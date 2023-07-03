int search(int in[],int start,int end,int val){
    for(int i=start;i<=end;i++){
        if(in[i]==val) return i;
    }
    return -1;
}
Node* create(int in[],int post[],int start,int end,int &index){
    if(start>end) return NULL;
    int val = post[index--];
    int pos = search(in,start,end,val);
    Node* root = new Node(val);
    root->right = create(in,post,pos+1,end,index);
    root->left = create(in,post,start,pos-1,index);
    return root;
}
//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int index=n-1;
    return create(in,post,0,n-1,index);
}