int recurse(int i,string str,int no,int n){
        if(i==n) return no;
        if((str[i]-'0')<0 || (str[i]-'0')>=10) return -1;
        no = (no*10)+(str[i]-'0');
        return recurse(i+1,str,no,n);
    }
    int atoi(string str) {
        //Your code here
        int n=str.size();
        if(str[0]=='-') {
            int no=recurse(1,str,0,n);
            if(no==-1) return -1;
            return -no;
        }
        return recurse(0,str,0,n);
    }