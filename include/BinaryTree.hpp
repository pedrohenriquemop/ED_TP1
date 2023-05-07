#pragma once

#include <string>

#include "Stack.hpp"

using namespace std;

class BinaryTree;

class BinaryTreeNode {
   public:
    BinaryTreeNode();  // construtor sem parâmetros para o nó

    BinaryTreeNode(string v);  // construtor apenas com o parametro do valor do nó

    BinaryTreeNode(string v, BinaryTreeNode* l, BinaryTreeNode* r);  // construtor com o parametro do valor do nó, o ponteiro do nó da esquerda e do nó da direita

    string getValue();  // retorna o valor do nó

   private:
    string value;           // valor do nó, armazenado como string
    BinaryTreeNode* left;   // ponteiro do nó da esquerda para a árvore
    BinaryTreeNode* right;  // ponteiro do nó da direita para a árvore

    friend class BinaryTree;  // permite que a classe BinaryTree acesse os atributos private. na prática evita que métodos getters sejam necessários para left e right
};

class BinaryTree {
   public:
    BinaryTree();  // construtor sem parâmetros para a árvore binária

    ~BinaryTree();  // destrutor para limpar as alocações dinâmicas

    void setRoot(BinaryTreeNode* node);  // determina qual nó será a raiz da árvore

    bool isEmpty();  // retorna se a árvore está vazia (raiz é nula)

    BinaryTreeNode* insert(string value, BinaryTreeNode* left = nullptr, BinaryTreeNode* right = nullptr);  // insere nó na árvore, podendo já passar os nós da esquerda e da direita em relação ao inserido

    string preOrder();  // retorna uma string representando os valores da árvore percorridos com encaminhamento preOrder

    string inOrderWithParenthesis();  // retorna uma string representando os valores da árvore percorridos com encaminhamento inOrder com parênteses (para notação infixa)

    string postOrder();  // retorna uma string representando os valores da árvore percorridos com encaminhamento postOrder

    Stack<string> getInOrderStack();  // retorna uma pilha com os valores da árvore ordenados pelo encaminhamento inOrder (chama inOrderStack)

    Stack<string> getPostOrderStack();  // retorna uma pilha com os valores da árvore ordenados pelo encaminhamento postOrder (chama postOrderStack)

    void clean();  // limpa a árvore (chama recursiveDelete e seta root para nullptr)

   private:
    void recursiveDelete(BinaryTreeNode*& p);  // percorre a árvore aplicando delete nos ponteiros

    string preOrderTraversal(BinaryTreeNode*& p);  // percorre a árvore em preOrder e retorna uma string

    string inOrderTraversalWithParenthesis(BinaryTreeNode*& p);  // percorre a árvore em inOrder e retorna uma string já com parênteses

    string postOrderTraversal(BinaryTreeNode*& p);  // percorre a árvore em postOrder e retorna uma string

    void inOrderStack(BinaryTreeNode*& p, Stack<string>& acc);  // retorna uma pilha com os valores da árvore ordenados pelo encaminhamento inOrder

    void postOrderStack(BinaryTreeNode*& p, Stack<string>& acc);  // retorna uma pilha com os valores da árvore ordenados pelo encaminhamento postOrder

    BinaryTreeNode* root;  // raiz da árvore
};