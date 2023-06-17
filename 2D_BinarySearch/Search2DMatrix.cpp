bool searchMatrix(vector<vector<int>>& mat, int X) {
        // int x = matrix[0].size()-1;
        // int y=-1;
        // if(target<=matrix[0][x] || matrix.size()==1){
        //     y=0;
        // }
        // else{
        // for(int i=1;i<matrix.size();i++){
        //     if(target<=matrix[i][x] && target>matrix[i-1][x]){
        //         y=i;
        //         break;
        //     }
        // }
        // }
        // if(y==-1)
        //     return false;
        // for(int i=0;i<matrix[y].size();i++){
        //     if(target == matrix[y][i])
        //         return true;
        // }
        // return false;
//                 int rows = matrix.size(),
// 			cols = matrix[0].size(),
//             row = 0, col = cols - 1;
			
//         while (row < rows && col > -1) {
//             int cur = matrix[row][col];
//             if (cur == target) return true;
//             if (target > cur) row++;
//             else col--;
//         }
        
//         return false;
        //int x=matrix[0].size()-1;
        // int i=0;
        if(X<mat[0][0]){
            return false;
        }
        // else{
        // while(target>=matrix[i][0]  && i<matrix.size()){
        //     i++;
        // }
        // i--;
        // for(int j=0;j<matrix[i].size();j++){
        //     if(matrix[i][j]==target)
        //         return true;
        // }
        // }
        // return false;
        int N=mat.size(),M=mat[0].size();
        int lo=0,hi=N-1;
	    int ans=0;
	    while(lo<=hi){
	        int mid = lo + (hi-lo)/2;
	        if(mat[mid][0]<=X && mat[mid][M-1]>=X){
	            ans=mid;
	            break;
	        }
	        else if(mat[mid][0]>X) hi=mid-1;
	        else lo=mid+1;
	    }
	    lo=0,hi=M-1;
	    while(lo<=hi){
	        int mid = lo + (hi-lo)/2;
	        if(mat[ans][mid]==X) return 1;
	        else if(mat[ans][mid]<X) lo=mid+1;
	        else hi=mid-1;
	    }
	    return 0;
    }