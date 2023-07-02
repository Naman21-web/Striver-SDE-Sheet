vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()){
       int n=q.size();
       for(int i=0;i<n;i++){
           Node* currnode=q.front();
           q.pop();
           if(i==0) ans.push_back(currnode->data);
           if(currnode->left) q.push(currnode->left);
           if(currnode->right) q.push(currnode->right);
       }
   }
   return ans;
}