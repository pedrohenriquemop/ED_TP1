#pragma once

#include <string>

#include "Stack.hpp"

using namespace std;

class BinaryTree;

class BinaryTreeNode {
   public:
    BinaryTreeNode();

    BinaryTreeNode(string v);

    BinaryTreeNode(string v, BinaryTreeNode* l, BinaryTreeNode* r);

    string getValue();

   private:
    string value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    friend class BinaryTree;
};

class BinaryTree {
   public:
    BinaryTree();

    ~BinaryTree();

    void setRoot(BinaryTreeNode* node);

    bool isEmpty();

    BinaryTreeNode* insert(string value, BinaryTreeNode* left = nullptr, BinaryTreeNode* right = nullptr);

    string preOrder();

    string inOrderWithParenthesis();

    string postOrder();

    Stack<string> getInOrderStack();

    Stack<string> getPostOrderStack();

    void clean();

   private:
    void recursiveDelete(BinaryTreeNode*& p);

    string preOrderTraversal(BinaryTreeNode*& p);

    string inOrderTraversalWithParenthesis(BinaryTreeNode*& p);

    string postOrderTraversal(BinaryTreeNode*& p);

    void inOrderStack(BinaryTreeNode*& p, Stack<string>& acc);

    void postOrderStack(BinaryTreeNode*& p, Stack<string>& acc);

    BinaryTreeNode* root;
};