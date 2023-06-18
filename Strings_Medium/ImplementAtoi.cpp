int atoi(string str) {
        //Your code here
        int ans=0;
        int ind;
        if(str[0]=='-') ind=1;
        else ind=0;
        for(int i=ind;i<str.size();i++){
            ans = ans*10;
            ans += str[i]-'0';
            // cout<<str[i]-'0'<<" ";
            
            if(str[i]-'0'>=10 || str[i]-'0'<0) return -1;
        }
        if(ind==1) ans *= -1;
        return ans;
    }