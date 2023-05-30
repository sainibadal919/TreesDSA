#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left=nullptr;
        this->right=nullptr;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter the data:";
    int data;
    cin>>data;
    if(data==-1)return nullptr;
   root=new Node(data);

    cout<<"Enter data for left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
void InorderTraversal(Node* root){
    if(root==nullptr)return;
     cout<<root->data<<" ";
    InorderTraversal(root->left);
    InorderTraversal(root->right);

}
void LevelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
             cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
       
    }
}
void LevelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(nullptr);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp==nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
             cout<<temp->data<<" ";
            if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
        }
       
    }
}
int main(){
   Node* root=nullptr;
   root=buildTree(root);
//    InorderTraversal(root);
cout<<endl;
cout<<"Printing level order Traversal"<<endl;
  LevelOrderTraversal(root);

  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
}