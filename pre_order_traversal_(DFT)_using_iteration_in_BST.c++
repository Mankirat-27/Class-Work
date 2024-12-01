// Pre Order Traversal (DFT) using recursion in BST
#include<iostream>
#include<stack>
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

void printTree_DFT(Node* root) {
    if (root == NULL) return;

    stack<Node*> stack;
    stack.push(root);

    while (!stack.empty()) {
        Node* current = stack.top();
        stack.pop();

        // Printing the left node 
        cout << current->val << " ";

        // Push the right child first so that left child comes on top and gets popped first and gets printed 
        if (current->right != NULL) {
            stack.push(current->right);
        }

        // Now pushing left child into the stack
        if (current->left != NULL) {
            stack.push(current->left);
        }
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
    cout<<"\nPre Order Traversal (DFT)"<<endl;
    printTree_DFT(rootNode);
    
    return 0;
}
