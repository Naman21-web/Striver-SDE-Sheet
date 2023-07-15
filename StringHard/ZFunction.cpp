vector<int> calculateZ(string input){
    int sz=input.size();
    vector<int> z(sz);
    int left=0,right=0;
    z[0]=0;
    for(int k=1;k<sz;k++){
        if(k>right){
            left=right=k;
            while(right<sz && input[right]==input[right-left]) right++;
            z[k]=right-left;
            right--;
        }
        else{
            int k1=k-left;
            if(z[k1]<right-k+1) z[k]=z[k1];
            else{
                left=k;
                while(right<sz && input[right]==input[right-left]) right++;
                z[k] = right-left;
                right--;
            }
        }
    }
    return z;
}

vector<int> search(string s, string pattern) {
    // Write Your Code Here
    string newstr;
    int n=s.size();
    int m=pattern.size();
    for(int i=0;i<m;i++){
        newstr += pattern[i];
    }
    newstr += '$';
    newstr += s;
    vector<int> ans;
    vector<int> Zarray = calculateZ(newstr);
    // for(int i=0;i<n+m+1;i++) cout<<Zarray[i]<<" ";
    for(int i=0;i<n+m+1;i++){
        if(Zarray[i]==m){
            ans.push_back(i-m);
        }
    }
    return ans;
}