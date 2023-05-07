#pragma once

#include <iomanip>
#include <sstream>

#include "BinaryTree.hpp"
#include "Stack.hpp"
#include "Utils.hpp"

using namespace std;
using namespace string_utils;

class Expression {
   public:
    void storeInfixExpression(string input);  // armazena expressão infixa recebida como árvore binária

    void storePostfixExpression(string input);  // armazena expressão posfixa recebida como árvore binária

    double solve();  // resolve a expressão armazenada na árvore

    string returnAsInfix();  // retorna a expressão armazenada na árvore na notação infixa

    string returnAsPostfix();  // retorna a expressão armazenada na árvore na notação posfixa

    bool isEmpty();  // verifica se a árvore que armazena a expressão está vazia

   private:
    BinaryTree tree;  // árvore que contém a expressão
};