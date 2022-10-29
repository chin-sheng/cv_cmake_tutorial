#include <iostream>
#include <vector> 
#include <numeric>
#include "card.h"
#include "deck.h"
using namespace std;

using iter = vector<Card*>::iterator; 

// general
template<class T>
bool check_continous(vector<T>& card_list)
{
    /*
    回傳是否有順連的，比如說黑桃Q、梅花K、方塊A、梅花2、黑桃3 這種組合也算順連。換言之，不考慮花色的話，共有 13 種順連的方式。
    */
    bool have_one_con = false;
    for(auto k=-5;k<9;k++){
        bool is_con = true;
        for(auto n=k; n<k+5; n++){
            auto new_n=n;
            if(n < 0){new_n=13+n;}
            if(card_list.at(new_n)==0){
                is_con = false;
                break;
            }
        }
        if(is_con){
            have_one_con = true;
            break;
        }
    }
    return have_one_con;
}

// public

Deck::~Deck()
{

}

void Deck::add_card(Card* card)
{
    /*
    建議：is_same_color、diff_one_index
    */
    cout << "start add cards" << endl;
    
    if (cards.empty()){
        cards.push_back(card);
    }
    else{
        if((cards.back()->is_same_color(card))&&(cards.back()->diff_one_index(card))){
            cards.erase(cards.end() - 1);
        }
        else{
            cards.push_back(card);
        }
    }
    cout << "end add cards" << endl;
    cout << cards.size() << endl;
}

int Deck::count_num_without_color(int x)
{
    //auto count_num = count(num_without_color_list.begin(), num_without_color_list.end(), x);
    cout << "Count = " << num_without_color_list.at(x) << endl;
    return num_without_color_list.at(x);
}

ostream& operator<<(ostream& os, const Deck& deck)
{
    for(Card* card:deck.cards){
        os << *card << endl;
    }
    return os;
}

int Deck::cal_max_score(){
    // init
    build_cards();
    get_num_without_color();
    int score = 0;
    if(check_g()){
        score = 100;
    } // 5 張牌
    else if(check_f()){
        score = 20 + check_a(); // 4 張牌
    }else if(check_e()){
        score = 10; // 5 張牌
    }else if(check_d()){
        score = 5; // 5 張牌
    }else if(check_b() == 2){
        score = 4;
        if((check_a() == 1)||(check_a() == 3)){
            score++;
        }
    }else if(check_c()){
        score = 3;
    }else{
        // 至多一組對子
        score = check_a();
        if(score<2){score += check_b()*2;} // 對子是否為 A，不是則加上
    }
    return score;
}


// private
void Deck::build_cards()
{
    iter iter = cards.begin();    
    for(iter; iter < cards.end(); iter++)
    {
        int suit_tmp = get<0>((*iter)->get_coordinate());
        int rank_tmp = get<1>((*iter)->get_coordinate());
        cout << get<0>((*iter)->get_coordinate()) <<"," << get<1>((*iter)->get_coordinate()) << endl;
        matrix[suit_tmp][rank_tmp] = true;
    }
    get_num_without_color();
    for (int j = 0; j != num_without_color_list.size(); ++j) {
        cout << "num_without_color_list" << num_without_color_list[j] << endl;
    }
}

void Deck::get_num_without_color()
{
    for(auto i=0; i<13;i++){
        int no = 0;
        for(auto j=0; j<4; j++){
            if(matrix.at(j).at(i)){++no;};
        }
        num_without_color_list.push_back(no);
    }
}


int Deck::check_a()
{
    return count_num_without_color(0);
}
int Deck::check_b()
{
    /*
     回傳對子（兩張同樣數字）的數量
     e.g. 
     如果有四張2，回傳2
     如果三張2，回傳 1
     如果兩張2，回傳1
     如果數字分別為 33322，則回傳 2
     建議：可以使用 count_num_without_color
    */
    int pair_count = 0;
    for (int i = 0; i < 13; i = i + 1) {
        int num_count = count_num_without_color(i);
        if (3> num_count > 1) {
            pair_count = pair_count + 1;
        }
        if(num_count > 3) {
            pair_count = pair_count + 2;
        }
    }
    return pair_count;
}
bool Deck::check_c()
{
    /*
    回傳牌組是否有同花，也就是五張同一花色的牌
    */
    for (int i = 0; i < 4; i = i + 1)
    {
        auto count_num = count(matrix[i].begin(), matrix[i].end(), true);
        if (count_num >= 5) {
            return true;
        }
    }
    return false;
}

bool Deck::check_d()
{
    /*
    回傳牌組是否有順子，也就是五張順連的牌。順連與否不考慮花色，也不因點數而中斷，比如說黑桃Q、梅花K、方塊A、梅花2、黑桃3 這種組合也算順連。換言之，不考慮花色的話，共有 13 種順連的方式。
    建議：可以使用 check_continous
    */
    vector<int> num_without_color;
    for (int j = 0; j != num_without_color_list.size(); ++j) {
        if (num_without_color_list[j]>0) num_without_color.push_back(j);
    }
    for (int j = 0; j != num_without_color.size(); ++j) {
        cout << "num_no" << num_without_color[j] << endl;
    }

    return check_continous(num_without_color);

}
bool Deck::check_e()
{
    /*
    回傳牌組是否有葫蘆，也就是三張同一點數的牌，加一對其他點數的牌。
    建議：可以使用 count_num_without_color
    */
    for (int i = 0; i < 13; i = i + 1) {
        int num_count=count_num_without_color(i);
        if (num_count > 2) {
            return true;
        }
    }
    return false;

}
bool Deck::check_f()
{
    /*
    回傳牌組是否有四條，也就是四張同一點數的牌，加一張其他點數的牌。
    建議：可以使用 count_num_without_color
    */
    for (int i = 0; i < 13; i = i + 1) {
        int num_count = count_num_without_color(i);
        if (num_count > 3) {
            return true;
        }
    }
    return false;

}
bool Deck::check_g()
{
    /*
    回傳牌組是否有同花順，也就是五張同一花色且順連的牌。
    建議：可以使用 check_continous
    */
    for (int i = 0; i < 4; i = i + 1) {
        vector<int> num_same_color;
        for (int j = 0; j != matrix[i].size(); ++j) {
            if (matrix[i][j]) num_same_color.push_back(j);
        }
        for (int j = 0; j != num_same_color.size(); ++j) {
            cout << "num_same" << num_same_color[j] << endl;
        }
        if (num_same_color.size() == 0) {
            continue;
        }

        //if (check_continous(num_same_color)) {
        //    return true;
        //}
    }
    return false;
}
