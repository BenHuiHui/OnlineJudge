//
//  P212_WordSearchII.cpp
//  CppPlayground
//
//  Created by Hui Hui on 11/2/16.
//  Copyright © 2016 Hui Hui. All rights reserved.
//

#include <vector>
#include <string>
#include <unordered_set>

/*
 Improved version: insert target word!!!!
 Early stop: prefix
 */

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

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>sln;
        
        Trie trie;
        vector<vector<bool>>used;
        
        for (int i=0; i<words.size(); i++) {
            trie.insert(words[i]);
        }
        
        for (int i=0; i<board.size(); i++) {
            used.push_back(vector<bool>(board[0].size(), false));
        }
        
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                searchTrie(trie, board, used, i, j, "", sln);
            }
        }
        
        
        //Remove duplicates
        vector<string>unique;
        unordered_set<string>contains;
        
        for (string word : sln) {
            if (contains.find(word) == contains.end()) {
                unique.push_back(word);
                contains.insert(word);
            }
        }
        
        return unique;
    }
    
    void searchTrie(Trie& trie, vector<vector<char>>& board, vector<vector<bool>>&used, int row, int col, string word, vector<string>&sln){
        
        if (row < 0 || row >= board.size() || col<0 || col>=board[0].size()) {
            return;
        }
        
        if (used[row][col]) {
            return;
        }
        
        int rowI[4] = {1, -1, 0, 0};
        int colI[4] = {0, 0, 1, -1};
        
        string newWord = word+board[row][col];
        
        if (trie.search(newWord)) {
            sln.push_back(newWord);
        }
        
        if (!trie.startsWith(newWord)) {
            return;
        }
        
        //trie.insert(newWord);
        used[row][col] = true;

        for (int i=0; i<4; i++) {
            searchTrie(trie, board, used, row+rowI[i], col+colI[i], newWord, sln);
        }
        
        used[row][col] = false;
    }
};

int main(int argc, char *argv[]){
    
    Solution sln;
    
    
    
    
}