int check(vector<int> &row,int C,int ele){
        int lo=0,hi=C-1;
        int ans=-1;
        while(lo<=hi){
            int mid= lo + (hi-lo)/2;
            if(row[mid]<=ele){
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return ans+1;;
    }
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here    
        int n = (R*C)/2;
        int median;
        int lo=1,hi=2000;
        while(lo<=hi){
            int mid= lo + (hi-lo)/2;
            int ans=0;
            //Checking no of elements less than equal to mid
            for(int i=0;i<R;i++){
                ans += check(matrix[i],C,mid);
            }
            //If no of elements less than equal to mid are greater than median index than 
            //it can be possible ans
            //and find lower no
            if(ans>=n+1){
                median = mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return median;
    }