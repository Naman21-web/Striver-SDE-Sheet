vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[arr1[i]]++;
        }
        for(int j=0;j<m;j++){
            mp[arr2[j]]++;
        }
        for(auto x:mp){
            ans.push_back(x.first);
        }
        return ans;
    }