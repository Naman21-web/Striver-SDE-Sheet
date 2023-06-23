vector<int>AllPrimeFactors(int N) {
	    // Code here
	    vector<int> vis(N+1,0);
	    vector<int>ans;
	    for(int i=2;i*i<=N;i++){
	        if(!vis[i]){
	           // if(N%i==0) ans.push_back(i);
	           // vis[i]=1;
	            for(int j=i*i;j<=N;j+=i){
	                vis[j]=1;
	            }
	        }
	    }
	    for(int j=2;j<=N;j++){
	        if(vis[j]==0 && N%j==0) ans.push_back(j); 
	    }
	    return ans;
	}