int canReach(int A[], int N) {
        // code here
        // int maxi=A[0];
        // int maxIdx=0;
        // int i=1;
        // while(true){
        //     if(maxIdx+maxi>=N-1) return 1;
        //     int x=maxi,y=maxIdx;
        //     // cout<<maxIdx<<maxi<<" ";
        //     maxi=0;
        //     // cout<<maxIdx<<maxi;
        //     while(i<=x+y) {
        //         // cout<<A[i]<<" ";
        //         if(A[i]>=maxi){
        //             maxi=A[i];
        //             maxIdx=i;
        //         }
        //         i++;
        //     }
        //     // cout<<maxIdx<<maxi<<" ";
        //     if(maxi==0) return 0;
        // }
        // return true;
        
        int j=0;
        int maxj=0;
        int curr=0;
        for(int i=0;i<N-1;i++)
        {
            // i se current k beech m max kha jump kr skte
            maxj=max(maxj,(A[i]+i));
            if(curr==i)
            {
                if(curr==maxj)
                return 0;
                //agar curr p pahoch gye to curr ko maxk kar do aur ab nya maxj dhumdo i=curr tk
                curr=maxj;
                j++;
            }
        }
          return 1;
    }