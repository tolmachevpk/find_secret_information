#include "../Headers/aho_corasick.h"
#include <iostream>

void AhoKorasik::algorithmRealization(const std::string &word) {
    Trie* node = root;
    for (int i = 0; i < word.length(); i++) {
        node = goTo(node, word[i]);
        out(node);
    }
    std::cout << "Does not match anything." << std::endl;
}

void AhoKorasik::out(Trie* node) {
    if (!node->terminalVertex) {
        node = termLink(node);
    }
    for ( ; node != root; node = termLink(node)) {
        if (!node->word.empty()) {
            std::cout << "Target detected." << std::endl;
            exit(0);
        }
    }
}

Trie* AhoKorasik::termLink(Trie* node) {
    if (node->termLinkCache != nullptr) {
        return node->termLinkCache;
    }
    if (sufLink(node)->terminalVertex) {
        node->termLinkCache = sufLink(node);
    } else {
        if (sufLink(node) == root) {
            node->termLinkCache = root;
        } else {
            node->termLinkCache = termLink(sufLink(node));
        }
    }
    return node->termLinkCache;
}

Trie* AhoKorasik::goTo(Trie* node, char a) {
    if (node->map.find(a) != node->map.end()) {
        return node->map[a];
    }
    if (node == root) {
        return root;
    }
    node->map[a] = goTo(sufLink(node), a);
    return node->map[a];
}

Trie* AhoKorasik::sufLink(Trie* node) {
    if (node->sufLinkCache != nullptr) {
        return node->sufLinkCache;
    }
    if ((node == root) || (node->parent == root)) {
        return root;
    }
    node->sufLinkCache = goTo(sufLink(node->parent), node->symbol);
    return node->sufLinkCache;
}