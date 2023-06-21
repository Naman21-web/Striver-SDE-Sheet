void generate(int i,int n,int k,vector<int> &res,vector<vector<int>> &ans){
        if(k==0){
            if(n==0) ans.push_back(res);
            return;
        }
        if(i==10) return;
        if(n>=i){
            res.push_back(i);
            generate(i+1,n-i,k-1,res,ans);
            res.pop_back();
            generate(i+1,n,k,res,ans);
        }
        else return;
    }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<int> res;
        vector<vector<int>> ans;
        generate(1,N,K,res,ans);
        return ans;
    }