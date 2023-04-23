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
    void storeInfixExpression(string input);

    void storePostfixExpression(string input);

    double solve();

    string returnAsInfix();

    string returnAsPostfix();

    bool isEmpty();

   private:
    BinaryTree tree;
};