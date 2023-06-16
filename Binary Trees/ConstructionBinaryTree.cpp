#include<iostream>
#include<vector>
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

node* buildTree(node* root,vector<int>source,int &idx){
   int data=source[idx];
   if(data==-1)return nullptr;
   root=new node(data);
   idx=idx+1;
   root->left=buildTree(root->left,source,idx);
   idx=idx+1;
   root->right=buildTree(root->right,source,idx);
   return root;
}
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

void display(node* root){
    if(root==nullptr)return;
    string ans="";
    // ans=ans+to_string(root->left->data)+to_string(root->data)+to_string(root->right->data);
    ans+=(root->left==nullptr?" . ":to_string(root->left->data)+" ");
    ans+="<-"+to_string(root->data)+"->";
    ans+=(root->right==nullptr?" . ":to_string(root->right->data)+" ");
    cout<<ans<<endl;
    display(root->left);
    display(root->right);
}
void preOrderTraversal(node* root){
    if(root==nullptr)return;
     cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}
void inorderTraversal(node* root){
    if(root==nullptr)return;
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);

}
void postorderTraversal(node* root){
    if(root==nullptr)return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}
void count(node* root,int &size){
    if(root==nullptr)return;
    //  cout<<root->data<<" ";
    size+=1;
    count(root->left,size);
    count(root->right,size);

}
int size(node* root){
    return root==nullptr?0:size(root->left)+size(root->right)+1;
}

int heightWithEdge(node* root){
    if(root==nullptr)return -1;
    return max(heightWithEdge(root->left),heightWithEdge(root->right))+1;
}
int heightWithNodes(node* root){
    if(root==nullptr)return 0;
    return max(heightWithNodes(root->left),heightWithNodes(root->right))+1;
}
bool find(node* root,int key){
  if(root==nullptr)return false;
  else if(root->data==key)return true;
  else return find(root->left,key) || find(root->right,key);
}
bool nodeToRoot(node* root,int key,vector<node*> &arr){
    if(root==nullptr){
        return false;
    }
    if(root->data==key){
       arr.push_back(root);
       return true;
    }
    bool leftans=nodeToRoot(root->left,key,arr);
    if(leftans){
        arr.push_back(root);
        return true;
    }
    bool rightans=nodeToRoot(root->right,key,arr);
    if(rightans){
        arr.push_back(root);
        return true;
    }
    return false;
}

vector<node*> nodeToRootPath(node* root,int key){
    if(root==nullptr)return {};
    if(root->data==key){
        return {root};
    }
    vector<node*>leftAns=nodeToRootPath(root->left,key);
    vector<node*>rightAns=nodeToRootPath(root->right,key);
    vector<node*>myAns;
    if(leftAns.size()>rightAns.size()){
        myAns=leftAns;
    }
    else {
        myAns=rightAns;
    }
    if(myAns.size()>0)myAns.push_back(root);
    return myAns;
    
}


void pathToLeaf(node*root,string ans){
    if(root==nullptr)return;
    if(root->left==nullptr && root->right ==nullptr){
        cout<<ans+to_string(root->data)<<endl;
        return;
    }
    pathToLeaf(root->left,ans+to_string(root->data)+" ");
    pathToLeaf(root->right,ans+to_string(root->data)+" ");
}
void width(node* root,vector<int>&arr,int level){
    if(root==nullptr)return;
    arr[0]=max(level,arr[0]);
    arr[1]=min(level,arr[1]);
    width(root->left,arr,level-1);
    width(root->right,arr,level+1);
}

int main(){
 node* root=nullptr;
 vector<int>arr={10,20,40,80,-1,-1,90,100,-1,-1,-1,50,-1,-1,30,60,110,120,-1,-1,140,-1,-1,-1,70,-1,-1};
 int idx=0;
//  root=buildTree(root,source,idx);
root=constructTree(arr);
// display(root);
// int total=0;
// cout<<endl;
//   count(root,total);
//   cout<<total<<endl;
//   cout<<size(root)<<endl; 
//  cout<<"Height of tree is "<<heightWithEdge(root);
//  cout<<endl;
//  cout<<"Height of tree is "<<heightWithNodes(root);
// preOrderTraversal(root);
// cout<<endl;
// inorderTraversal(root);
// cout<<endl;
// postorderTraversal(root);
// cout<<endl;

// cout<<find(root,0)<<endl;
 
//  vector<node*>ans;
// //  nodeToRoot(root,110,ans);
// ans=nodeToRootPath(root,90);
//  for(node* n:ans){
//     cout<<n->data<<" ";
//  }
 cout<<endl;
// pathToLeaf(root,"");
vector<int>ans(2,0);
width(root,ans,0);
cout<<"width is : "<<ans[0]-ans[1]<<endl;


}