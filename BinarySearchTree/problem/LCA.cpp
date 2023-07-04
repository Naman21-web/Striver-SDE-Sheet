Node* LCA(Node *root, int n1, int n2)
        {
            // code here
            if(n1>n2) {
                n2=n2^n1;
                n1=n2^n1;
                n2=n2^n1;
            }
            if(root==NULL) return NULL;
            if(root->data==n1 || root->data==n2) return root;
            if(root->data>n1 && root->data<n2) return root;
            if(root->data>n1 && root->data>n2) return LCA(root->left,n1,n2);
            else return LCA(root->right,n1,n2);
        }