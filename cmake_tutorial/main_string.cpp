#include <iostream>
#include "string_calculator.h"

using namespace std;

int main() {
    StringCalculator cal; // simple calculator object
    cout << "String Add Result: " << cal.add("4.0", "2.0") << endl;
    cout << "String Sub Result: " << cal.sub("4.0", "2.0") << endl;
    cout << "String Mul Result: " << cal.mul("4.0", "2.0") << endl;
    cout << "String Div Result: " << cal.div("4.0", "2.0") << endl;
    return 0;
}