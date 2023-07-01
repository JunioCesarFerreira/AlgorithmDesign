#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class SuffixTrie 
{
    private:
        struct Node 
        {
            unordered_map<char, Node*> children;
            int wordCount;

            Node() : wordCount(0) {}
        };

        Node* root;

        bool search(const string& word) 
        {
            Node* current = root;

            for (char c : word) 
            {
                if (current->children.find(c) == current->children.end()) 
                {
                    return false;
                }
                current = current->children[c];
            }

            return true;
        }

    public:
        SuffixTrie() 
        {
            root = new Node();
        }

        void insert(const string& word) 
        {
            Node* current = root;
            current->wordCount++; // Incrementa o contador de palavras no nó raiz

            for (char c : word) 
            {
                if (current->children.find(c) == current->children.end()) 
                {
                    current->children[c] = new Node();
                }

                current = current->children[c];
                current->wordCount++; // Incrementa o contador de palavras no nó atual
            }
        }

        void remove(const string& word) 
        {
            Node* current = root;

            if (!search(word)) return;

            current->wordCount--; // Decrementa o contador de palavras no nó raiz

            for (char c : word) 
            {
                current = current->children[c];
                current->wordCount--; // Decrementa o contador de palavras no nó atual
            }
        }

        int countPrefix(const string& prefix) 
        {
            Node* current = root;

            for (char c : prefix) 
            {
                if (current->children.find(c) == current->children.end()) 
                {
                    return 0;
                }

                current = current->children[c];
            }

            return current->wordCount;
        }
};

int main() 
{
    int q;
    cin >> q;

    SuffixTrie trie;

    for (int i = 0; i < q; i++) 
    {
        int t;
        string s;
        cin >> t >> s;

        if (t == 1)
            trie.insert(s);

        else if (t == 2)
            trie.remove(s);
        
        else if (t == 3)
        {
            int count = trie.countPrefix(s);
            cout << count << endl;
        }
    }

    return 0;
}
