#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class Trie
{
public:
    struct TrieNode
    {
        char character;
        std::unordered_map<char, TrieNode *> map{};

        TrieNode() : character(0), map({}) {};
        TrieNode(char c) : character(c), map({}) {};
    };

    Trie()
    {
        root = new TrieNode();
    }

    void insert(std::string word)
    {
        auto current = root;

        for (char c : word)
        {
            auto &map = current->map;

            if (map.find(c) == map.end())
            {
                TrieNode *node = new TrieNode(c);
                map.insert({c, node});
            }

            current = map[c];
        }

        current->map.insert({'\0', nullptr});
    }

    bool search(std::string word)
    {
        auto current = root;

        for (char c : word)
        {
            auto map = current->map;

            if (map.find(c) == map.end())
            {
                return false;
            }

            current = map[c];
        }

        return current->map.find('\0') != current->map.end();
    }

    bool startsWith(std::string prefix)
    {
        auto current = root;

        for (char c : prefix)
        {
            auto map = current->map;

            if (map.find(c) == map.end())
            {
                return false;
            }

            current = map[c];
        }

        return true;
    }

private:
    TrieNode *root;
};

int main()
{
    Trie trie{};

    trie.insert("apple");
    std::cout << trie.search("apple") << std::endl;
    std::cout << trie.search("app") << std::endl;
    std::cout << trie.startsWith("app") << std::endl;
    trie.insert("app");
    std::cout << trie.search("app") << std::endl;

    return 0;
}