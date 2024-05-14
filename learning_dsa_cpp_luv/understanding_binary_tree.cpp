#include <bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
node* buildpreorder(node* root){
        int data;
        cin>>data;
        root = new node(data);
        
        if(data == -1){
            return NULL;
        }

        //cout<<"enter the data for the left node of "<<root->data<<": ";
        root->left = buildpreorder(root->left);

        //cout<<"enter the data for the right node of "<<root->data<<": ";
        root->right = buildpreorder(root->right);

        return root;
}

node* buildlevelorder(node* root){
    queue<node*> q;
    int data;
    cout<<"enter the data for root: ";
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
       node* temp = q.front();
       q.pop();
       //cout<<"enter data for left of "<<temp->data<<" : ";
       cin>>data;
       if(data != -1) {
       node* lefti = new node(data);
       temp->left = lefti;
       q.push(lefti);
       }
       
       //cout<<"enter data for right of "<<temp->data<<" : ";
       cin>>data;
       if(data != -1) {
       node* righti = new node(data);
       temp->right = righti;
       q.push(righti);
       }
    }
    return root;
}

void levelorder(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
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

void inorder(node* root){
    //base condition
    if(root == NULL) return;

    //recurrence relation
    inorder(root->left);
    cout<<" "<<root->data<<" ";
    inorder(root->right);
}

void preorder(node* root){
    //base condition
    if(root == NULL) return;

    //recurrence relation
    cout<<" "<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node* root){
    //base condition
    if(root == NULL) return;

    //recurrence relation
    postorder(root->left);
    postorder(root->right);
    cout<<" "<<root->data<<" ";
}

int height(node* root){
        // code here
        //approach - firstly finding the height of the left subtree and right subtree and then , finding
        // the maximum out of those and adding 1 to it to count the root node and returning it .
        if (root == NULL) return 0;
        
        int h1 = height(root->left); 
        int h2 = height(root->right);
        
        return max(h1,h2) + 1;
        
    }

    bool solve(node* root){
        if(root->left == NULL && root->right == NULL) return true;
        
        bool res = true;
        if(root->left!= NULL && root->right == NULL){
            if(root->left->data > root->data) return false;
        }
        else if(root->left == NULL && root->right != NULL){
            if(root->right->data > root->data) return false;
        }
        else{
            if(root->left->data > root->data || root->right->data > root->data) return false;
        }
        
        bool lef,righ;
        if(root->left != NULL)
           lef = solve(root->left);
        else lef = true;
        if(root->right != NULL)
           righ = solve(root->right);
        else righ = true;
        return (lef && righ);
    }

int main() {
//      7        pre order input of the tree : 7 3 2 -1 -1 1 -1 -1 4 1 -1 -1 -1
//     / \       level order input of the tree : 7 3 4 2 1 6 -1 -1 -1 9 -1 -1 -1 -1 -1
//    3   4
//   / \  / 
//  2  1  6
//    /
//   9
node* root = NULL;
// cout<<"enter the data for root : ";
// root = buildpreorder(root);    //it takes the data in pre order traversal way
root = buildlevelorder(root);     //mostly level order is used .
cout<<"the level order traversal of the tree is : "<<endl;
levelorder(root);
cout<<endl;
cout<<"the inorder traversal of the tree is: "; 
inorder(root);
cout<<endl;
cout<<"the preorder traversal of the tree is: ";
preorder(root);
cout<<endl;
cout<<"the postorder traversal of the tree is: ";
postorder(root);
cout<<endl;
cout<<"the height of the tree is : "<<height(root);
cout<<endl;
cout<<solve(root);
return 0;
}