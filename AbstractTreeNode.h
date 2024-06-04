#ifndef ABSTRACTTREENODE_H
#define ABSTRACTTREENODE_H

template <typename T>
class AbstractTreeNode {
public:
    T data;
    AbstractTreeNode* left;
    AbstractTreeNode* right;
    int height;

    AbstractTreeNode(T value) : data(value), left(nullptr), right(nullptr), height(1) {}
    virtual ~AbstractTreeNode() = default;

    virtual void display() = 0;
};

#endif // ABSTRACTTREENODE_H
