#include <iostream>
#include <boost/lexical_cast.hpp>
#include <math.h>
#include <string>
#include "string_calculator.h"

using namespace std;

string StringCalculator::add(string a, string b) {
    float a_cast = boost::lexical_cast<float>(a);
    float b_cast = boost::lexical_cast<float>(b);
    string c = boost::lexical_cast<string>(a_cast + b_cast);
    return c;
}
string StringCalculator::sub(string a, string b) {
    float a_cast = boost::lexical_cast<float>(a);
    float b_cast = boost::lexical_cast<float>(b);
    string c = boost::lexical_cast<string>(a_cast - b_cast);
    return c;
}
string StringCalculator::mul(string a, string b) {
    float a_cast = boost::lexical_cast<float>(a);
    float b_cast = boost::lexical_cast<float>(b);
    string c = boost::lexical_cast<string>(a_cast * b_cast);
    return c;
}
string StringCalculator::div(string a, string b) {
    float a_cast = boost::lexical_cast<float>(a);
    float b_cast = boost::lexical_cast<float>(b);
    if (b_cast == 0) {
        cout << "Divison By Zero" << endl;
        string c = boost::lexical_cast<string>(INFINITY);
        return c;
    }
    else {
        string c = boost::lexical_cast<string>(a_cast / b_cast);
        return c;
    }
}