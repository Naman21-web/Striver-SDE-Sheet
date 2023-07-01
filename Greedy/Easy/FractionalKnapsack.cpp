double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<n;i++){
            double valperunit = (double)arr[i].value/arr[i].weight;
            pq.push({valperunit,arr[i].weight});
        }
        double ans=0;
        while(!pq.empty() && W){
            double valperunit=pq.top().first;
            int weight=pq.top().second;
            pq.pop();
            // cout<<W<<" ";
            if(weight<=W) {ans += weight*valperunit;W -= weight;}
            else{
                ans += W*valperunit;
                W=0;
            }
        }
        return ans;
    }