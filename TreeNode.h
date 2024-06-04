#ifndef TREENODE_H
#define TREENODE_H

#include "AbstractTreeNode.h"
#include <iostream>

template <typename T>
class TreeNode : public AbstractTreeNode<T> {
public:
    TreeNode(T value) : AbstractTreeNode<T>(value) {}
    void display() override {
        std::cout << this->data;
    }
};

#endif // TREENODE_H
