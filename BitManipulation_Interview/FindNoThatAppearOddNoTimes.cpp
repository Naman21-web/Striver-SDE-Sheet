int getOddOccurrence(int arr[], int n) {
        // code here
        int x=0;
        for(int i=0;i<n;i++){
            x = x^arr[i];
        }
        return x;
    }