class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        if(intervals.size()==0) {
            v.push_back(newInterval);
             return v;
            }
        int x = newInterval[0];
        int mini=x;
        int y = newInterval[1];
        int maxi=y;
        int n =intervals.size();
        if(y<intervals[0][0]){
             v.push_back(newInterval);     
        }  
        for(int i=0;i<n;i++){
            if(intervals[i][1]<mini) v.push_back(intervals[i]);
            else if(i>0 && intervals[i-1][1]<mini && intervals[i][0]>maxi) {
                v.push_back(newInterval);
                v.push_back(intervals[i]);
            }
            else if(intervals[i][0]>maxi) v.push_back(intervals[i]);
            else{
                while(i<n && intervals[i][0]<=maxi){
                    mini = min(mini,intervals[i][0]);
                    maxi = max(maxi,intervals[i][1]);
                    i++;
                }
                v.push_back({mini,maxi});
                i--;
            }
        }
        if(x>intervals[n-1][1]){
            v.push_back(newInterval);
        }
        return v;
    }
};