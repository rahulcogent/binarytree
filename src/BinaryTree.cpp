#include "BinaryTree.h"
#include <queue>
#include <stack>
#include <iostream>

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

bool BinaryTree::findLCA(std::string nodeData1, std::string nodeData2, std::string& lca) {
    std::vector<std::string> path1;
    std::vector<std::string> path2;

    // find paths for both nodes.
    if(!findPath(root, nodeData1, path1) || !findPath(root, nodeData2, path2))
        return false;

    size_t i;
    // Find first mismatching node.
    for(i = 0; i < path1.size() && i < path2.size(); i++)
        if(path1[i] != path2[i])
            break;

    lca = path1[i - 1];
    return true;
}

bool BinaryTree::findPath(TreeNode* root, std::string nodeData, std::vector<std::string>& path) {
    if(root == nullptr)
       return false;

    // Push this node
    path.push_back(root->data);

    if(root->data == nodeData)
        return true;

    if((root->left && findPath(root->left, nodeData, path))
       || (root->right && findPath(root->right, nodeData, path)))
        return true;

    // Didn't find the node in this path, pop node.
    path.pop_back();
    return false;
}

void BinaryTree::serialize(std::list<std::string>& treeList, TreeNode* subTree, LeafType type) {
    if(subTree == nullptr)
        return;

    std::string data = subTree->data;
    if(type == LEFT)
        data += "->L";
    else if(type == RIGHT)
        data += "->R";

    treeList.push_back(data);
    LeafType childType = NONE;
    if(subTree->left) {
        // Check for left leaf node.
        if(subTree->left->left == nullptr && subTree->left->right == nullptr)
            childType = LEFT;
        serialize(treeList, subTree->left, childType);
    }

    childType = NONE;
    if(subTree->right) {
        // Check for right leaf node.
        if(subTree->right->left == nullptr && subTree->right->right == nullptr)
            childType = RIGHT;
        serialize(treeList, subTree->right, childType);
    }
}

void BinaryTree::deserialize(std::list<std::string> treeList, TreeNode** tree, std::list<std::string>::iterator& iter) {
    if(iter == treeList.end())
        return;
    // Create root node.
    if(*tree == nullptr) {
        std::string data;
        if(isLeftMarker(*iter) || isRightMarker(*iter))
            data = stripMarker(*iter);
        else
            data = *iter;
        *tree = new TreeNode(data);
        ++iter;
    }
    std::string data;
    // Strip data
    if(isLeftMarker(*iter) || isRightMarker(*iter))
        data = stripMarker(*iter);
    else
        data = *iter;
    // Check for right only leaf node.
    if(!isRightMarker(*iter))
        (*tree)->left = new TreeNode(data);
    // If not leaf node recurse.
    if(!isLeftMarker(*iter) && !isRightMarker(*iter))
        deserialize(treeList, &((*tree)->left), ++iter);
    else
        ++iter;
    // Strip data
    if(isLeftMarker(*iter) || isRightMarker(*iter))
        data = stripMarker(*iter);
    else
        data = *iter;
     (*tree)->right = new TreeNode(data);
    // If not leaf node recurse.
    if(!isRightMarker(*iter))
        deserialize(treeList, &((*tree)->right), ++iter);
    else
        ++iter;
}

bool BinaryTree::isLeftMarker(std::string str) {
    int len = str.length();
    return (str[len - 1] == 'L' && str[len - 2] == '>' && str[len - 3] == '-');
}

bool BinaryTree::isRightMarker(std::string str) {
    int len = str.length();
    return (str[len - 1] == 'R' && str[len - 2] == '>' && str[len - 3] == '-');
}

std::string BinaryTree::stripMarker(std::string str) {
    return str.substr(0, str.length() - 3);
}
    
TreeNode* BinaryTree::successor(TreeNode* node) {
    if(root == nullptr || node == nullptr)
        return nullptr;

    std::stack<TreeNode*> s;
    bool done = false;
    TreeNode* node1 = root;
    bool getSuccessor = false;

    while(!done) {
        if(node1) {
            if(node1 == node) {
                getSuccessor = true;
                break;
            }
            s.push(node1);
            node1 = node1->left;
        } else {
            if(s.size() > 0) {
                node1 = s.top();
                // Don't pop parent if node is in the subtree,
                // will need to move up the tree.
                if(node1->right != node) {
                    s.pop();
                }
                node1 = node1->right;
            } else {
                done = true;
            }
        }
    }

    if(getSuccessor) {
        if(node1->right != nullptr) {
            // Find the leftmost child.
            TreeNode* rightNode = node1->right;
            while(rightNode->left != nullptr) {
                rightNode = rightNode->left;
            }
            return rightNode;
        } else {
            TreeNode* currNode = node;
            while(s.size() > 0) {
                TreeNode* pNode = s.top();
                s.pop();
                if(pNode->left == currNode)
                    return pNode;
                currNode = pNode;
            }
            return nullptr;
        }
    }
    
    return nullptr;
}
    
TreeNode* BinaryTree::find(std::string data) {
    if(root == nullptr)
        return nullptr;

    std::stack<TreeNode*> s;
    bool done = false;
    TreeNode* node1 = root;

    while(!done) {
        if(node1) {
            if(node1->data == data) {
                return node1;
            }
            s.push(node1);
            node1 = node1->left;
        } else {
            if(s.size() > 0) {
                node1 = s.top();
                s.pop();
                node1 = node1->right;
            } else {
                done = true;
            }
        }
    }

    return nullptr;
}
 
TreeNode* BinaryTree::predecessor(TreeNode* node) {
    if(root == nullptr || node == nullptr)
        return nullptr;

    std::stack<TreeNode*> s;
    bool done = false;
    TreeNode* node1 = root;
    bool getpredecessor = false;

    while(!done) {
        if(node1) {
            if(node1 == node) {
                getpredecessor = true;
                break;
            }
            s.push(node1);
            node1 = node1->left;
        } else {
            if(s.size() > 0) {
                node1 = s.top();
                // Don't pop parent if node is in the subtree,
                // will need to move up the tree.
                if(node1->right != node) {
                    s.pop();
                }
                node1 = node1->right;
            } else {
                done = true;
            }
        }
    }

    if(getpredecessor) {
        if(node1->left != nullptr) {
            // Find the leftmost child.
            TreeNode* leftNode = node1->left;
            while(leftNode->right != nullptr) {
                leftNode = leftNode->right;
            }
            return leftNode;
        } else {
            TreeNode* currNode = node;
            while(s.size() > 0) {
                TreeNode* pNode = s.top();
                s.pop();
                if(pNode->right == currNode)
                    return pNode;
                currNode = pNode;
            }
            return nullptr;
        }
    }
    
    return nullptr;
}

