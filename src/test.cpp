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
    std::cout << "inOrder: ";
    t->inOrder(t->root);
    std::cout << std::endl;
    TreeNode* node = t->find("Les");
    TreeNode* succ = t->successor(node);
    if(succ) {
        std::cout << "Les' successor: ";
        succ->print();
    } else
        std::cout << "No Les successor";
    std::cout << std::endl;
    node = t->find("Frank");
    succ = t->successor(node);
    if(succ) {
        std::cout << "Frank's successor: ";
        succ->print();
    } else
        std::cout << "No Frank successor";
    std::cout << std::endl;
    node = t->find("Terry");
    succ = t->successor(node);
    if(succ) {
        std::cout << "Terry's successor: ";
        succ->print();
    } else
        std::cout << "No Terry successor";
    std::cout << std::endl;
    std::cout << "preOrder: ";
    t->preOrder(t->root);
    std::cout << std::endl;
    node = t->find("Les");
    TreeNode* pre = t->predecessor(node);
    if(pre) {
        std::cout << "Les' predecessor: ";
        pre->print();
    } else
        std::cout << "No Les predecessor";
    std::cout << std::endl;
    node = t->find("Frank");
    pre = t->predecessor(node);
    if(pre) {
        std::cout << "Frank's predecessor: ";
        pre->print();
    } else
        std::cout << "No Frank predecessor";
    std::cout << std::endl;
    node = t->find("Terry");
    pre = t->predecessor(node);
    if(pre) {
        std::cout << "Terry's predecessor: ";
        pre->print();
    } else
        std::cout << "No Terry predecessor";
    std::cout << std::endl;
    std::cout << "postOrder: ";
    t->postOrder(t->root);
    std::cout << std::endl;
	t->levelOrder(t->root);
    std::cout << std::endl;
    t->indentedPreOrder(t->root, 0);

    std::cout << "LCM of Nancy and Tony: ";
    std::string lcm;
    if(!t->findLCA(std::string("Nancy"), std::string("Tony"), lcm))
        std::cout << "Not found!" << std::endl;
    else
        std::cout << lcm << std::endl;

    std::list<std::string> treeList;
    t->serialize(treeList, t->root, NONE);
    std::cout << "Serialized list: ";
    for(auto& x : treeList)
        std::cout << x << " ";
    std::cout << std::endl;

    BinaryTree* ts = new BinaryTree();
    std::list<std::string>::iterator iter = treeList.begin();
    ts->deserialize(treeList, &(ts->root), iter);
    std::cout << "Deserialized tree: " << std::endl;
    std::cout << "inOrder: ";
    ts->inOrder(ts->root);
    std::cout << std::endl;
    std::cout << "preOrder: ";
    ts->preOrder(ts->root);
    std::cout << std::endl;
    std::cout << "postOrder: ";
    ts->postOrder(ts->root);
    std::cout << std::endl;

	BinarySearchTree* bst = static_cast<BinarySearchTree*>(BinarySearchTree::createSampleTree());
	bst->add("Lucy");

	if(bst->find("Lucy") != nullptr)
		std::cout << "Found lucy" << std::endl;
	else
		std::cout << "Lucy not found" << std::endl;

    return 0;
}
