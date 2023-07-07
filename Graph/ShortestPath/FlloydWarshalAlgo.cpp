void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size(),m=matrix[0].size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(matrix[i][j]==-1) matrix[i][j]=1e9;
	            if(i==j) matrix[i][j]=0;
	        }
	    }
	    for(int via=0;via<n;via++){
	        for(int row=0;row<n;row++){
	            for(int col=0;col<m;col++){
	                if(matrix[row][col]>matrix[row][via]+matrix[via][col]){
	                    matrix[row][col]=matrix[row][via]+matrix[via][col];
	                }
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(matrix[i][j]==1e9) matrix[i][j]=-1;
	        }
	    }
	}