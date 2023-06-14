int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    // Write Your Code Here
    unordered_map<int,int> mp;
    mp[0]=1;
    int sum=0;
    int cnt=0;
    for(int i=0;i<arr.size();i++){
        sum += arr[i];
        if(mp.find(sum-k)!=mp.end()) cnt++;
        mp[sum]++;
    }
    return cnt;
}