void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> v;
        int col=1;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                if(matrix[i][j]==0){
                    // v.push_back({i,j});
                    if(j==0) col=0;
                    else matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<matrix.size();i++){
            if(matrix[i][0]==0){
                for(int j=0;j<matrix[i].size();j++) matrix[i][j]=0;
            }
            if(col==0) matrix[i][0]=0;
        }
        for(int j=1;j<matrix[0].size();j++){
            if(matrix[0][j]==0){
                for(int i=0;i<matrix.size();i++) matrix[i][j]=0;
            }
        }
        if(matrix[0][0]==0){
            for(int j=1;j<matrix[0].size();j++) matrix[0][j]=0;
        }
        if(col==0) matrix[0][0]=0;
        // for(int i=0;i<v.size();i++){
        //     int x = v[i].first;
        //     int y = v[i].second;
        //     for(int j=0;j<matrix[x].size();j++)
        //         matrix[x][j]=0;
        //     for(int k=0;k<matrix.size();k++)
        //         matrix[k][y]=0;
        // }
    }