#include <string.h>

#include <iostream>

#include "Expression.hpp"
#include "Utils.hpp"

using namespace string_utils;

std::ostream& operator<<(std::ostream& os, BinaryTreeNode*& obj) {  // override do operador cout para caso algum nó da árvore fosse ser impresso
    os << "BinaryTreeNode object value: " << obj->getValue();
    return os;
}

Expression expression;

void processInput(string& input) {  // processa a string lida com o getLine, chamando as funções de Expression correspondentes aos comandos passados
    int lastIndex = 0;
    char separator = ' ';
    string instructionType = "";

    try {
        for (int i = 0;; i++) {
            if (input[i] == separator || input[i] == '\0') {
                if (i != lastIndex) {
                    string str = input.substr(lastIndex, i - lastIndex);
                    if (instructionType == "ler") {
                        if (detectStringType(str) == "instr_infixa") {
                            try {
                                expression.storeInfixExpression(input.substr(lastIndex, input.length() - lastIndex));
                                cout << "EXPRESSAO OK: " << expression.returnAsInfix() << endl;
                            } catch (exception& e) {
                                if (strcmp(e.what(), "Invalid infix expression.") == 0) {
                                    cout << "ERRO: EXP NAO VALIDA" << endl;
                                } else
                                    cout << "ERRO: " << e.what() << endl;
                            }
                        } else if (detectStringType(str) == "instr_posfixa") {
                            try {
                                expression.storePostfixExpression(input.substr(lastIndex, input.length() - lastIndex));
                                cout << "EXPRESSAO OK: " << expression.returnAsPostfix() << endl;
                            } catch (exception& e) {
                                if (strcmp(e.what(), "Invalid postfix expression.") == 0) {
                                    cout << "ERRO: EXP NAO VALIDA" << endl;
                                } else
                                    cout << "ERRO: " << e.what() << endl;
                            }
                            break;
                        }
                    } else if (detectStringType(str) == "instr_ler") {
                        instructionType = "ler";
                    } else if (detectStringType(str) == "instr_infixa") {
                        try {
                            string exp = expression.returnAsInfix();
                            cout << "INFIXA: " << exp << endl;
                        } catch (runtime_error& e) {
                            if (strcmp(e.what(), "No stored expression.") == 0) {
                                cout << "ERRO: EXP NAO EXISTE" << endl;
                            } else {
                                cout << "ERRO: " << e.what() << endl;
                            }
                        }
                    } else if (detectStringType(str) == "instr_posfixa") {
                        try {
                            string exp = expression.returnAsPostfix();
                            cout << "POSFIXA: " << exp << endl;
                        } catch (runtime_error& e) {
                            if (strcmp(e.what(), "No stored expression.") == 0) {
                                cout << "ERRO: EXP NAO EXISTE" << endl;
                            } else {
                                cout << "ERRO: " << e.what() << endl;
                            }
                        }
                    } else if (detectStringType(str) == "instr_resolve") {
                        try {
                            double result = expression.solve();
                            cout << "VAL: " << result << endl;
                        } catch (runtime_error& e) {
                            if (strcmp(e.what(), "No stored expression.") == 0) {
                                cout << "ERRO: EXP NAO EXISTE" << endl;
                            } else
                                cout << "ERRO: " << e.what() << endl;
                        }
                    }
                }
                if (input[i] == '\0') break;
                lastIndex = i + 1;
            }
        }
    } catch (exception& e) {
        cout << "ERRO: " << e.what() << endl;
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