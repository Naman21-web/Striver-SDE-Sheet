int minRemoval(int N, vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(),intervals.end(),comp());
        int cnt=1;
        int end=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(end<=intervals[i][0]){
                cnt++;
                end=intervals[i][1];
            }
        }
        return intervals.size()-cnt;
    }