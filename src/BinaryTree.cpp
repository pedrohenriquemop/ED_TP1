#include "BinaryTree.hpp"

BinaryTreeNode::BinaryTreeNode() {
    value = "";
    left = nullptr;
    right = nullptr;
};

BinaryTreeNode::BinaryTreeNode(string v) : value(v) {
    left = nullptr;
    right = nullptr;
};

BinaryTreeNode::BinaryTreeNode(string v, BinaryTreeNode* l, BinaryTreeNode* r) : value(v), left(l), right(r){};

string BinaryTreeNode::getValue() {
    return value;
};

BinaryTree::BinaryTree() {
    root = nullptr;
};

BinaryTree::~BinaryTree() {
    clean();
};

void BinaryTree::setRoot(BinaryTreeNode* node) {
    root = node;
}

bool BinaryTree::isEmpty() {
    return root == nullptr;
}

BinaryTreeNode* BinaryTree::insert(string value, BinaryTreeNode* left, BinaryTreeNode* right) {
    BinaryTreeNode* inserted = new BinaryTreeNode(value);
    inserted->left = left;
    inserted->right = right;
    return inserted;
};

string BinaryTree::preOrder() {
    if (isEmpty())
        throw runtime_error("Tree with no root.");
    return preOrderTraversal(root);
};

string BinaryTree::inOrderWithParenthesis() {
    if (isEmpty())
        throw runtime_error("Tree with no root.");
    return inOrderTraversalWithParenthesis(root);
};

string BinaryTree::postOrder() {
    if (isEmpty())
        throw runtime_error("Tree with no root.");
    return postOrderTraversal(root);
};

Stack<string> BinaryTree::getInOrderStack() {
    Stack<string> stack;
    inOrderStack(root, stack);
    return stack;
}

Stack<string> BinaryTree::getPostOrderStack() {
    Stack<string> stack;
    postOrderStack(root, stack);
    return stack;
}

void BinaryTree::clean() {
    if (isEmpty())
        throw runtime_error("Tree with no root.");
    recursiveDelete(root);
    root = nullptr;
};

void BinaryTree::recursiveDelete(BinaryTreeNode*& p) {
    if (p != nullptr) {
        recursiveDelete(p->left);
        recursiveDelete(p->right);
        delete p;
    }
};

string BinaryTree::preOrderTraversal(BinaryTreeNode*& p) {
    if (p != nullptr) {
        return p->value + " " + preOrderTraversal(p->left) + preOrderTraversal(p->right);
    }
    return "";
}
string BinaryTree::inOrderTraversalWithParenthesis(BinaryTreeNode*& p) {
    if (p != nullptr) {
        return "( " + inOrderTraversalWithParenthesis(p->left) + p->value + " " + inOrderTraversalWithParenthesis(p->right) + ") ";
    }
    return "";
}
string BinaryTree::postOrderTraversal(BinaryTreeNode*& p) {
    if (p != nullptr) {
        return postOrderTraversal(p->left) + postOrderTraversal(p->right) + p->value + " ";
    }
    return "";
}

void BinaryTree::inOrderStack(BinaryTreeNode*& p, Stack<string>& acc) {
    if (p != nullptr) {
        inOrderStack(p->right, acc);
        acc.push(p->value);
        inOrderStack(p->left, acc);
    }
}

void BinaryTree::postOrderStack(BinaryTreeNode*& p, Stack<string>& acc) {
    if (p != nullptr) {
        acc.push(p->value);
        postOrderStack(p->right, acc);
        postOrderStack(p->left, acc);
    }
}