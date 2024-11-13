// Pre Order Traversal (BFT) using recursion in BST
#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* parent;
};

void createTree(Node* root) {
    char choice;
    int value;

    cout<<"Does left child of "<<root->val<<" exist? (y/n): ";
    cin>>choice;
    if(choice == 'y') {
            Node* newNode = new Node();
    cout<<"Enter the value of Node: ";
    cin>>value;
    root->left = newNode;
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = root;
        createTree(newNode);
    }
    
    cout<<"Does right child of "<<root->val<<" exist? (y/n): ";
    cin>>choice;
    if(choice == 'y') {
            Node* newNode = new Node();
    cout<<"Enter the value of Node: ";
    cin>>value;
    root->right = newNode;
    newNode->val = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = root;
        createTree(newNode);
    }
}

void printTree_BFT(Node* root) {
    queue<Node*> queue;
    if(root != NULL) {
        queue.push(root);        
    }
    while(!queue.empty()) {
        cout<<queue.front()->val<<" ";
        if(queue.front()->left != nullptr) {
            queue.push(queue.front()->left);
        }
        if(queue.front()->right != nullptr) {
            queue.push(queue.front()->right);
        }
    queue.pop();
    }
}

int main() {
    int rootNodeValue;
    Node* rootNode = new Node();
    cout<<"Enter the value of Root Node: ";
    cin>>rootNodeValue;
    rootNode->val = rootNodeValue;
    rootNode->parent = NULL;
    
    createTree(rootNode);
    cout<<"\nPre Order Traversal (BFT)"<<endl;
    printTree_BFT(rootNode);
    
    return 0;
}



