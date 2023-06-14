void sort012(int a[], int n)
    {
        // code here 
        int i=0,k=n-1,j=0;
        while(k>=i){
            if(a[i]==0){
                swap(a[i],a[j]);
                i++;j++;
            }
            else if(a[i]==2){
                swap(a[i],a[k]);
                k--;
            }
            else i++;
        }
    }