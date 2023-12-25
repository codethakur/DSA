#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr; // Initialize left and right pointers to nullptr
    newNode->right = nullptr;
    return newNode;
}

void printNode(Node* root) // Corrected the function signature and parameter
{
    if (root == nullptr) return; // Check if the current node is null

    printNode(root->left); // Recursively print left subtree
    cout << root->data << " "; // Print current node's data
    printNode(root->right); // Recursively print right subtree
}

int main()
{
    Node* root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(5);

    printNode(root); // Pass the root to the printNode function

    system("pause>0");
    return 0; // Return 0 from main to indicate successful execution
}
/*
          1
       / \
      2   3
         / \
        4   5
output: 2 1 4 3 5
*/
