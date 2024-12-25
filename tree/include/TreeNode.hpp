#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <iostream>
#include <string>

class TreeNode {
    public:
    TreeNode *left;
    TreeNode *right;
    char data;

    TreeNode(char data);
};
#endif 