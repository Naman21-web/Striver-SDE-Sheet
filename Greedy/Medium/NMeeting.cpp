struct cmp{
    bool operator()(const vector<int>&a,const vector<int>&b) {
    // 	if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
};
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    // struct meeting{
    //   int start;
    //   int end;
    //   int pos;
    // };
    // bool comparator(struct meeting m1,meeting m2){
    //     if(m1.end < m2.end) return true;
    //     else if(m1.end>m2.end) return false;
    //     else if(m1.pos<m2.pos) return true;
    //     return false;
    // }
    // auto comp = [](const vector<int>&a,const vector<int>&b){
    //         if(a[1]==b[1]) return a[0]>b[0];
    //         return a[1]>b[1];
    //     }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        // struct meeting meet[n];
        // for(int i=0;i<n;i++){
        //     meet[i].start=start[i];
        //     meet[i].end=end[i];
        //     meet[i].pos=i+1;
        // }
        // sort(meet,meet+n,comparator);
        // vector<int> ans;
        // int limit=meet[0].end;
        // int cnt=1;
        // for(int i=0;i<n;i++){
        //     if(meet[i].start>limit){
        //         limit=meet[i].end;
        //         cnt++;
        //     }
        // }
        // return cnt;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            ans.push_back({start[i],end[i]});
        }
        sort(ans.begin(),ans.end(),cmp());
        int en=ans[0][1];
        int cnt=1;
        for(int i=1;i<n;i++){
            // cout<<ans[i][1]<<" ";
            if(ans[i][0]>en){
                cnt++;
                en=ans[i][1];
            }
        }
        return cnt;
    }
};