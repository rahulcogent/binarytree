#include "BinarySearchTree.h"

void BinarySearchTree::add(std::string data) {
	if(root == nullptr) {
		root = new TreeNode(data);
		return;
	}

	TreeNode* node = root;

	while(true) {
		if(data < node->data) {
			if(node->left == nullptr) {
				node->left = new TreeNode(data);
				return;
			}
			node = node->left;
		} else {
			if(node->right == nullptr) {
				node->right = new TreeNode(data);
				return;
			}
			node = node->right;
		}
	}
}

TreeNode* BinarySearchTree::find(std::string data) {
	TreeNode* node = root;
	while(node) {
		if(data < node->data)
			node = node->left;
		else if(data > node->data)
			node = node->right;
		else
			return node;
	}

	return node;
}
