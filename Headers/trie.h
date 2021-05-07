#ifndef FIND_SECRET_INFORMATION_TRIE_H
#define FIND_SECRET_INFORMATION_TRIE_H

#include <string>
#include <unordered_map>

struct Trie {
    bool terminalVertex;
    std::unordered_map<char, Trie*> map;
    Trie* parent;
    char symbol;
    Trie* sufLinkCache;
    Trie* termLinkCache;
    std::string word;
};

class MakeTrie {
public:
    MakeTrie(const std::string& s); // создает бор по пришедшей строке
    Trie* root;

private:
    void insert(const std::string& s);
    Trie* getNewTrieNode();
};

#endif //FIND_SECRET_INFORMATION_TRIE_H
