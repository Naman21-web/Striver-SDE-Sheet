int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {

        //By FloydWarshal Algo
        // vector<vector<int>> adj(n,vector<int> (n,1e9));
        // for(int i=0;i<m;i++){
          
        //     adj[edges[i][0]][edges[i][1]]=edges[i][2];
        //     adj[edges[i][1]][edges[i][0]]=edges[i][2];
        // }
        // for(int i=0;i<n;i++) adj[i][i]=0;
        // for(int via=0;via<n;via++){
        //     for(int row=0;row<n;row++){
        //         for(int col=0;col<n;col++){
        //             adj[row][col] = min(adj[row][col],adj[row][via]+adj[via][col]);
        //         }
        //     }
        // }
        // int city=-1,cntmin=INT_MAX;
        // for(int i=0;i<n;i++){
        //     int cnt=0;
        //     for(int j=0;j<n;j++){
        //         if(adj[i][j]<=distanceThreshold) cnt++;
        //     }
        //     if(cnt<=cntmin){
        //         cntmin=cnt;
        //         city=i;
        //     }
        // }
        // return city;
        

        //By djikstra's Algo
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        int city=-1,cntMin=n;
        for(int i=0;i<n;i++){
            vector<int> dist(n,1e9);
            dist[i]=0;
            set<pair<int,int>> st;
            st.insert({0,i});
            while(!st.empty()){
                auto x=*st.begin();
                int distance=x.first;
                int node=x.second;
                st.erase(x);
                for(auto it:adj[node]){
                    if(dist[it.first]>distance+it.second){
                        st.erase({dist[it.first],it.first});
                        dist[it.first]=distance+it.second;
                        st.insert({dist[it.first],it.first});
                    }
                }
            }
            int  cnt=0;
            for(int i=0;i<n;i++){
                if(dist[i]<=distanceThreshold) cnt++;
            }
            if(cnt<=cntMin){
                cntMin=cnt;
                city=i;
            }
        }
        return city;
    }