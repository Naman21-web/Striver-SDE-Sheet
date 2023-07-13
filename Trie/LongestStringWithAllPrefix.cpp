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
        auto it = root;
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
    int maxXor(int num){
        int maxSum=0;
        auto it=root;
        for(int i=31;i>=0;i--){
            int bit = (1<<i) & num;
            if(bit>0) bit=1;
            if(it->checkbit(!bit)){
                maxSum |= (1<<i);
                it = it->getbit(!bit);
            }
            else it = it->getbit(bit);
        }
        return maxSum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        int ans=0;
        for(int i=0;i<nums.size();i++){
            trie->insert(nums[i]);
            ans = max(ans,trie->maxXor(nums[i]));
        }
        return ans;
    }
};