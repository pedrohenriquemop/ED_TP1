#pragma once

#include <string>

using namespace std;

namespace string_utils {            // namespae para funções utilitárias de string para o programa
string isInstruction(string &str);  // verifica se str é uma das instruções do programa e qual delas é (LER, INFIXA, POSFIXA, RESOLVE)

bool isDouble(string &str);  // verifica se str é um double

bool isOperator(char c);  // verifica se str é um operador (+, -, *, /)

bool isParenthesis(char c);  // verifica se str é um parênteses ("(" ou ")")

string detectStringType(string str);  // verifica se str é um double ou um operador ou um parêntese, nesse último caso retornando se é parêntese de abertura ou fechamento
}  // namespace string_utils