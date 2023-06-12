 int minJumps(int a[], int n){
        // Your code here
        int j=0;
        int maxj=0;
        int curr=0;
        for(int i=0;i<n-1;i++)
        {
            // i se current k beech m max kha jump kr skte
            maxj=max(maxj,(a[i]+i));
            if(curr==i)
            {
                if(curr==maxj)
                return -1;
                //agar curr p pahoch gye to curr ko maxk kar do aur ab nya maxj dhumdo i=curr tk
                curr=maxj;
                j++;
            }
        }
          return j; 
        
    }