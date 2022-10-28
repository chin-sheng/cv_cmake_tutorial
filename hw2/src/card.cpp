#include "card.h"
#include <vector>
#include <algorithm>
using namespace std;

Card::Card(string s, string r)
{
    auto it_suit = find(color_list.begin(), color_list.end(), s);
    suit = it_suit - color_list.begin();
    auto it_rank = find(num_list.begin(), num_list.end(), r);
    rank = it_rank - num_list.begin();
    cout << rank << endl;

}


bool Card::is_same_color( Card* that) 
{
    if(rank ==that->rank){
        return true;
    }
    else{
        return false;
    }
}


ostream& operator<<(ostream& os, const Card& card)
{
    os << card.suit << ' ' << card.rank;
    return os;
}

bool Card::diff_one_index( Card* that) 
{
    /*
    回傳兩張牌是否符合拿掉的規則
    規則：某張牌的點數加一，且兩張牌花色相同，那麼這兩張牌就必須被拿掉，須注意點數 10、J、Q、K、A 的點數加一依序為點數J、Q、K、A、2 。
    */
    if(rank -that->rank<2){
        return true;
    }
    else{
        return false;
    }



}