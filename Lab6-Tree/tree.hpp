#ifndef __TREE__
#define __TREE__

#include <iostream>
#include <queue>

// class of a tree_node
class Node {
public:
    // attributes 
    int data;
    Node *left;
    Node *right;
};

// the function that create a new tree node
Node *create_node(int new_data) {
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

// the function that add a new tree node with a value
Node *insert_node(Node *root, int new_data) {

    if (root == NULL) {
        root = create_node(new_data);
        return root;
    }

    std::queue<Node *> queue;
    queue.push(root);

    while (queue.empty() == false) {
        Node *temp = queue.front();
        queue.pop();
        // insert in left subtree
        if (temp->left != NULL) {
            queue.push(temp->left);
        } else {
            temp->left = create_node(new_data);
            return root;
        }
        // insert in right subtree
        if (temp->right != NULL) {
            queue.push(temp->right);
        } else {
            temp->right = create_node(new_data);
            return root;
        }
    }
    return NULL;   
}

// the function that print nodes in inorder traversal
void print_inorder(Node *root) {
    if (root == NULL) {
        return;
    }
    print_inorder(root->left);
    std::cout << root->data << " ";
    print_inorder(root->right);
}

// the function that print nodes in preorder traversal 
void print_preorder(Node *root) {
    if (root == NULL) {
        return;
    }
    std::cout << root->data << " ";
    print_preorder(root->left);
    print_preorder(root->right);

}

// the function that print nodes in postorder traversal 
void print_postorder(Node *root) {
    if (root == NULL) {
        return;
    }
    print_postorder(root->left);
    print_postorder(root->right);
    std::cout << root->data << " ";

}
#endif