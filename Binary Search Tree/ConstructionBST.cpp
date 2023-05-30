#include<iostream>
#include<vector>
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
Node* constructBST(vector<int>&arr,int si,int ei){
    if(si>ei)return nullptr;
    int mid=(si+ei)/2;
    Node* node=new Node(arr[mid]);
    node->left=constructBST(arr,si,mid-1);
    node->right=constructBST(arr,mid+1,ei);
    return node;
}
void inorderTraversal(Node* root){
    if(root==nullptr)return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);

}
int maxEl(Node* root){
    if(root->right==nullptr)return root->data;
    return maxEl(root->right);
}
int minEl(Node* root){
    if(root->left==nullptr)return root->data;
    return minEl(root->left);
}
bool find(Node* root,int key){
    if(root==nullptr)return false;
    if(root->data==key)return true;
    if(root->data>key)return find(root->left,key);
    else return find(root->right,key);
}
bool findIt(Node* root,int key){
    Node* node=root;
    while(node!=nullptr){
        if(node->data==key)return true;
        else if(node->data>key)node=node->left;
        else node=node->right;
    }
    return false;
}
int main(){
    vector<int>arr={10,20,30,40,50,60,70,80,90,100,110,120};
    int si=0;
    int ei=arr.size()-1;
    Node* root=nullptr;
    root=constructBST(arr,si,ei);
    inorderTraversal(root);
    cout<<endl;
    cout<<maxEl(root)<<endl;
    cout<<minEl(root)<<endl;
    cout<<"find is:"<<findIt(root,100)<<endl;
    
}