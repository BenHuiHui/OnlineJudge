//
//  P208_ImplementTrie.cpp
//  CppPlayground
//
//  Created by Hui Hui on 15/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

/*
 Needs to take care of syntax here
 */

#include <string>
#include <vector>
using namespace std;

class TrieNode {
    
    friend class Trie;
    
public:
    // Initialize your data structure here.
    TrieNode() {
        hasValue = false;
        for (int i=0; i<26; i++) {
            children.push_back(nullptr);
        }
    }
    
private:
    bool hasValue;
    vector<TrieNode *>children;
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
        return node!=nullptr && node->hasValue;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *node = search(root, prefix, 0);
        
        if (node == nullptr) {
            return false;
        }
        
        if (node->hasValue) {
            return true;
        }
        
        for (int i=0; i<26; i++) {
            if (node->children[i] != nullptr) {
                return true;
            }
        }
        
        return false;
    }
    
    TrieNode *search(TrieNode *node, string word, int index){
        
        if (node == nullptr) {
            return nullptr;
        }
        
        if (word.length() == index) {
            return node;
        }
        
        int num = word[index] - 'a';
        
        return search(node->children[num], word, index+1);
    }
    
private:
    
    TrieNode* root;
};