void rearrange(int arr[], int n) {
	    // code here
	    int arr1[n];
	    for(int i=0;i<n;i++){
	        arr1[i]=arr[i];
	    }
	    int j=0,k=1;
	    for(int i=0;i<n;i++){
	        if(arr1[i]>=0){
	            arr[j]=arr1[i];
	            j+=2;
	        }
	        else{
	            arr[k]=arr1[i];
	            k += 2;
	        }
	    }
	}