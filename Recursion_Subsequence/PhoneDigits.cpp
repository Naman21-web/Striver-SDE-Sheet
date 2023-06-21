void generate(int i,int N,int a[],string s,vector<string> &ans,vector<vector<char>> &mp){
        if(i==N){
            ans.push_back(s);
            return;
        }
        for(int j=0;j<mp[a[i]].size();j++){
            s += mp[a[i]][j];
            generate(i+1,N,a,s,ans,mp);
            s.pop_back();
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        vector<string> ans;
        string s;
        vector<vector<char>> mp={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};
        generate(0,N,a,s,ans,mp);
        return ans;
    }