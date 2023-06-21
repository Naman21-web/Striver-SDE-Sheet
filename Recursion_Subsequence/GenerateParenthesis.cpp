void generate(int close,int open,string s,vector<string> &ans){
        if(close<open) return;
        if(close==0){
            ans.push_back(s);
            return;
        }
        // naman kyu sochta dinbhar? band kar.......
       if(open!=0){ s += '(';
        generate(close,open-1,s,ans);
        s.pop_back();}
        s += ')';
        generate(close-1,open,s,ans);
        s.pop_back();
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        string s = "(";
        vector<string> ans;
        generate(n,n-1,s,ans);
        return ans;
    }