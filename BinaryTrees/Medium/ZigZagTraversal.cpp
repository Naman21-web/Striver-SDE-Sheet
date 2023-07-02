vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	stack<Node*> q;
    	q.push(root);
    	vector<int> ans;
    	bool ltor=true;
    	while(!q.empty()){
    	    stack<Node*> st;
    	    int n=q.size();
    	    for(int i=0;i<n;i++){
    	        Node* currnode=q.top();
    	        ans.push_back(currnode->data);
    	        q.pop();
    	        if(ltor){
    	            if(currnode->left)st.push(currnode->left);
    	            if(currnode->right)st.push(currnode->right);
    	        }
    	        else{
    	            if(currnode->right)st.push(currnode->right);
    	            if(currnode->left)st.push(currnode->left);
    	        }
    	    }
    	    ltor = !ltor;
    	    q=st;
    	    while(!st.empty()) st.pop();
    	}
    	return ans;
    }