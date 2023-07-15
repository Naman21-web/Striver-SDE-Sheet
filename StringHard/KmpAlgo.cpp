class Solution {
public:
    // lps[i] tells us the max value for which prefix from post 0 to len match to suff from pos n-len-1 to n;
    // Ex- abaaba
    // for lps[0] is always 0 as no proper prefix exist for it
    // proper prefix = all prefix with size less than size of string 

    // lps[1]
    //  proper prefix = 'a'
    // suffix = 'b','ab'
    // suffix and prefix dont match
    // so lps[1]=0

    // lps[2]
    // proper prefix = 'a' 'ab'
    // suffix = 'a' 'ba' 'aba'
    // since 'a' is the lasrgest match bw pref and suff
    // so lps[2]=1

    // lps[3]
    // proper prefix = 'a' 'ab' 'aba'
    // suffix = 'a' 'aa' 'baa' 'abaa
    // so lps[3]=1
    
    // lps[4]
    // proper prefix = 'a' 'ab' 'aba' 'abaa'
    // suffix = 'b' 'ab' 'aab' 'baab' 'abaab'
    // ab greates match
    // so lps[4]=2

    //lps[5]
    // proper prefix = 'a' 'ab' 'aba' 'abaa' 'abaab'
    //suffix = 'a' 'ba' 'aba' 'aaba' 'baaba' 'abaaba'
    // aba gratest match
    //so lps[5]=3
    vector<int> findlps(string needle){
        int n=needle.size();
        vector<int> lps(n);
        lps[0]=0;
        int i=1,len=0;
        while(i<n){
            if(needle[i]==needle[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len==0){
                    lps[i]=len;
                    i++;
                }
                else{
                    len = lps[len-1];
                }
            }
        }
        return lps;
    }
    // lps[i] tells longest prefix that matches with suffix
    // so when characters dont match we go lps[i] character because before that character there is match needle and haystick
    // ex - haystick = 'ababcababaad'
    // needle = 'ababa'
    // lps = {0,0,1,2,3}

    // so till i=3, abab = abab
    // now at j=4, needle[j]=c and haystick[i]=c they dont match
    // so we move j = lps[j-1] = lps[4-1]=lps[3]=2
    // which means first 2 character of needle match with last 2 char of needle
    // and since we move till j=4 that means first 4 char of haystick and needle are same
    // so first 2 char of haystick wll also match from first 2 char of needle since string is same till j=3
    // So now we need to check match from 3rd char of needle to ith char of haystick as first 2 char of needle matches with haystick so no need to check it
    // if they match we move i and j
    // and if they dont match we move j again to lps[j-1]=lps[2-1]=lps[1]=0
    // so we check 0th char of needle with ith char of haystick
    // if they dont match so we simply move i as j is 0 now no further matching can be done
    // If we reach m at any point of time then that means whole needle string matches so we return starting index that is i-m
    int strStr(string haystick, string needle) {
        vector<int> lps = findlps(needle);
        int n=haystick.size(),m=needle.size();
        int i=0,j=0;
        while(i<n){
            if(haystick[i]==needle[j]){
                i++;
                j++;
                if(j==m){
                    return i-m;
                }
            }
            else if(i<n && haystick[i]!=needle[j]){
                if(j==0) i++;
                else j=lps[j-1];
            }
        }
        return -1;
    }
};