#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Trie{
    
    public:
        Trie *child[26];
        bool isEnd;

        Trie(){
          for(int i = 0; i < 26; i++){
                this->child[i] = NULL;
            }
            this->isEnd = false;
        }

        void insert(string s){
            Trie *node = this;
            for(int i = 0; i < s.size(); i++){
                int index = s[i] - 'a';
                if(!node->child[index])
                    node->child[index] = new Trie();
                node = node->child[index];
            }
            node->isEnd = true; 
        }
        
        bool search(string s){
            Trie *node = this;
            for(int i = 0; i < s.size(); i++){
                int index = s[i]-'a';
                if(!node->child[index])
                    return false;
                node = node->child[index];     
            }
            return node->isEnd;
        }
};

int main(){
    Trie *root = new Trie();
    root->insert("krishna");
    cout<<"key found = "<<root->search("krishn");
    return 0; 
}