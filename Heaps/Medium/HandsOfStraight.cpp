class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        map<int,int> mp;
        if(n%groupSize!=0) return 0;
        for(int i=0;i<n;i++) mp[hand[i]]++;
        for(auto x:mp){
            int y = x.second;
            if(y==0) continue;
            while(y--){
                int no=x.first;
                int size=groupSize-1;
                int add=1;
                while(size--){
                    if(mp[no+add]==0)return 0;
                    else{
                        mp[no+add]--;
                        add++;
                    }
                }
            }
        }
        return true;
    }
};