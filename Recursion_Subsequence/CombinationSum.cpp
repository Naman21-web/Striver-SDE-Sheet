void generate(int i,int n,vector<int> &A,int target,vector<int> s,vector<vector<int>> &ans){
        if(i==n){
            if(target==0) ans.push_back(s);
            return;
        }
        if(i!=0 && A[i]==A[i-1]){
            generate(i+1,n,A,target,s,ans);
            return;
        }
        if(A[i]<=target){
            s.push_back(A[i]);
            generate(i,n,A,target-A[i],s,ans);
            s.pop_back();
        }
        generate(i+1,n,A,target,s,ans);
    }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        int n=A.size();
        sort(A.begin(),A.end());
        vector<vector<int>> ans;
        vector<int> s;
        generate(0,n,A,B,s,ans);
        return ans;
    }