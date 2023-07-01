//we have to make grp of all decreasing no

//and then no of candy to first person in grp is max(prev+1,size of grp)
//prev+1 as no is greater than prev no so its amt of candy should be greater than
//what assigned to no before it and if size is greater than prev
//we assign size no as after that we keep on decreasing the candies amt
//as no are decreasing and last one in grp will be assigned 1 

// and to person after that is equal to cnt as all of them are
//decreasing after that in grp so they can be assigned from cnt-1 to 1

//if the no start in the new grp is same as the prev ending no then it can be
//assigned the size of grp no of candies as there is no cond for person with
//same no and we have to assign min candies which will be in case if we assign
//size of grp no candies to it
    int candy(vector<int>& ratings) {
        int n=ratings.size();
       int res=0;
       int prev=0;
       bool same=false;
        for(int i=0;i<n;i++){
            int cnt=1;
            while(i<n-1 && ratings[i+1]<ratings[i]){
                i++;
                cnt++;
            }
            long long int ans;
            if(same)ans= cnt;
            else ans=max(prev+1,cnt);
            if(cnt==1)prev = ans;
            else prev=1;
            // cout<<cnt<<ans<<prev<<" ";
            if(ans>cnt){
                res += ans;
                cnt--;
                ans=cnt;
            }
            res += ((ans)*(ans+1))/2;
            if(i<n-1 && ratings[i+1]==ratings[i]) same=true;
            else same=false;
        } 
        return res;
    }