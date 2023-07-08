class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int sum=0;
        set<pair<int,int>> st;
        st.insert({0,0});
        vector<int> vis(V,0);
        while(!st.empty()){
            auto it=*st.begin();
            int node=it.second;
            int cost=it.first;
            st.erase(it);
            if(vis[node]==1) continue;
            sum += cost;
            vis[node]=1;
            for(auto adjnode:adj[node]){
                if(!vis[adjnode[0]]){
                    st.insert({adjnode[1],adjnode[0]});
                }
            }
        }
        return sum;
        
    }
};