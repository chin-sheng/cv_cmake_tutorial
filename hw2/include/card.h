#ifndef  _CARD_H_
#define _CARD_H_

#include <iostream>
#include <vector> 
#include <string>
#include <tuple>
using namespace std;

class Card
{
    public:
        Card(string s, string r);  // init
        bool is_same_color(Card* that) ;  // 比較兩張卡是否擁有同樣花色
        bool diff_one_index(Card* that) ;  // 比較兩張卡片，是否相差一個數字
        tuple<int, int> get_coordinate(){return(std::make_tuple(suit, rank));}; // get suit and rank
        friend ostream& operator<<(ostream& os, const Card& card); // print
    private:
        int suit; // 花色
        int rank; // 數字
        const vector<string> color_list = {"S", "H", "D", "C"}; // 牌組花色種類
        const vector<string> num_list = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"}; // 牌組數字
};
#endif