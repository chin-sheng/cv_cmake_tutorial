#include <iostream>
#include <memory>
#include "calculator.h"

using namespace std;

int main() {
    unique_ptr<Calculator> cal(new Calculator()); // simple calculator object
    cout << "Add Result: " << cal->add(4.0, 2.0) << endl;
    cout << "Sub Result: " << cal->sub(4.0, 2.0) << endl;
    cout << "Mul Result: " << cal->mul(4.0, 2.0) << endl;
    cout << "Div Result: " << cal->div(4.0, 2.0) << endl;
    return 0;
}