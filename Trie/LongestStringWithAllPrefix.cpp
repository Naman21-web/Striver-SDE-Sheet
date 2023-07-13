#include <bits/stdc++.h> 
class node{
    node* child[26];
    int prefcnt=0;
    int endwith=0;
    public:
    node(){
        for(int i=0;i<26;i++) child[i]=NULL;
    }
    bool charexist(char ch){
        return child[ch-'a']!=NULL;
    }
    node* getchar(char ch){
        return child[ch-'a'];
    }  
    void put(char ch,node* nd){
        child[ch-'a']=nd;
    }
    void incpref(){
        prefcnt++;
    }
    void decpref(){
        prefcnt--;
    }
    void incendwith(){
        endwith++;
    }
    void decendwith(){
        endwith--;
    }
    int getend(){
        return endwith;
    }
    int getprefcnt(){
        return prefcnt;
    }
};

class Trie{
    node* root;
    public:
    Trie(){
        root = new node();
    }
    void insert(string word){
        auto nod = root;
        for(auto ch:word){
            if(nod->charexist(ch)){
                nod = nod->getchar(ch);
                nod->incpref();
            }
            else{
                nod->put(ch,new node());
                nod = nod->getchar(ch);
                nod->incpref();
            }
        }
        nod->incendwith();
    }
    bool checkword(string word){
        auto it = root;
        for(auto ch:word){
            it = it->getchar(ch);
            if(it->getend()==0) return false; 
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie* trie = new Trie();
    for(auto word:a){
        trie->insert(word);
    }
    string ans="";
    for(auto word:a){
        if(trie->checkword(word)){
            if(word.size()>ans.size()) ans=word;
            else if(word.size()==ans.size()) ans = min(ans,word);
        }
    }
    if(ans=="") return "None";
    return ans;
}
