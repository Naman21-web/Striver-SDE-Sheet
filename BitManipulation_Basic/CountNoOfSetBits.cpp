int countSetBits(int n)
    {
        // Your logic here
        //TLE soln
        // int ans=0;
        // while(n>0){
        //     int cnt=0;
        //     int x=n;
        //     while(x){
        //         x = x&(x-1);
        //         cnt++;
        //     }
        //     ans += cnt;
        //     n--;
        // }
        // return ans;
        
        
        //Better soln
        n++;
        int ans=0;
        int x=1;
        while(x<n){
            int pairs = n/x;//Total no of pairs of 0s and 1s
            //pairs/2 because in pairs half even half odd
            ans += (pairs/2)*x;//Total no of 1s
            //if pairs odd that means when pairs/2 at last remainders are all 1s
            //as 1st 0 come then 1 then 0 and so on
            //so whenever pairs are odd 1s are left in remainder
            //and whenever pairs are even 0s are left in remainder
            //Ex- 000011110000111 this is sequence of 3rd bit(i.e.,4) for 14
            //so first we do 14+1=15 because in it 0 is also considered
            //when 15/4 pairs=3 which is odd
            //that means the remainder bits are 1 as we can see at last 3 1s are left
            //so we add it if pairs are odd
            //Ex- 0000111100 this is sequence of 3rd bit(i.e.,4) for 9
            //so first we do 9+1=10 because in it 0 is also considered
            //when 10/4 pairs=2 which is even
            //that means the remainder bits are 0 as we can see at last 2 0s are left
            //so we dont add remainder if pairs are even
            if(pairs%2==1) ans += n%x;//so adding that 1s
            x = x*2;
        }
        return ans;
    }