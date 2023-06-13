int missingNumber(int A[], int N)
{
    // Your code goes here
    int xora=A[0];
    for(int i=1;i<N-1;i++){
        xora = xora^A[i];
    }
    int x = N%4;
    
    if(x==0) return xora^N;
    if(x==1) return xora^1;
    if(x==2) return xora^N+1;
    if(x==3) return xora^0;
}