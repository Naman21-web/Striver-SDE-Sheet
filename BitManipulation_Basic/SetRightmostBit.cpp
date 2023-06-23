int setBit(int N)
    {
        // Write Your Code here
        int i=0;
        while((1<<i)<N){
            if((N&(1<<i))==0){
                N = N | (1<<i);
                break;
            }
            i++;
        }
        return N;
    }