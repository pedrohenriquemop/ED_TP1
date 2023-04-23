#include "Expression.hpp"

void Expression::storeInfixExpression(string input) {
    // cout << "PROCEESSANDO INFIXA:" << input << endl;
    int lastIndex = 0;
    char separator = ' ';
    if (!tree.isEmpty()) tree.clean();

    Stack<BinaryTreeNode*> nodeStack;
    Stack<string> operatorStack;

    try {
        for (int i = 0;; i++) {
            if (input[i] == separator || input[i] == '\0') {
                if (i != lastIndex) {
                    string str = input.substr(lastIndex, i - lastIndex);
                    // cout << detectStringType(str) << ": " << str << endl;

                    if (detectStringType(str) == "number") {
                        nodeStack.push(new BinaryTreeNode(str));
                    } else if (detectStringType(str) == "parenthesis_open") {
                        operatorStack.push(str);
                    } else if (detectStringType(str) == "parenthesis_close") {
                        while (detectStringType(operatorStack.getTop()) != "parenthesis_open") {
                            BinaryTreeNode* rightNode = nodeStack.pop();
                            BinaryTreeNode* leftNode = nodeStack.pop();
                            nodeStack.push(new BinaryTreeNode(operatorStack.pop(), leftNode, rightNode));
                        }
                        operatorStack.pop();
                    } else if (detectStringType(str) == "operator") {
                        while (!operatorStack.isEmpty() && detectStringType(operatorStack.getTop()) == "operator") {
                            BinaryTreeNode* rightNode = nodeStack.pop();
                            BinaryTreeNode* leftNode = nodeStack.pop();
                            nodeStack.push(new BinaryTreeNode(operatorStack.pop(), leftNode, rightNode));
                        }
                        operatorStack.push(str);
                    }
                }
                if (input[i] == '\0') break;
                lastIndex = i + 1;
            }
        }
        while (!operatorStack.isEmpty()) {
            BinaryTreeNode* rightNode = nodeStack.pop();
            BinaryTreeNode* leftNode = nodeStack.pop();
            nodeStack.push(new BinaryTreeNode(operatorStack.pop(), leftNode, rightNode));
        }
    } catch (...) {
        throw "Invalid infix expression.";
    }

    tree.setRoot(nodeStack.pop());

    // cout << "INORDER TREE: " << tree.inOrderWithParenthesis() << endl;
    // cout << "POSTORDER TREE: " << tree.postOrder() << endl;
    // cout << "TESTING NEW FUNCTION: " << endl;
    // tree.getInOrderStack().print();
}

void Expression::storePostfixExpression(string input) {
    // cout << "PROCEESSANDO POSFIXA:" << input << endl;
    int lastIndex = 0;
    char separator = ' ';
    if (!tree.isEmpty()) tree.clean();

    Stack<BinaryTreeNode*> stack;

    for (int i = 0;; i++) {
        if (input[i] == separator || input[i] == '\0') {
            if (i != lastIndex) {
                string str = input.substr(lastIndex, i - lastIndex);

                if (detectStringType(str) == "number") {
                    stack.push(new BinaryTreeNode(str));
                } else if (detectStringType(str) == "operator") {
                    try {
                        BinaryTreeNode* rightNode = stack.pop();
                        BinaryTreeNode* leftNode = stack.pop();
                        BinaryTreeNode* inserted = tree.insert(str, leftNode, rightNode);
                        tree.setRoot(inserted);
                        stack.push(inserted);
                    } catch (...) {
                        throw "Invalid postfix expression.";
                    }
                }
            }
            if (input[i] == '\0') break;
            lastIndex = i + 1;
        }
    }
    if (!(stack.getSize() == 1)) throw "Invalid postfix expression.";
    // cout << "INORDER TREE: " << tree.inOrderWithParenthesis() << endl;
    // cout << "POSTORDER TREE: " << tree.postOrder() << endl;
    // cout << "TESTING NEW FUNCTION: " << endl;
}

double Expression::solve() {
    if (isEmpty())
        throw "No stored expression.";
    Stack<string> postOrderStack = tree.getPostOrderStack();
    Stack<double> auxStack;

    while (!postOrderStack.isEmpty()) {
        string str = postOrderStack.pop();
        if (detectStringType(str) == "number") {
            double aux;
            stringstream ss;
            ss << str;
            ss >> setprecision(10) >> aux;
            auxStack.push(aux);
        } else if (detectStringType(str) == "operator") {
            double secondOperand = auxStack.pop();
            double firstOperand = auxStack.pop();
            switch (str[0]) {
                case '+':
                    auxStack.push(firstOperand + secondOperand);
                    break;
                case '-':
                    auxStack.push(firstOperand - secondOperand);
                    break;
                case '*':
                    auxStack.push(firstOperand * secondOperand);
                    break;
                case '/':
                    auxStack.push(firstOperand / secondOperand);
                    break;
            }
            // cout << "auxStack state: " << endl;
            // auxStack.print();
        }
    }

    return auxStack.pop();
}

string Expression::returnAsInfix() {
    if (isEmpty())
        throw "No stored expression.";
    return tree.inOrderWithParenthesis();
}

string Expression::returnAsPostfix() {
    if (isEmpty())
        throw "No stored expression.";
    return tree.postOrder();
}

bool Expression::isEmpty() {
    return tree.isEmpty();
}