class node{
    node* child[2];
    public:
    node(){
        child[0]=NULL;
        child[1]=NULL;
    }
    bool checkbit(int bit){
        return (child[bit]!=NULL);
    }
    void putbit(int bit,node* root){
        child[bit]=root;
    }
    node* getbit(int bit){
        return child[bit];
    }
};

class Trie{
    node* root;
    public:
    Trie(){
        root = new node();
    }
    void insert(int num){
        auto it=root;
        for(int i=31;i>=0;i--){
            int bit = (1<<i) & num;
            if(bit>0) bit=1;
            if(it->checkbit(bit)){
                it = it->getbit(bit);
            }
            else{
                it->putbit(bit,new node());
                it = it->getbit(bit);
            }
        }
    }
    int findmax(int num){
        auto it=root;
        int maxNum=0;
        for(int i=31;i>=0;i--){
            int bit = (1<<i) & num;
            if(bit>0) bit=1;
            if(it->checkbit(!bit)){
                maxNum |= (1<<i);
                it = it->getbit(!bit);
            }
            else it = it->getbit(bit);
        }
        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        vector<pair<int,pair<int,int>>> newarr;
        for(int i=0;i<queries.size();i++){
            newarr.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(newarr.begin(),newarr.end());
        sort(nums.begin(),nums.end());
        int j=0;
        Trie* root = new Trie();
        for(int i=0;i<newarr.size();i++){
            while(j<nums.size() && nums[j]<=newarr[i].first){
                root->insert(nums[j]);
                j++;
            }
            if(j!=0)ans[newarr[i].second.second] = root->findmax(newarr[i].second.first);
            else ans[newarr[i].second.second]=-1;
        }
        return ans;
    }
};