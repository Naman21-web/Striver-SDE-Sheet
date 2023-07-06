
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here	   
	   vector<int> indeg(V,0),vis(V,0),ans;
	   queue<int> q;
	   for(int i=0;i<V;i++){
	       for(auto node:adj[i]){
	           indeg[node]++;
	       }
	   }
	   for(int i=0;i<V;i++){
	       if(indeg[i]==0) q.push(i);
	   }
	   while(!q.empty()){
	       int x=q.front();
	       q.pop();
	       ans.push_back(x);
	       for(auto node:adj[x]){
	           indeg[node]--;
	           if(indeg[node]==0) q.push(node);
	       }
	   }
	   return ans;
	}