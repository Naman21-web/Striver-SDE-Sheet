bool palindrome(int i,int j,string &str){
        while(i<=j){
            if(str[i]==str[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    int partition(int i,string str,int n){
        if(i==n) return 0;
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            if(palindrome(i,j,str)){
                mini = min(mini,1+partition(j+1,str,n));
            }
        }
        return  mini;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n=str.size();
        return partition(0,str,n)-1;
    }