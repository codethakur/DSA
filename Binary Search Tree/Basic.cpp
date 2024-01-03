#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int d)
{
    if (root == NULL) {
        root = new Node(d);
        return root;
    }
    if (d > root->data) {
        root->right = insertIntoBST(root->right, d);
    }
    else {
        root->left = insertIntoBST(root->left, d);
    }
    return root;
}

void takeInput(Node*& root) {
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
    }
}

void levelOrder(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

//inOrder (LNR)
void inOrder(Node* root)
{
    if (root == NULL)
    {
        cout << " ";
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
//preOrder(NLR)
void preOrder(Node* root)
{
    if (root == NULL) return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

//postOrder(LRN)
void postOrder(Node* root)
{
    if (root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}



int main() {
    Node* root = NULL;
    cout << "Enter the data for BST: " << endl;
    takeInput(root);

    cout << "LevelOrder" << endl;
    levelOrder(root);

    cout<<endl << "inOrder" << " ";
    inOrder(root);

    cout << endl<< "preOrder" << " ";
    preOrder(root);

    cout<<endl << "preOrder" << " ";
    preOrder(root);
    system("pause>0");
}
    
