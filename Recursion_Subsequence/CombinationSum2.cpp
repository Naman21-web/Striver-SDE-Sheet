void generate(int i,int n,vector<int> &candidates,int target,vector<int> &res,vector<vector<int>> &ans){
            if(target==0){
                ans.push_back(res);
                return;
            }
        for(int j=i;j<n;j++){
            if(j!=i && candidates[j]==candidates[j-1]) continue;
            if(target>=candidates[j]){
                res.push_back(candidates[j]);
                generate(j+1,n,candidates,target-candidates[j],res,ans);
                res.pop_back();
            }
            else break;
            // generate(j+1,n,candidates,target,res,ans);
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> res;
        generate(0,n,candidates,target,res,ans);
        return ans;
    }