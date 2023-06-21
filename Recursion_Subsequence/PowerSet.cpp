void generate(int i,string &s,string &str,int n,vector<string> &ans){
	        if(i==n){
	            if(str!="") ans.push_back(str);
	            return;
	        }
	        str += s[i];
	        generate(i+1,s,str,n,ans);
	        str.pop_back();
	        generate(i+1,s,str,n,ans);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n=s.size();
		    string str="";
		    vector<string> ans;
		    generate(0,s,str,n,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}