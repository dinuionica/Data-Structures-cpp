#include "bst.hpp" 

int main(void) {

    // create bst
    BST b, *root = NULL;

    // insertions
    root = b.insert(root, 50);
    b.insert(root, 30);
    b.insert(root, 20);
    b.insert(root, 40);
    b.insert(root, 70);
    b.insert(root, 60);
    b.insert(root, 80);

    // delete a node
    b.remove(root, 80);

    // print inorder 
    b.print_inorder(root);

    // print min and max value
    BST *node_max = b.find_max(root);
    BST *node_min = b.find_minim(root);

    std:: cout << node_min->data << " " << node_max->data << "\n";
 
    return 0;
}