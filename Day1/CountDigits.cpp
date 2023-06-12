int evenlyDivides(int N){
        //code here
        int x = N,cnt=0;
        while(x){
            int y = x%10;
            if(y!=0 && N%y==0) cnt++;
            x = x/10;
        }
        return cnt;
    }