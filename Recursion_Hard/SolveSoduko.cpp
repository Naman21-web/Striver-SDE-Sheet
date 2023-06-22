bool isSafe(int i,int j,int no,int grid[N][N]){
        for(int k=0;k<N;k++) {
            if(grid[i][k]==no) return false;
            if(grid[k][j]==no) return false;
            if(grid[(k/3)+((i/3)*3)][((j/3)*3)+(k%3)]==no) return false;
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool solve(int grid[N][N]){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j]==0){
                    for(int k=1;k<10;k++){
                        if(isSafe(i,j,k,grid)){
                            grid[i][j]=k;
                            if(solve(grid)) return true;
                            grid[i][j]=0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        return solve(grid);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }