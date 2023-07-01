int maxChildren(int N, int M, vector<int> &greed, vector<int> &sz) {
        // code here
        sort(sz.begin(),sz.end());
        sort(greed.begin(),greed.end());
        int i=0,j=0,cnt=0;
        for(i;i<M;i++){
            while(i<M && sz[i]<greed[j]) i++;
            if(i!=M){cnt++;j++;}
            if(j==N) break;
        }
        return cnt;
    }