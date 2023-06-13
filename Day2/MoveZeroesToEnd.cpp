void pushZerosToEnd(int arr[], int n) {
	    // code here
	    int i=0;
	    for(int k=0;k<n;k++){
	        if(arr[k]!=0){
	            arr[i]=arr[k];
	            i++;
	        }
	    }
	    for(int k=i;k<n;k++) arr[k]=0;
	}