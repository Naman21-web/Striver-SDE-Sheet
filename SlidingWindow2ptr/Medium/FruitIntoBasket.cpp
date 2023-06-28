int totalFruits(int n, vector<int> &fruits) {
        int ans=0;
        int start=1,end=0;
        int fruit1=fruits[0],cnt1=1,fruit2,cnt2=1;
        while(start<n && fruits[start]==fruit1){cnt1++; start++;}
        if(start==n) return n;
        fruit2=fruits[start];
        start++;
        while(start<n){
            if(fruits[start]==fruit1){
                start++;cnt1++;
            }
            else if(fruits[start]==fruit2){
                start++;cnt2++;
            }
            else{
                while(cnt1!=0 && cnt2!=0){
                    ans=max(ans,start-end);
                    if(fruits[end]==fruit1) cnt1--;
                    else cnt2--;
                    end++;
                }
                if(cnt1==0) {fruit1=fruits[start]; start++;cnt1=1;}
                else {fruit2=fruits[start]; start++;cnt2=1;}
            }
        }
        return max(ans,start-end);
    }