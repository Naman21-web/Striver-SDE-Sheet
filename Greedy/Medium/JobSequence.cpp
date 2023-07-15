/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/
struct comp{
    bool operator()(const Job &a,Job &b){
        return a.profit>b.profit;
    }
};

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp());
        unordered_map<int,int> mp;
        int cnt=1;
        int totalprofit=arr[0].profit;
        mp[arr[0].dead]=1;
        // int deadline=2;
        for(int i=1;i<n;i++){
            int deadline=arr[i].dead;
            while(mp.find(deadline)!=mp.end()) deadline--;
            if(deadline!=0){
                mp[deadline]++;
                cnt++;
                totalprofit += arr[i].profit;
            }
        }
        return {cnt,totalprofit};
    } 
};