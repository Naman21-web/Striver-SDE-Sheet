    // Function to return a list containing the inorder traversal of the tree.
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        stack<Node*> st;
        st.push(root);
        while(true){
        	Node* currnode=st.top();
        	//st.pop();
        	if(currnode==NULL){
        		st.pop();
        		if(st.empty()) break;
        		Node* next = st.top();
        		st.pop();
        		ans.push_back(next->data);
        		//if(next->right) 
        		st.push(next->right);
        	}
        	else st.push(currnode->left);
        }
        return ans;
    }