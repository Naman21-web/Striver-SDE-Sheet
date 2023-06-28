vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<N;i++){
            pq.push({arr[i],i});
        }
        int i=1;
        int prevtop=-1;
        while(!pq.empty()){
            int currtop=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            if(currtop==prevtop)i--;
            arr[index]=i;
            i++;
            prevtop=currtop;
        }
        return arr;
    }