#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data=0;
    vector<Node*>childs;
    Node(int val){
        this->data=val;
    }
};

Node* construct(vector<int>&arr,int idx){
    
    stack<Node*>st;
    Node* root=new Node(arr[idx++]);
    st.push(root);
    while(!st.empty()){
        int ele=arr[idx++];
         Node* node=new Node(ele);
     if(ele==-1){
        st.pop();
     }
     else{
        st.top()->childs.push_back(node);
        st.push(node);
     }
     
    }
   
    return root;
}

Node* construct2(vector<int>& arr){
    stack<Node*>st;
    for(int i=0;i<arr.size()-1;i++){
        int ele=arr[i];
        if(ele!=-1){
           
            st.push(new Node(ele));
        }
        else{
            Node* node=st.top();
            st.pop();
            st.top()->childs.push_back(node);
        }
    }
    return st.top();
}

void display(Node* root){
    string str="";
    str+=(to_string(root->data)+"-> ");
    for(Node* child:root->childs){
        str+=(to_string(child->data)+" ");
    }

    cout<<str<<endl;
    for(Node* child:root->childs){
        display(child);
    }
}
bool find(Node* node,int key){
    if(node->data==key)return true;
    for(Node* child:node->childs){
        if(find(child,key))return true;

    }
    return false;
}
int size(Node* root){
    int ans=0;
    for(Node* child:root->childs){
        ans+=size(child);
    }
    return ans+1;
}
 int main(){
    vector<int>arr={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,120,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    // Node* root=construct2(arr);
    Node* root=construct(arr,0);
    display(root);
    cout<<endl;
    if(find(root,120))cout<<"Yes Present"<<endl;
    else cout<<"Not Present"<<endl;
    cout<<size(root);
 }