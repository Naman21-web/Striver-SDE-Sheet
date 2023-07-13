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

TrieNode* trie = new TrieNode();
TrieNode* solution::deleteWord(TrieNode* root, string word) {
  // Write your code here
  auto it = trie;
  for(auto c:word){
    if(it->children[c-'a']==NULL) return false;
    it = it->children[c-'a'];
  }
  it->isEnd=false;
  return trie;
  // for(auto node:it->children){
  //   if(it->children!=NULL) return trie;
  // }
}

