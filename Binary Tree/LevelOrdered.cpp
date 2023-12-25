#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTreeNode(Node* root)
{
    cout << "Enter data (or -1 to indicate null): ";
    int data;
    cin >> data;
    root = new Node(data);

    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter the data for the left child of " << data << ":" << endl;
    root->left = createTreeNode(root->left);

    cout << "Enter the data for the right child of " << data << ":" << endl;
    root->right = createTreeNode(root->right);

    return root;
}

void levelOrder(Node* root)
{
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty()) {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }if (temp->right) {
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
    cout << root->data<< " ";
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




int main()
{
    Node* root = NULL;
    root = createTreeNode(root);
    //1 2 -1 -1 3 -1 -1 4 -1 -1 5 -1 -1

    cout << "levelOrder" << " " << endl;
    levelOrder(root);

    cout << "inOrder" << " ";
    inOrder(root);

    cout << "preOrder" << " ";
    preOrder(root);

    cout << "preOrder" << " ";
    preOrder(root);

    

    
        

    system("pause>0");
    return 0;
}

