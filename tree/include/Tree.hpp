#ifndef TREE_HPP
#define TREE_HPP
#include "TreeNode.hpp"
class Tree {
public:
    Tree();
    ~Tree();
    void insert(char data);
    int calculateTotalValue() const;
    void printTreeStructure() const;
    void print() const;
    TreeNode* getRoot() const;
    void mirror();
private:
    TreeNode* root;
    void insert(char data, TreeNode*& node);
    int calculateTotalValue(TreeNode* node, bool isLeft) const;
    void destroyTree(TreeNode* node);
    void print(TreeNode* node) const;
    int treeHeight(TreeNode* node) const;
    void mirror(TreeNode* node);
};

#endif
