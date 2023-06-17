bool check(int mid,int A[],int N,int M){
        int ans=1,book=0;
        for(int i=0;i<N;i++){
            if(A[i]>mid) return false;
            book += A[i];
            if(book>mid){
                ans++;
                book=A[i];
            }
        }
        return (ans<=M);
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M>N) return -1;
        int lo=*min_element(A,A+N),hi=accumulate(A,A+N,0);
        int ans=0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,A,N,M)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }