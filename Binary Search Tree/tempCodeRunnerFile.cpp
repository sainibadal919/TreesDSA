Node* constructBST(vector<int>&arr,int si,int ei){
    if(si>ei)return nullptr;
    int mid=(si+ei)/2;
    Node* node=new Node(arr[mid]);
    node->left=constructBST(arr,si,mid-1);
    node->right=constructBST(arr,mid+1,ei);
    return node;
}