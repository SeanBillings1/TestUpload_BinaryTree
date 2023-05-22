//
// Created by Sean Billings on 5/20/23.
//

#ifndef UNTITLED11_TREE_HPP
#define UNTITLED11_TREE_HPP


#include <iostream>
#include <string>


using namespace std;

class Node {
public:
    int value;
    bool deleted;
    Node* left;
    Node* right;
    Node(int v) : value(v), deleted(false), left(NULL), right(NULL) {}
};

class Tree {
private:
    Node* root;
    void insertValue(Node* &node, int value);
    bool findValue(Node* node, int value);
    bool removeValue(Node* node, int value);
    string preOrder(Node* node);
    string inOrder(Node* node);
    string postOrder(Node* node);
    void deleteTree(Node* node);
    int findLarger(Node* node, int value);
    Node* removeLarger(Node* &node, int value);
public:
    Tree() : root(NULL) {}
    ~Tree() { deleteTree(root); }
    void insertValue(int value) { insertValue(root, value); }
    bool findValue(int value) { return findValue(root, value); }
    bool removeValue(int value) { return removeValue(root, value); }
    string preOrder() { return preOrder(root); }
    string inOrder() { return inOrder(root); }
    string postOrder() { return postOrder(root); }
    int findLarger(int value) { return findLarger(root, value); }
    bool removeLarger(int value) { return removeLarger(root, value) != NULL; }
};

#endif //UNTITLED11_TREE_HPP
