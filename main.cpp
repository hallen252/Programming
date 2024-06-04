#include <iostream>
#include <vector>
#include "AVLTree.h"

int main() {
    AVLTree<int> tree;
    std::vector<int> sequence;
    int number;

    std::cout << "Enter numbers to insert into the AVL tree (type 'end' to stop):" << std::endl;

    while (std::cin >> number) {
        sequence.push_back(number);
    }

    for (int num : sequence) {
        tree.insert(num);
    }

    std::cout << "In-order traversal of the AVL tree:" << std::endl;
    tree.inOrderTraversal();
    std::cout << std::endl;

    std::cout << "Tree structure:" << std::endl;
    tree.printTree();

    return 0;
}
