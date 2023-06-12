string armstrongNumber(int n){
        // code here
        int x=n;
        int ans=0;
        while(x){
            int dig=x%10;
            ans += dig*dig*dig;
            x = x/10;
        }
        if(ans==n) return "Yes";
        return "No";
    }