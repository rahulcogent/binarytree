#ifndef TREE_NODE_H_
#define TREE_NODE_H_

#include <iostream>
#include <string>

class TreeNode {
public:
    TreeNode(std::string d) : data(d), left(nullptr), right(nullptr) { }
    void print() { std::cout << data << " "; }
    void debug() { std::cout << " " << left->data << "-" << data << "-" << right->data; }

    std::string data;
    TreeNode* left;
    TreeNode* right;
};

#endif
