#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left=nullptr;
    Node* right=nullptr;
    
    Node(int data){
        this->data=data;
    }
};
int index=0;
vector<Node*> nodeToRootPath(Node* root,int key){
    if(root==nullptr)return {};
    if(root->data==key){
        return {root};
    }
    vector<Node*>leftAns=nodeToRootPath(root->left,key);
    vector<Node*>rightAns=nodeToRootPath(root->right,key);
    vector<Node*>myAns;
    if(leftAns.size()>rightAns.size()){
        myAns=leftAns;
    }
    else {
        myAns=rightAns;
    }
    if(myAns.size()>0)myAns.push_back(root);
    return myAns;
    
}

Node* constructTree(vector<int>&arr){
    if(index==arr.size() || arr[index]==-1){
        index++;
        return nullptr;
    }
    
    Node* root=new Node(arr[index++]);
    root->left=constructTree(arr);
    root->right=constructTree(arr);
    return root;
}
bool rootToNode(Node* root,int key,vector<Node*> &arr){
    if(root==nullptr){
        return false;
    }
   
    if(root->data==key){
       arr.push_back(root);
       return true;
    }
     arr.push_back(root);
    bool leftans=rootToNode(root->left,key,arr);
    if(leftans){
       
        return true;
    }
    bool rightans=rootToNode(root->right,key,arr);
    if(rightans){
       
        return true;
    }
    arr.pop_back();
    return false;
}
void LevelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    int level=0;
    while(!q.empty()){
        int size=q.size();
        cout<<"level "<<level<<"->";
        while(size-->0){
            Node* temp=q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left!=nullptr){
            q.push(temp->left);
        }
        if(temp->right!=nullptr){
            q.push(temp->right);
        }

        }
        cout<<endl;
        level++;
       
    }
}
void leftView(Node *root)
{  
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        for(int i=0;i<size;i++){
            Node* temp=q.front();
            q.pop();
            if(i==0){
               cout<<temp->data<<" ";
            }
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
    }
   // Your code here
}
vector<int> rightView(Node* root){
    vector<int>ans;
    queue<Node*>q;
    
    q.push(root);
    while(!q.empty()){
     int size=q.size();
     Node*temp=nullptr;
     while(size-- >0){
        temp=q.front();
        q.pop();
        if(temp->left!=nullptr){
            q.push(temp->left);
        }
        if(temp->right!=nullptr){
                q.push(temp->right);
         }
     }
     ans.push_back(temp->data);
    }
    return ans;
}
int main(){
    Node* root=nullptr;
 vector<int>arr={10,20,40,80,-1,-1,90,100,-1,-1,-1,50,-1,-1,30,60,110,120,-1,-1,140,-1,-1,-1,70,-1,-1};
 int idx=0;
root=constructTree(arr);
 vector<Node*>ans;
//  ans=nodeToRootPath(root,90);
// rootToNode(root,140,ans);
// for(auto el:ans){
//     cout<<el->data<<" ";
// }
cout<<endl;
LevelOrderTraversal(root);
cout<<endl;
leftView(root);
vector<int>a=rightView(root);
cout<<endl;
for(auto el:a){
    cout<<el<<" ";
}
}