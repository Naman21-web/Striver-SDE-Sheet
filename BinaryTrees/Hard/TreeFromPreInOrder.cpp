int search(int in[],int start,int end,int val){
        for(int i=start;i<=end;i++){
            if(in[i]==val) return i;
        }
        return -1;
    }
    Node* create(int in[],int pre[],int start, int end,int &index){
        if(start>end) return NULL;
        int val=pre[index++];
        int pos = search(in,start,end,val);
        Node* root = new Node(val);
        root->left = create(in,pre,start,pos-1,index);
        root->right = create(in,pre,pos+1,end,index);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int i=0;
        return create(in,pre,0,n-1,i);
    }