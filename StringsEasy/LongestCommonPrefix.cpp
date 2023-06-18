string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        sort(arr,arr+N);
        string first=arr[0];
        string last=arr[N-1];
        // for(int i=1;i<N;i++){
        //     int j=0;
        //     while(arr[i][j]==ans[j]) {j++;}
            
        //     while(j<ans.size()){
        //         ans.pop_back();
        //         j++;
        //     }
        // }
        string ans;
        for(int i=0;i<first.size();i++){
            if(first[i]==last[i]) ans += first[i];
            else break;
        }
        if(ans.size()==0) return "-1";
        return ans;
    }