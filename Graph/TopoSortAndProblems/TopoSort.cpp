	void dfs(int node,vector<int> adj[],stack<int> &st,vector<int> &vis){
	    for(auto nodes:adj[node]){
	        if(!vis[nodes]){
	            vis[nodes]=1;
	            dfs(nodes,adj,st,vis);
	        }
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   stack<int> st;
	   vector<int> vis(V,0);
	   for(int i=0;i<V;i++){
	       if(!vis[i]){
	           vis[i]=1;
	           dfs(i,adj,st,vis);
	       }
	   }
	   vector<int> ans;
	   while(!st.empty()){
	       int node=st.top();
	       st.pop();
	       ans.push_back(node);
	   }
	   return ans;
	}