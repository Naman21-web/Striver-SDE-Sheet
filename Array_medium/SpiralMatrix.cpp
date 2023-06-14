int findK(vector<vector<int>> &matrix, int n, int m, int k)
    {
        // Your code goes here
        int left=0,right=m-1,top=0,bottom=n-1;
        int ele=0;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                ele++;
                if(ele==k) return matrix[top][i];
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ele++;
                if(ele==k) return matrix[i][right];
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ele++;
                    if(ele==k) return matrix[bottom][i];
                }
                bottom--;
            } 
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ele++;
                    if(ele==k) return matrix[i][left];
                }
                left++;
            }
        }
        return 0;
    }