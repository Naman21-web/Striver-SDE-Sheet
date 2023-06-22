bool isSafe(int i,int j,vector<int> res){
        for(int k=0;k<res.size();k++){
            if(res[k]==j) return false;
            else if((res[k]+k+1) == i+j) return false;
            else if((res[k]+k+1)+2*(i-(k+1)) == i+j) return false;
        }
        return true;
        
    }
    void place(int i,int n,vector<int> &res,vector<vector<int>> &ans){
        if(i==n+1) {ans.push_back(res);return;}
        for(int j=1;j<=n;j++){
            if(isSafe(i,j,res)){
                res.push_back(j);
                place(i+1,n,res,ans);
                res.pop_back();
            }
        }
    } 
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> res;
        place(1,n,res,ans);
        return ans;
    }