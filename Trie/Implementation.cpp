#include<bits/stdc++.h>
using namespace std;
class Trie {

private:

struct TrieNode{
    struct TrieNode *child[26];
    bool isEnd;
};
TrieNode* node;
public:

Trie() {
    node=new TrieNode();
}

void insert(string word) {
    TrieNode* cur=node;
    for(char c: word){
        if(cur->child[c-'a']==NULL) cur->child[c-'a']=new TrieNode();
        cur=cur->child[c-'a'];
    }
    cur->isEnd=true;
}
class Trie
{
    public:
    class Trienode{
        Trienode* child[26];
        bool isEnd;
    };
    Trienode* node;
    
    Trie()
    {
        node=new Trienode();
    }
    void insert(string word)
    {
        Trienode* curr=node;
        for(auto c:word)
        {
            if(curr->child[c-'a']==NULL) curr->child[c-'a']=new Trienode();
        }
    }


};


int main()
{
    return 0;
}