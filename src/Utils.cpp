#include "Utils.hpp"

string string_utils::isInstruction(string &str) {
    if (str == "LER") return "instr_ler";
    if (str == "INFIXA") return "instr_infixa";
    if (str == "POSFIXA") return "instr_posfixa";
    if (str == "RESOLVE") return "instr_resolve";
    return "no";
}

bool string_utils::isDouble(string &str) {
    try {
        stod(str);
        return true;
    } catch (...) {
        return false;
    }
}

bool string_utils::isOperator(char c) {
    switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

bool string_utils::isParenthesis(char c) {
    switch (c) {
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}

string string_utils::detectStringType(string str) {
    if (isInstruction(str) != "no")
        return isInstruction(str);
    else if (isDouble(str))
        return "number";
    else if (str.length() == 1 && isOperator(str[0]))
        return "operator";
    else if (str.length() == 1 && isParenthesis(str[0])) {
        if (str[0] == '(') return "parenthesis_open";
        return "parenthesis_close";
    }
    return "null";
}