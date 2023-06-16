#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* left=nullptr;
    Node* right=nullptr;
    int data=0;

    Node(int data){
        this->data=data;
    }

};
int idx=0;
Node* constructTree(vector<int>&arr){
   if(idx==arr.size() || arr[idx]==-1){
    idx++;
    return nullptr;
   }
  
   Node* root=new Node(arr[idx++]);
   root->left=constructTree(arr);
   root->right=constructTree(arr);
   return root;
}

void display(Node* root){
    if(root==nullptr)return;
    string ans="";
   ans+=(root->left==nullptr?" . ":to_string(root->left->data)+" ");
    ans+=" <- "+to_string(root->data)+" -> ";
    ans+=(root->right==nullptr?" . ":to_string(root->right->data)+" ");
    cout<<ans<<endl;
    display(root->left);
    display(root->right);
}
bool nodeToRoot(Node* root,vector<int>& arr,int key){
    if(root==nullptr)return false;
    if(root->data==key){
        arr.push_back(root->data);
        return true;
    }
    bool leftans=nodeToRoot(root->left,arr,key);
    if(leftans){
        arr.push_back(root->data);
        return true;
    }
    bool rightans=nodeToRoot(root->right,arr,key);
    if(rightans){
        arr.push_back(root->data);
        return true;
    }
    return false;

}
bool rootToNode(Node*root,vector<int>& arr,int key){
    if(root==nullptr){
        return false;
    }
    arr.push_back(root->data);
    if(root->data==key){
        return true;
    }
    bool leftans=rootToNode(root->left,arr,key);
    if(leftans)return true;
    bool rightans=rootToNode(root->right,arr,key);
    if(rightans)return true;

    arr.pop_back();
    return false;
}
int main(){
vector<int>arr={10,20,40,80,-1,-1,90,100,-1,-1,-1,50,-1,-1,30,60,110,120,-1,-1,140,-1,-1,-1,70,-1,-1};
Node* root=constructTree(arr);
display(root);
vector<int>ans;
// nodeToRoot(root,ans,140);
rootToNode(root,ans,140);
for(auto el:ans){
    cout<<el<<" ";
}
}
