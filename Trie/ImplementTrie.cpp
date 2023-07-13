#include <bits/stdc++.h> 

/*class TrieNode {                        //Definition of TrieNode class
public:
    TrieNode * children[26];
    bool isEnd;
    TrieNode()
    {
        isEnd=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
    
};*/

//To insert a word into the Trie
TrieNode* trie = new TrieNode();
void solution::insert(string word) {
	
	//Write your code here
    auto it = trie;
    for(auto c:word){
        if(it->children[c-'a']!=NULL) it = it->children[c-'a'];
        else{
            it->children[c-'a'] = new TrieNode();
            it = it->children[c-'a'];
        }
    }                
    it->isEnd=true;
}

//Returns if the word is present in the Trie
bool solution::search(string word){
   
   //Write your code here
   auto it = trie;
   for(auto c:word){
       if(it->children[c-'a']!=NULL) it = it->children[c-'a'];
       else return false;
   }
    return it->isEnd;
}   
