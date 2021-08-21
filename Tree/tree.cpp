#include "tree.hpp"

int main(void) {
    
Node *root = create_node(10);
root = insert_node(root, 2);
root = insert_node(root, 4);
print_inorder(root);
std::cout << "---------\n";
print_preorder(root);
std::cout << "---------\n";
print_postorder(root);
std::cout << "---------\n";
}

//   10
// 2    4
