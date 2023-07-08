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
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        unordered_map<int,int> countNodes;
        int maxRow=0,maxCol=0;
        for(int i=0;i<stones.size();i++){
            maxRow = max(maxRow,stones[i][0]);
            maxCol = max(maxCol,stones[i][1]);
        }
        disjointset ds(maxRow+maxCol+1);
        for(auto it:stones){
            int row = it[0];
            int col = it[1]+maxRow+1;
            if(ds.findpar(row)!=ds.findpar(col)){
                ds.unionBySize(row,col);
            }
            countNodes[row]=1;
            countNodes[col]=1;
        }
        int cntcomp=0;
        for(auto it:countNodes){
            if(ds.findpar(it.first)==it.first) cntcomp++;
        }
        return n-cntcomp;
    }
};