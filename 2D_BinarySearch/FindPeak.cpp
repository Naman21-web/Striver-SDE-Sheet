    bool check(int i,int mid,int n,int m,vector<vector<int>> &mat){
        // if(mid!=0 && mat[i][mid]<mat[i][mid-1]) return false;
        // if(mid!=m-1 && mat[i][mid]<mat[i][mid+1]) return false;
        if(i!=0 && mat[i][mid]<mat[i-1][mid]) return false;
        if(i!=n-1 && mat[i][mid]<mat[i+1][mid]) return false;
        return true;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        int lo=0,hi=n-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int ind=0,maxi=0;
            for(int j=0;j<m;j++){
                if(mat[mid][j]>maxi){
                    maxi=mat[mid][j];
                    ind=j;
                }
            }
            if(check(mid,ind,n,m,mat)) return {mid,ind};
            else if(mid!=0 && mat[mid][ind]<mat[mid-1][ind]) hi=mid-1;
            else lo=mid+1;
        }        
        return {-1,-1};
    }