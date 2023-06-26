vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector<int> ans;
        for(int i=0;i<queries;i++){
            int cnt=0;
            for(int j=indices[i]+1;j<n;j++){
                if(arr[j]>arr[indices[i]]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }