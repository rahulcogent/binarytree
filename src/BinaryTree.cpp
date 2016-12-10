#include "BinaryTree.h"
#include <queue>

void BinaryTree::inOrder(TreeNode* subTree) {
    if(subTree == nullptr)
        return;

    inOrder(subTree->left);
    subTree->print();
    inOrder(subTree->right);
}

void BinaryTree::preOrder(TreeNode* subTree) {
    if(subTree == nullptr)
        return;

    subTree->print();
    preOrder(subTree->left);
    preOrder(subTree->right);
}

void BinaryTree::postOrder(TreeNode* subTree) {
    if(subTree == nullptr)
        return;

    postOrder(subTree->left);
    postOrder(subTree->right);
    subTree->print();
}
    
void BinaryTree::levelOrder(TreeNode* subTree) {
    if(subTree == nullptr)
        return;

    std::queue<TreeNode*> q;
    q.push(subTree);

    while(q.size() > 0) {
        TreeNode* node = q.front();
        q.pop();
        node->print();
        if(node->left != nullptr)
            q.push(node->left);
        if(node->right != nullptr)
            q.push(node->right);
    }
}

void BinaryTree::indentedPreOrder(TreeNode* subTree, int height) {
    if(subTree == nullptr)
        return;

    for(int i = 0; i < height; i++)
        std::cout << '\t';
    subTree->print();
    std::cout << std::endl;
    indentedPreOrder(subTree->left, height + 1);
    indentedPreOrder(subTree->right, height + 1);
}

BinaryTree* BinaryTree::createSampleTree() {
    BinaryTree* t = new BinaryTree();

    t->root = new TreeNode("Les");
    t->root->left = new TreeNode("Cathy");
    t->root->right = new TreeNode("Sam");
    
    TreeNode* cathy = t->root->left;
    TreeNode* sam = t->root->right;

    cathy->left = new TreeNode("Alex");
    cathy->right = new TreeNode("Frank");

    sam->left = new TreeNode("Nancy");
    sam->right = new TreeNode("Voilet");

    TreeNode* voilet = sam->right;
    voilet->left = new TreeNode("Tony");
    voilet->right = new TreeNode("Wendy");

    return t;
}
