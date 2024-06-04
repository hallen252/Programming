#ifndef AVLTREE_H
#define AVLTREE_H

#include "TreeNode.h"
#include <iostream>

template <typename T>
class AVLTree {
private:
    AbstractTreeNode<T>* root;

    int height(AbstractTreeNode<T>* node);
    int getBalance(AbstractTreeNode<T>* node);
    AbstractTreeNode<T>* rightRotate(AbstractTreeNode<T>* y);
    AbstractTreeNode<T>* leftRotate(AbstractTreeNode<T>* x);
    AbstractTreeNode<T>* insert(AbstractTreeNode<T>* node, T key);
    void inOrderTraversal(AbstractTreeNode<T>* node);
    void printTree(AbstractTreeNode<T>* node, std::string indent, bool last);

public:
    AVLTree() : root(nullptr) {}
    void insert(T key);
    void inOrderTraversal();
    void printTree();
};

#endif // AVLTREE_H
