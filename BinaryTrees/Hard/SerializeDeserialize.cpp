vector<int> serialize(Node *root) 
    {
        //Your code here
        vector<int> ans;
        if(root==NULL) return ans;
        // ans.push_back(root->data);
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                Node* currnode=q.front();
                q.pop();
                if(currnode!=NULL) ans.push_back(currnode->data);
                else ans.push_back(-1);
                if(currnode!=NULL){q.push(currnode->left);
                q.push(currnode->right);}
            }
        }
        return ans;
    }
    
    //Function to deserialize a list and construct the tree.
    Node * deSerialize(vector<int> &A)
    {
       //Your code here
      int i=0;
      Node* root=new Node(A[i++]);
      queue<Node*> q;
      q.push(root);
      while(i<A.size()){
          Node* currnode=q.front();
          q.pop();
          if(A[i]!=-1){currnode->left=new Node(A[i++]);q.push(currnode->left);}
          else currnode->left=NULL,i++;
          if(A[i]!=-1){currnode->right=new Node(A[i++]);q.push(currnode->right);}
          else currnode->right=NULL,i++;
      }
      return root;
    }