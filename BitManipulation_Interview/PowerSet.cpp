vector<string> AllPossibleStrings(string s){
		    // Code here
		  vector<string> ans;
		  int n=s.size();
		  for(int i=1;i<(1<<(n));i++){
		      string res;
		      int x=0;
		      while(x<n){
		          if(i&(1<<x)){
		              res += s[x];
		          }
		          x++;
		      }
		      ans.push_back(res);
		  }
		  sort(ans.begin(),ans.end());
		  return ans;
		}