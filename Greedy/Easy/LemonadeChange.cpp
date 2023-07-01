bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int five=0,ten=0,twenty=0;
        if(bills[0]!=5) return false;
        for(int i=0;i<N;i++){
            if(bills[i]==5) five++;
            else if(bills[i]==10){
                if(five==0) return false;
                five--;
                ten++;
            }
            else{
                if(five==0 || (ten==0 && five<3)) return false;
                five--;
                if(ten==0) five -= 2;
                else ten--;
                twenty++;
            }
        }
        return true;
    }