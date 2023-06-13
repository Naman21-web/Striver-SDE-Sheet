int search(int A[], int N){
	    //code
	    int xora=A[0];
	    for(int i=1;i<N;i++){
	        xora = xora^A[i];
	    }
	    return xora;
	}