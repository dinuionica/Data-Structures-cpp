#ifndef __BST__
#define __BST__

#include <iostream>

// class of a binary search tree
class BST {

public:
    int data;
    BST *left, *right;
    // default constructor
    BST() {
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }

    // constructor with value argument
    BST(int value) {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }

    // function to insert a new node in bst
    BST *insert(BST *root, int value) {

        if (root == NULL) {
            return new BST(value);
        }

        if (root->data > value) {
            root->left = insert(root->left, value);
        } else {
            root->right = insert(root->right, value);
        }
        return root;
    }

    // function to find the min value of the bst
    BST *find_minim(BST *root) {
        if (root == NULL) {
            return NULL;
        } else if (root->left == NULL) {
            return root;
        } else {
            return find_minim(root->left);
        }
    }

    // function to find the max value of the bst
    BST *find_max(BST *root) {
        if (root == NULL) {
            return NULL;
        } else if (root->right == NULL) {
            return root;
        } else {
            return find_max(root->right);
        }
    }
    // function to remove an element from bst
    BST *remove(BST *root, int value) {

        if (root == NULL) {
            return NULL;
        }

        if (root->data > value) {
            root->left = remove(root->left, value);
        } else if (root->data < value) {
            root->right = remove(root->right, value);
        } else if (root->left != NULL && root->right != NULL) {

            BST *temp = find_minim(root->right);
            root->data = temp->data;
            root->right = remove(root->right, root->data);
        } else {
            BST *temp = root;
            if (root->left == NULL) {
                root = root->right;
            } else if (root->right == NULL) {
                root = root->left;
            }
        }
        return root;
    }

    // function to print element in inorder
    void print_inorder(BST *root) {
        if (root == NULL) {
            return;
        }
        print_inorder(root->left);
        std::cout << root->data << "\n";
        print_inorder(root->right);
    }
};

#endif // __BST__