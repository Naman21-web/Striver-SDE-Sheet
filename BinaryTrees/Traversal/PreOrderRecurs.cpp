void preordertraverse(Node* root,vector<int> &ans){
    if(root==NULL) return;
    ans.push_back(root->data);
    preordertraverse(root->left,ans);
    preordertraverse(root->right,ans);
}
vector <int> preorder(Node* root)
{
  // Your code here
  vector<int> ans;
  preordertraverse(root,ans);
  return ans;
}