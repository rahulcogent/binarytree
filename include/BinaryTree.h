#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "TreeNode.h"

class BinaryTree {
public:
    BinaryTree() : root(nullptr) { }
    void inOrder(TreeNode* subTree);
    void preOrder(TreeNode* subTree);
    void postOrder(TreeNode* subTree);
    void levelOrder(TreeNode* subTree);
    void indentedPreOrder(TreeNode* subTree, int height);
    static BinaryTree* createSampleTree();

    TreeNode* root;
};

#endif
