#include<iostream>
#include<bits/stdc++.h>
#include<utility>
using namespace std;
class node{
    public:
    int data;
    node* left=nullptr;
    node* right=nullptr;
    
    node(int data){
        this->data=data;
    }
};
int index=0;
node* constructTree(vector<int>&arr){
    if(index==arr.size() || arr[index]==-1){
        index++;
        return nullptr;
    }
    
    node* root=new node(arr[index++]);
    root->left=constructTree(arr);
    root->right=constructTree(arr);
    return root;
}
void width(node* root,vector<int>&arr,int level){
    if(root==nullptr)return;
    arr[0]=max(level,arr[0]);
    arr[1]=min(level,arr[1]);
    width(root->left,arr,level-1);
    width(root->right,arr,level+1);
}
vector<vector<int>> verticalOrder(node* root){
    vector<int>maxMin(2,0);
    width(root, maxMin, 0);
    
    int n = maxMin[0] - maxMin[1] + 1;
    
    vector<vector<int>>ans(n);
    
    queue<pair<node*, int>>que;
    
    que.push({root, -maxMin[1]});
    
    while(que.size() != 0){
        int size = que.size();
        while(size-- > 0){
            pair<node*, int> removedPair = que.front();
            que.pop();
            // a/2
            ans[removedPair.second].push_back(removedPair.first->data);
            
            if(removedPair.first->left != nullptr){
                que.push({removedPair.first->left, removedPair.second - 1});
            }
            
            if(removedPair.first->right != nullptr){
                que.push({removedPair.first->right, removedPair.second + 1 });
            }
            
        }
    }
    return ans;
}

vector<vector<int>> verticalSecond(node* root){
  
    queue<pair<node*,int>>que;
    vector<int>maxMin(2,0);
    width(root,maxMin,0);
     int n=maxMin[0]-maxMin[1]+1;
       vector<vector<int>>ans(n);
    que.push({root,-maxMin[1]});
    while(!que.empty()){
        int size=que.size();
        while(size-- >0){
            pair<node*,int>removedPair=que.front();
            que.pop();
            ans[removedPair.second].push_back(removedPair.first->data);
            if(removedPair.first->left!=nullptr){
                que.push({removedPair.first->left,removedPair.second-1});
            }
            if(removedPair.first->right!=nullptr){
                que.push({removedPair.first->right,removedPair.second+1});
            }
        }
    }
  return ans;
}
void preOrderTraversal(node* root){
    if(root==nullptr)return;
     cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}
vector<int> TopView(node* root){
    vector<vector<int>>ans=verticalOrder(root);
    vector<int>arr;
    for(auto v:ans){
          arr.push_back(v[0]);
    }
    return arr;
}
vector<int> BottomView(node* root){
    vector<vector<int>>ans=verticalOrder(root);
    vector<int>arr;
    for(auto v:ans){
          arr.push_back(v[v.size()-1]);
    }
    return arr;
}
int main(){
node* root=nullptr;
 vector<int>arr={10,20,40,80,-1,-1,90,100,-1,-1,-1,50,-1,-1,30,60,110,120,-1,-1,140,-1,-1,-1,70,-1,-1};
root=constructTree(arr);
// preOrderTraversal(root);
// vector<int>ans(2,0);
// width(root,ans,0);
// cout<<"width is : "<<ans[0]-ans[1]<<endl;
 vector<vector<int>>myAns=verticalOrder(root);
 for(auto v:myAns){
    for(int ele:v){
        cout<<ele<<" ";
    }
    cout<<endl;
 }
 cout<<endl;
cout<<"Top View"<<endl;
 vector<int>topans=TopView(root);
 for(int ele:topans){
    cout<<ele<<" ";
 }

 cout<<endl;
 cout<<"Bottom View"<<endl;
 vector<int>BottomAns=BottomView(root);
 for(int ele:BottomAns){
    cout<<ele<<" ";
 }

 cout<<endl;

}