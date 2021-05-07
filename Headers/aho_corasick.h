#ifndef FIND_SECRET_INFORMATION_AHO_CORASICK_H
#define FIND_SECRET_INFORMATION_AHO_CORASICK_H

#include "trie.h"

class AhoKorasik : private MakeTrie {
public:
    explicit AhoKorasik(const std::string& s) : MakeTrie(s) {}
    void algorithmRealization(const std::string &word);
private:
    Trie* sufLink(Trie* node);
    Trie* goTo(Trie* node, char a);
    void out(Trie* node);
    Trie* termLink(Trie* node);
};

#endif //FIND_SECRET_INFORMATION_AHO_CORASICK_H
