#include <bits/stdc++.h>
using namespace std;
class Node{
   public:
   int data;
   Node* left;
   Node* right;
   
   Node(int data){
    this->data = data;
    this->left = this->right = NULL;
   }
};

Node* insertIntoBST(Node* root, int data){
     if(root == NULL){
        root = new Node(data);
        return root;
     }

     if(data <= root->data) root->left = insertIntoBST(root->left, data);
     else root->right = insertIntoBST(root->right, data);
     return root;
}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data;
    }
}

void levelorder(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        cout<<temp->data<<" ";
        }
    }
}

int minValue(Node* root){
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

int maxValue(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

Node* inorder_pred(Node* root){
    if(root->left == NULL) return root;
    root = root->left;
    while(root->right != NULL) 
       root = root->right;
    return root;
}

Node* inorder_succ(Node* root){
    if(root->right == NULL) return root;
    root = root->right;
    while(root->left != NULL)
       root = root->left;
    return root;
}

Node* deleteFromBST(Node* root, int val){
    //base case
    if(root == NULL) return root;

    //if the value is equal to current node value
    if(root->data == val){
        //0 child node
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
            }
        //1 child node
          //only left child
        else if(root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
          //only right child
        else if(root->left == NULL && root->right != NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //two child node
        else {
            root->data = inorder_succ(root)->data;
            root->right = deleteFromBST(root->right, root->data);
            return root; 
        }
    }

    // if value is greater than current node value, then the value may be in right subtree
    else if(root->data < val){
        root->right = deleteFromBST(root->right, val);
        return root;
    }

    // else the value is smaller than current node value, then the value may be in left subtree
    else{
        root->left = deleteFromBST(root->left, val);
        return root;
    }
}

void inorder_traversal(Node* root, unordered_map<int,int> &ans){
    if(root == NULL) return;
    inorder_traversal(root->left, ans);
    ans[root->data]++;
    inorder_traversal(root->right, ans);
}

int main() {
    //example :
    //       8
    //      / \
    //     6  15          input for bst maker :  8 6 15 2 10 17 5 -1
    //    /   / \
    //   2   10 17
    //    \ 
    //     5
Node* root = NULL;
cout<<"enter the data for BST : ";
takeInput(root);
cout<<"the BST looks like : "<<endl;
levelorder(root);
cout<<endl<<"the minimum value is : "<<minValue(root);
cout<<endl<<"the maximum value is : "<<maxValue(root);
cout<<endl<<"enter the value to delete : ";
int data;
cin>>data;
root = deleteFromBST(root, data);
levelorder(root);
return 0;
}