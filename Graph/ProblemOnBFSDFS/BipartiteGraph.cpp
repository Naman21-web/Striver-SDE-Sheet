bool bfs(int i,vector<int> adj[],vector<int> &vis,vector<int> &col){
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node=q.front();
            int color=col[node];
            color ^= 1;
            q.pop();
            for(auto nodes:adj[node]){
                if(!vis[nodes]){
                    vis[nodes]=1;
                    col[nodes]=color;
                    q.push(nodes);
                }
                else{
                    if(col[nodes]!=(color)) return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> vis(V,0),col(V);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            vis[i]=1;
	            col[i]=1;
	            if(bfs(i,adj,vis,col)==false) return false;
	        }
	    }
	    return true;
	}