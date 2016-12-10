#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include "TreeNode.h"
#include <vector>
#include <list>

enum LeafType {
    LEFT,
    RIGHT,
    NONE
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) { }
    void inOrder(TreeNode* subTree);
    void preOrder(TreeNode* subTree);
    void postOrder(TreeNode* subTree);
    void levelOrder(TreeNode* subTree);
    void indentedPreOrder(TreeNode* subTree, int height);
    static BinaryTree* createSampleTree();
    bool findLCA(std::string nodeData1, std::string nodeData2, std::string& lcm);
    void serialize(std::list<std::string>& treeList, TreeNode* subTree, LeafType type);
    void deserialize(std::list<std::string> treeList, TreeNode** tree, std::list<std::string>::iterator& iter);

    TreeNode* root;

private:
    bool findPath(TreeNode* node, std::string nodeData, std::vector<std::string>& path);
    bool isLeftMarker(std::string str);
    bool isRightMarker(std::string str);
    std::string stripMarker(std::string str);
};

#endif
