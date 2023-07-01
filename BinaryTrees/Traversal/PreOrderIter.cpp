vector <int> preorder(Node* root)
{
  // Your code here
    vector<int> ans;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* currnode=st.top();
        st.pop();
        if(currnode->right) st.push(currnode->right);
        if(currnode->left) st.push(currnode->left);
        ans.push_back(currnode->data);
    }
    return ans;
}