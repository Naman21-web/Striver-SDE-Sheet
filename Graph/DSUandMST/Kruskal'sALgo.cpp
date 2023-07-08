class disjointset{
    vector<int> parent,rank,size;
    public:
    disjointset(int v){
        parent.resize(v+1);
        rank.resize(v+1,0);
        size.resize(v+1,1);
        for(int i=0;i<=v;i++){
            parent[i]=i;
        }
    }
    int findpar(int no){
        if(parent[no]==no) return no;
        return parent[no]=findpar(parent[no]);
    }
    void unionByRank(int u,int v){
        int par_u = findpar(u);
        int par_v = findpar(v);
        if(par_u==par_v) return;
        if(rank[par_u]>rank[par_v]){
            parent[par_v] = par_u;
        }
        else if(rank[par_u]<rank[par_v]){
            parent[par_u] = par_v;
        }
        else{
            parent[par_u] = par_v;
            rank[par_v]++;
        }
    }
    void unionBySize(int u,int v){
        int par_u = findpar(u);
        int par_v = findpar(v);
        if(par_u==par_v) return;
        if(size[par_u]>size[par_v]){
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else{
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
    }
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],{it[0],i}});
            }
        }
        disjointset ds(V);
        sort(edges.begin(),edges.end());
        int mstwt=0;
        for(auto it:edges){
            int wt=it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findpar(u)!=ds.findpar(v)){
                mstwt += wt;
                ds.unionBySize(u,v);
            }
        }
        return mstwt;
    }
};