#include <iostream>
#include "BinarySearchTree.h"

int main(int argc, char* argv[]) {
    TreeNode* root = new TreeNode("80");
    root->left = new TreeNode("70");
    root->right = new TreeNode("90");

    root->print();
    std::cout << std::endl;
    root->debug();
    std::cout << std::endl;

    BinaryTree* t = BinaryTree::createSampleTree();
    t->inOrder(t->root);
    std::cout << std::endl;
    t->preOrder(t->root);
    std::cout << std::endl;
    t->postOrder(t->root);
    std::cout << std::endl;
	t->levelOrder(t->root);
    std::cout << std::endl;
    t->indentedPreOrder(t->root, 0);
    
	BinarySearchTree* bst = static_cast<BinarySearchTree*>(BinarySearchTree::createSampleTree());
	bst->add("Lucy");

	if(bst->find("Lucy") != nullptr)
		std::cout << "Found lucy" << std::endl;
	else
		std::cout << "Lucy not found" << std::endl;

    return 0;
}
