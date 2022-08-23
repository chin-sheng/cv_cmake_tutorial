#include <iostream>
#include <math.h>
#include "calculator.h"

using namespace std;

float Calculator::add(float a, float b) {
    return a + b;
}
float Calculator::sub(float a, float b) {
    return a - b;
}
float Calculator::mul(float a, float b) {
    return a * b;
}
float Calculator::div(float a, float b) {
    if (b == 0) {
        cout << "Divison By Zero" << endl;
        return INFINITY;
    }
    else {
        return a / b;
    }
}