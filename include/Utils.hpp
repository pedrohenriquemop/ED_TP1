#pragma once

#include <string>

using namespace std;

namespace string_utils {
string isInstruction(string &str);

bool isDouble(string &str);

bool isOperator(char c);

bool isParenthesis(char c);

string detectStringType(string str);
}  // namespace string_utils