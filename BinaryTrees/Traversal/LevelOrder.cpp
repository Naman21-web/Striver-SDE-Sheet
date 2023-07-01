vector<int> findSpiral(Node *root)
{
    //Your code here
    if(root==NULL) return {};
    vector<int> ans;
    stack<Node*> q;
    int ltor=false;
    q.push(root);
    while(!q.empty()){
        // if(ltor){
        int n=q.size();
        stack<Node*> next;
           for(int i=n-1;i>=0;i--){
               Node* currnode=q.top();
               q.pop();
               if(ltor){
                   if(currnode->left) next.push(currnode->left);
                    if(currnode->right) next.push(currnode->right);
               }
               else{
                   if(currnode->right) next.push(currnode->right);
                    if(currnode->left) next.push(currnode->left);
               }
               ans.push_back(currnode->data);
           }
           q=next;
           stack<Node*> clear;
           next=clear;
           ltor=!ltor;
    }
    return ans;
}