class disjointset{
    vector<int> parent,rank,size;
    public:
    disjointset(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        rank.resize(n+1,1);
        for(int i=0;i<=n;i++) parent[i]=i;
    }
    int findpar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findpar(parent[node]);//path compression
    }
    void unionBySize(int u,int v){
        int ulp_u = findpar(u);
        int ulp_v = findpar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

/*Complete the functions below*/
int find(int A[],int X)
{
       //add code here
       if(A[X]==X) return X;
       return A[X] = find(A,A[X]);
}
void unionSet(int A[],int X,int Z)
{
	//add code here.
	while(A[X]!=X) X=A[X];
	while(A[Z]!=Z) Z=A[Z];
	if(X==Z) return;
	A[X]=Z;
}