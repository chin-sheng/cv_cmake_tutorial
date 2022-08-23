#ifndef _STR_CALCULATOR_H_
#define _STR_CALCULATOR_H_
#include <string>

class StringCalculator
{
  public:
    // Function to add two numbers
    std::string add(std::string a, std::string b);
    // Function to subtract two numbers
    std::string sub(std::string a, std::string b);
    // Function to multiply two numbers
    std::string mul(std::string a, std::string b);
    // Function to divide two numbers
    std::string div(std::string a, std::string b);
};

#endif // _STR_CALCULATOR_H_