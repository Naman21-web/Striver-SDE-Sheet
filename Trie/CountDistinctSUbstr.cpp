class node{
    node* child[26];
    bool endwith;
    public:
    bool check(char ch){
        return (node->child[ch-'a']!=NULL);
    }
    void putnode(char ch,node* root){
        node->child[ch-'a']=root;
    }
    node* getnode(char ch){
        return node->child[ch-'a'];
    }
};

int countDistinctSubstrings(string &s)
{
    //    Write your code here.
    int n=s.size();
    int cnt=0;
    for(int i=0;i<n;i++){
        node* root=new node();
        for(int j=i;j<n;j++){
            if(!root.check(ch)){
                root->putnode(ch,new node());
                root = root->getnode(ch);
                cnt++;
            }
            else root = root->getnode(ch);
        }
    }
    return cnt;
}