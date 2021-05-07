#include "../Headers/trie.h"
#include <vector>

const int Kb4 = 4 * 1024;

MakeTrie::MakeTrie(const std::string& s) {
    std::vector<std::string> parsedLine;
    int pos = 0;
    while (pos + Kb4 < s.length()) {
        parsedLine.push_back(s.substr(pos, Kb4));
        pos++;
    }
    if (parsedLine.empty()) {
        perror("too small file");
    }
    root = getNewTrieNode();
    for (int i = 0; i < parsedLine.size(); i++) {
        insert(parsedLine[i]);
    }
}

void MakeTrie::insert(const std::string& s) {
    Trie* node = root;
    for (int i = 0; i < s.length(); i++) {
        char x = s[i];
        if (node->map.find(x) == node->map.end()) {
            node->map[x] = getNewTrieNode();
            node->map[x]->parent = node;
            node->map[x]->symbol = x;
        }

        node = node->map[x];
    }

    node->terminalVertex = true;
    node->word = s;
}

Trie* MakeTrie::getNewTrieNode() {
    Trie* node = new Trie;
    node->terminalVertex = false;
    return node;
}