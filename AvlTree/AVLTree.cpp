#include "AVLTree.h"

template <typename T>
int AVLTree<T>::height(AbstractTreeNode<T>* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

template <typename T>
int AVLTree<T>::getBalance(AbstractTreeNode<T>* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

template <typename T>
AbstractTreeNode<T>* AVLTree<T>::rightRotate(AbstractTreeNode<T>* y) {
    AbstractTreeNode<T>* x = y->left;
    AbstractTreeNode<T>* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

template <typename T>
AbstractTreeNode<T>* AVLTree<T>::leftRotate(AbstractTreeNode<T>* x) {
    AbstractTreeNode<T>* y = x->right;
    AbstractTreeNode<T>* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

template <typename T>
AbstractTreeNode<T>* AVLTree<T>::insert(AbstractTreeNode<T>* node, T key) {
    if (node == nullptr)
        return new TreeNode<T>(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);
    else
        return node;

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->data)
        return rightRotate(node);

    if (balance < -1 && key > node->right->data)
        return leftRotate(node);

    if (balance > 1 && key > node->left->data) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->data) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

template <typename T>
void AVLTree<T>::insert(T key) {
    root = insert(root, key);
}

template <typename T>
void AVLTree<T>::inOrderTraversal(AbstractTreeNode<T>* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        node->display();
        std::cout << " ";
        inOrderTraversal(node->right);
    }
}

template <typename T>
void AVLTree<T>::inOrderTraversal() {
    inOrderTraversal(root);
}

template <typename T>
void AVLTree<T>::printTree() {
    printTree(root, "", true);
}

template <typename T>
void AVLTree<T>::printTree(AbstractTreeNode<T>* node, std::string indent, bool last) {
    if (node != nullptr) {
        std::cout << indent;
        if (last) {
            std::cout << "R----";
            indent += "     ";
        }
        else {
            std::cout << "L----";
            indent += "|    ";
        }
        node->display();
        std::cout << std::endl;
        printTree(node->left, indent, false);
        printTree(node->right, indent, true);
    }
}

template class AVLTree<int>;  // Explicit template instantiation for int
