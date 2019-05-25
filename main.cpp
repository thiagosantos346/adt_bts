#include <iostream>
#include <bits/stdc++.h>
#include "Red_Black_tree.h"


int main() {
    Red_Black_tree tree;

    tree.insertValue(7);
    tree.insertValue(6);
    tree.insertValue(5);
    tree.insertValue(4);
    tree.insertValue(3);
    tree.insertValue(2);
    tree.insertValue(1);
    tree.inorder();
    tree.levelOrder();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
//https://github.com/anandarao/Red-Black-Tree/blob/master/RBTree.cpp
//https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/