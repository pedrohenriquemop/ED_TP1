#include <string.h>

#include <iostream>

#include "Expression.hpp"
#include "Utils.hpp"

using namespace string_utils;

std::ostream& operator<<(std::ostream& os, BinaryTreeNode*& obj) {
    os << "BinaryTreeNode object value: " << obj->getValue();
    return os;
}

Expression expression;

void processInput(string& input) {
    int lastIndex = 0;
    char separator = ' ';
    string instructionType = "";

    try {
        for (int i = 0;; i++) {
            if (input[i] == separator || input[i] == '\0') {
                if (i != lastIndex) {
                    string str = input.substr(lastIndex, i - lastIndex);
                    if (detectStringType(str) == "instr_ler") {
                        instructionType = "ler";
                    } else if (detectStringType(str) == "instr_infixa") {
                        cout << "INFIXA: " << expression.returnAsInfix() << endl;
                    } else if (detectStringType(str) == "instr_posfixa") {
                        cout << "POSFIXA: " << expression.returnAsPostfix() << endl;
                    } else if (detectStringType(str) == "instr_resolve") {
                        cout << "VAL: " << expression.solve() << endl;
                    }

                    if (detectStringType(str) == "parenthesis_open" && instructionType == "ler") {
                        try {
                            expression.storeInfixExpression(input.substr(lastIndex, input.length() - lastIndex));
                        } catch (const char* error) {
                            if (strcmp(error, "Invalid infix expression.") == 0) {
                                cout << "ERRO: EXP NAO VALIDA" << endl;
                            } else
                                cout << "ERRO: " << error << endl;
                        }
                        break;
                    } else if (detectStringType(str) == "number" && instructionType == "ler") {
                        try {
                            expression.storePostfixExpression(input.substr(lastIndex, input.length() - lastIndex));
                        } catch (const char* error) {
                            if (strcmp(error, "Invalid postfix expression.") == 0) {
                                cout << "ERRO: EXP NAO VALIDA" << endl;
                            } else
                                cout << "ERRO: " << error << endl;
                        }
                        break;
                    }
                }
                if (input[i] == '\0') break;
                lastIndex = i + 1;
            }
        }
    } catch (char const* error) {
        cout << error << endl;
    }
}

int main() {
    string input;

    while (1) {
        getline(cin, input);
        processInput(input);
    }
    return 0;
}