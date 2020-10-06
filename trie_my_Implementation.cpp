#include "solution.hpp"
using namespace std;

class Trie {
    private:
    struct trie {
        char ch;
        unordered_map<char, trie*> m;
        bool isWord;
    };

    trie* base;

    string word;

    public:
    Trie() {
        base = new trie();
        base->ch = '#';
        base->isWord = false;
    }
    trie* create(char c) {
        trie* t = new trie();
        t->ch = c;
        t->isWord = false;
        return t;
    }
    trie* insert(int i, trie* root) {
        if (i == word.size()) {
            root->isWord=true;
            return root;
        }

        if (root->m.find(word[i]) == root->m.end()) root->m[word[i]] = create(word[i]);

        
        root->m[word[i]] = insert(i + 1, root->m[word[i]]);

        return root;
    }
    void add(string s) {
        word = s;

        base = insert(0, base);
    }
    bool find(int i, trie* root) {
        if (i == word.size()) {
            return root->isWord;
        }

        if (root->m.find(word[i]) != root->m.end()) {
            return find(i + 1, root->m[word[i]]);
        }

        return false;
    }
    bool exists(string w) {
        word = w;
        return find(0, base);
    }
    bool ffind(trie* root) {
        if (root->isWord) return true;

        for (auto r : root->m) {
            if (ffind(r.second)) return true;
        }
        return false;
    }
    bool sfind(int i, trie* root) {
        if (i == word.size()) {
            
            for (auto r : root->m) {
                if (ffind(r.second)) return true;
            }

            return root->isWord;
        }

        if (root->m.find(word[i]) != root->m.end()) return sfind(i + 1, root->m[word[i]]);
        return false;
    }

    bool startswith(string p) {
        word = p;
        return sfind(0, base);
    }
};