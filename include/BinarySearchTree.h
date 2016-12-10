#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include "BinaryTree.h"
#include <string>

class BinarySearchTree : public BinaryTree {
public:
	void add(std::string data);
	TreeNode* find(std::string data);
};

#endif
