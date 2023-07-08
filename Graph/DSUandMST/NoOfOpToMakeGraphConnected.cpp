class disjointset{
    public:
    vector<int> parent,rank,size;
    disjointset(int v){
        parent.resize(v+1);
        rank.resize(v+1,0);
        size.resize(v+1,1);
        for(int i=0;i<=v;i++) parent[i]=i;
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


class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edges) {
        // code here
        disjointset ds(n);
        int extraEdge=0;
        for(int i=0;i<edges.size();i++){
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int par_1 = ds.findpar(node1);
            int par_2 = ds.findpar(node2);
            if(par_1==par_2) extraEdge++;
            else{
                ds.unionBySize(node1,node2);
            }
        }
        int cntComp=-1;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cntComp++;
        }
        if(cntComp>extraEdge) return -1;
        return cntComp;
    }
};