//
//  P211_AddAndSearchWord.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <string>
#include <iostream>

using namespace std;

class TrieNode {
    
public:
    // Initialize your data structure here.
    TrieNode() {
        hasValue = false;
        for (int i=0; i<26; i++) {
            children[i] = NULL;
        }
    }
    
    bool hasValue;
    TrieNode* children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        root = insert(root, word, 0);
    }
    
    TrieNode* insert(TrieNode *node, string word, int index){
        
        if (node == nullptr) {
            node = new TrieNode();
        }
        
        if (index == word.length()) {
            node->hasValue = true;
        }
        else{
            
            int num = word[index] - 'a';
            node->children[num] = insert(node->children[num], word, index+1);
        }
        
        return node;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *node = search(root, word, 0);
        return node!=nullptr;
    }
    
    
    TrieNode *search(TrieNode *node, string word, int index){
        
        if (node == nullptr) {
            return nullptr;
        }
        
        if (word.length() == index) {
            if (node->hasValue) {
                return node;
            }
            return nullptr;
        }
        
        
        if (word[index] == '.') {
            TrieNode *newNode = nullptr;
            
            for (int i=0; i<26; i++) {
                newNode = search(node->children[i], word, index+1);
                
                if (newNode != nullptr) {
                    return newNode;
                }
            }
            
            return newNode;
        }
        else{
            
            int num = word[index] - 'a';
            
            return search(node->children[num], word, index+1);
        }
    }
    
private:
    
    TrieNode* root;
};


class WordDictionary {
public:
    
    WordDictionary(){
        trie = new Trie();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        trie->insert(word);
    }
    
    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return trie->search(word);
    }
    
    Trie *trie;
};



int main(int argc, char* argv[]){
    
    WordDictionary d;
    d.addWord("a");
    cout << d.search(".");
    
    return 0;
}