int majorityElement(int a[], int size)
    {
        
        // your code here
        int no=a[0],cnt=1;
        for(int i=1;i<size;i++){
            if(cnt==0){
                no=a[i];
                cnt=1;
            }
            else if(a[i]==no) cnt++;
            else cnt--;
        }
        cnt=0;
        for(int i=0;i<size;i++){
            if(a[i]==no) cnt++;
        }
        if(cnt>(size/2)) return no;
        return -1;
    }