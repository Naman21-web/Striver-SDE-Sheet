int countBitsFlip(int a, int b){
        
        // Your logic here
        int x = a^b;
        int cnt=0;
        while(x){
            x = x&(x-1);
            cnt++;
        }
        return cnt;
    }