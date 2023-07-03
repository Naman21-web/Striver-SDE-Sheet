void noOfPath(Node* root,vector<int> ans,vector<vector<int>> &res){
    ans.push_back(root->data);
    if(!root->left && !root->right){
        res.push_back(ans);
        return;
    }
    if(root->left)noOfPath(root->left,ans,res);
    if(root->right)noOfPath(root->right,ans,res);
}
/* The function should print all the paths from root
 to leaf nodes of the binary tree */
vector<vector<int>> Paths(Node* root)
{
    // Code here
    vector<vector<int>> res;
    vector<int> ans;
    noOfPath(root,ans,res);
    return res;
}