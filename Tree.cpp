//
// Created by Sean Billings on 5/20/23.
//

#include "Tree.hpp"

#include <iostream>
#include <sstream>

using namespace std;

//Helper function to find minimum value node
Node* findMinNode(Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

void Tree::insertValue(Node* &node, int value) {
    if (node == NULL) {
        node = new Node(value);
    }
    else if (value < node->value) {
        insertValue(node->left, value);
    }
    else {
        insertValue(node->right, value);
    }
}

bool Tree::findValue(Node* node, int value) {
    if (node == NULL) {
        return false;
    }
    else if (node->value == value && !node->deleted) {
        return true;
    }
    else if (value < node->value) {
        return findValue(node->left, value);
    }
    else {
        return findValue(node->right, value);
    }
}

bool Tree::removeValue(Node* node, int value) {
    if (node == NULL) {
        return false;
    }
    else if (node->value == value) {
        node->deleted = true;
        return true;
    }
    else if (value < node->value) {
        return removeValue(node->left, value);
    }
    else {
        return removeValue(node->right, value);
    }
}

string Tree::preOrder(Node* node) {
    ostringstream oss;
    if (node != NULL) {
        oss << (node->deleted ? to_string(node->value) + "D " : to_string(node->value) + " ");
        oss << preOrder(node->left);
        oss << preOrder(node->right);
    }
    return oss.str();
}

string Tree::inOrder(Node* node) {
    ostringstream oss;
    if (node != NULL) {
        oss << inOrder(node->left);
        oss << (node->deleted ? to_string(node->value) + "D " : to_string(node->value) + " ");
        oss << inOrder(node->right);
    }
    return oss.str();
}

string Tree::postOrder(Node* node) {
    ostringstream oss;
    if (node != NULL) {
        oss << postOrder(node->left);
        oss << postOrder(node->right);
        oss << (node->deleted ? to_string(node->value) + "D " : to_string(node->value) + " ");
    }
    return oss.str();
}

void Tree::deleteTree(Node* node) {
    if (node != NULL) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

int Tree::findLarger(Node* node, int value) {
    if (node == NULL) {
        return -1;
    }
    else if (node->value == value && !node->deleted) {
        return value;
    }
    else if (node->value > value && !node->deleted) {
        int leftLarger = findLarger(node->left, value);
        return (leftLarger != -1) ? leftLarger : node->value;
    }
    else {
        return findLarger(node->right, value);
    }
}

// Function to delete a node and maintain BST property
Node* deleteNode(Node* &root, int value) {
    if (root == NULL) return root;

    if (value < root->value)
        root->left = deleteNode(root->left, value);
    else if (value > root->value)
        root->right = deleteNode(root->right, value);
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // node with two children
        Node* temp = findMinNode(root->right);

        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

Node* Tree::removeLarger(Node* &node, int value) {
    if (node == NULL) {
        return NULL;
    }
    else if (node->value == value && !node->deleted) {
        node->deleted = true;
        return node;
    }
    else if (node->value > value && !node->deleted) {
        Node* leftLarger = removeLarger(node->left, value);
        if (leftLarger != NULL)
            return leftLarger;
        else {
            Node* temp = node;
            node = deleteNode(node, node->value);
            return temp;
        }
    }
    else {
        return removeLarger(node->right, value);
    }
}

