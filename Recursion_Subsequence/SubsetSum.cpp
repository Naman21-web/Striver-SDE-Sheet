void func(int i,int sum,vector<int> &v,vector<int> &arr,int n){
        if(i==n){
            v.push_back(sum);
            return;
        }
        func(i+1,sum+arr[i],v,arr,n);
        func(i+1,sum,v,arr,n);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> v;
        func(0,0,v,arr,N);
        return v;
    }