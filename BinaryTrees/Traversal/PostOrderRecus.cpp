void postOrdertraverse(Node* root,vector<int> &ans){
        if(root==NULL) return;
        postOrdertraverse(root->left,ans);
        postOrdertraverse(root->right,ans);
        ans.push_back(root->data);
    }

//Function to return a list containing the postorder traversal of the tree.
vector <int> postOrder(Node* root)
{
  // Your code here
  vector<int> ans;
  postOrdertraverse(root,ans);
  return ans;
}