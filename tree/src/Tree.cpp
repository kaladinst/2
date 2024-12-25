#include "../include/Tree.hpp"
#include <iostream>
#include <iomanip>
#include <queue>
#include <cmath>
Tree::Tree() : root(nullptr) {}

Tree::~Tree() {
    destroyTree(root);
}

void Tree::insert(char data) {
        if (data < 32 || data > 126) {
        return;
    }
    insert(data, root);
}

void Tree::insert(char data, TreeNode*& node) {
    if (node == nullptr) {
        node = new TreeNode(data);
    } else if (data < node->data) {
        insert(data, node->left);
    } else if (data > node->data) {
        insert(data, node->right);
    }
}

int Tree::calculateTotalValue() const {
    return calculateTotalValue(root, false);
}

int Tree::calculateTotalValue(TreeNode* node, bool isLeft) const {
    if (node == nullptr) {
        return 0;
    }

    int leftValue = calculateTotalValue(node->left, true);
    int rightValue = calculateTotalValue(node->right, false);

    int nodeValue = node->data;
    if (isLeft) {
        nodeValue *= 2;
    }
    return leftValue + rightValue + nodeValue;
}

void Tree::print() const {
    print(root);
}

void Tree::print(TreeNode* node) const {
    if (node != nullptr) {
        print(node->left);
        std::cout << node->data << " ";
        print(node->right);
    }
}

void Tree::destroyTree(TreeNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

TreeNode* Tree::getRoot() const {
    return root;
}

void Tree::printTreeStructure() const {
    std::queue<TreeNode*> nodes;
    nodes.push(root);

    int maxLevel = treeHeight(root) - 1; // Calculate tree height (zero-based)
    int currentLevel = 0;

    while (currentLevel <= maxLevel) {
        int levelSize = nodes.size(); // Nodes at the current level
        int spaces = (1 << (maxLevel - currentLevel)) - 1; // Leading spaces
        int betweenSpaces = (1 << (maxLevel - currentLevel + 1)) - 1; // Spaces between nodes

        // Print leading spaces before the first node
        for (int i = 0; i < spaces; ++i) {
            std::cout << "   ";
        }

        // Print nodes at the current level
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* current = nodes.front();
            nodes.pop();

            if (current) {
                std::cout << std::setw(3) << current->data;
                nodes.push(current->left);
                nodes.push(current->right);
            } else {
                std::cout << "   ";
                nodes.push(nullptr);
                nodes.push(nullptr);
            }

            // Print spaces between nodes
            if (i < levelSize - 1) {
                for (int j = 0; j < betweenSpaces; ++j) {
                    std::cout << "   ";
                }
            }
        }

        // Move to the next level
        std::cout << "\n";
        currentLevel++;
    }
}
int Tree::treeHeight(TreeNode* node) const {
    if (node == nullptr) return 0;
    return 1 + std::max(treeHeight(node->left), treeHeight(node->right));
}

void Tree::mirror() {
    mirror(root);
}

void Tree::mirror(TreeNode* node) {
    if(node == nullptr) {
        return;
    }

    TreeNode* temp = node->left;
    node->left = node->right;
    node->right = temp;

    mirror(node->left);
    mirror(node->right);
}