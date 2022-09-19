#ifndef  _DECK_H_
#define _DECK_H_

#include <iostream>
#include <vector> 
#include <numeric>
#include "card.h"
using namespace std;

class Deck
{
    public:
        Deck():matrix(4, std::vector<bool>(13, false)), cards(0){} // constructor
        ~Deck(); // destructor
        void add_card(Card* card); // 新增牌組
        int cal_max_score(); // 計算牌組分數
        int count_num_without_color(int x); // 不考慮牌組花色，特定數字的出現數量
        friend ostream& operator<<(ostream& os, const Deck& deck); // print
    private:
        vector<Card*> cards;  // 牌的一維 list
        std::vector<std::vector<bool> > matrix;  // 牌的二維矩陣(4*13)
        vector<int> num_without_color_list;  // 不考慮牌組花色的數字數量陣列

        void build_cards(); // 建立牌組矩陣 cards -> matrix
        void get_num_without_color(); // matrix -> num_without_color_list
        // 分數規則
        int check_a();
        int check_b();
        bool check_c();
        bool check_d();
        bool check_e();
        bool check_f();
        bool check_g();
};



#endif

