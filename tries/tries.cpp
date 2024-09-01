#include <bits/stdc++.h>

using namespace std;

struct TrieNode
{
    char data;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    }
};

struct TrieOperations
{
    TrieNode *root;
    TrieOperations()
    {
        root = new TrieNode('/');
    }
    void insertUtil(TrieNode *root, string word, int s, int e)
    {
        if (s == e || e <= 0)
            return;

        // Words are in ALL CAPS
        int index = word[s] - 'A';
        if (root->children[index] == NULL)
            root->children[index] = new TrieNode(word[s]);

        if (s == e - 1)
            root->children[index]->isTerminal = true;

        insertUtil(root->children[index], word, s + 1, e);
    }
    void insert(string word)
    {
        insertUtil(root, word, 0, word.length());
    }

    bool searchUtil(TrieNode *root, string word, int s, int e)
    {
        if (s == e)
            return root->isTerminal;
        int ind = word[s] - 'A';
        if (root->children[ind] != nullptr)
            return searchUtil(root->children[ind], word, s + 1, e);

        return false;
    }

    bool search(string word)
    {
        return searchUtil(root, word, 0, word.length());
    }
    void removeUtil(TrieNode *root, string word, int s, int e)
    {
        if (s == e)
        {
            cout << "removed" << endl;
            root->isTerminal = false;
            return;
        }
        int ind = word[s] - 'A';
        if (root->children[ind] != nullptr)
            return removeUtil(root->children[ind], word, s + 1, e);
    }

    void remove(string word)
    {
        removeUtil(root, word, 0, word.length());
    }

    bool prefixUtil(TrieNode *root, string prefix, int s, int e)
    {

        if (s == e)
            return true;

        int ind = prefix[s] - 'a';
        if (root->children[ind] == NULL)
            return prefixUtil(root, prefix, s + 1, e);

        return false;
    }

    bool searchPrefix(string prefix)
    {
        return prefixUtil(root, prefix, 0, prefix.length());
    }

    void printWordsUtil(TrieNode *root, string currentWord)
    {
        if (root->isTerminal)
            cout << currentWord << endl;

        for (int i = 0; i < 26; i++)
        {
            if (root->children[i] != nullptr)
            {
                printWordsUtil(root->children[i], currentWord + string(1, root->children[i]->data));
            }
        }
    }

    void printWords()
    {
        printWordsUtil(root, "");
    }
};

int main()
{
    TrieOperations t;
    t.insert("ABCD");
    t.insert("MAT");
    cout << t.search("HAT") << endl;
    t.insert("HAT");
    t.insert("WHAT");
    t.insert("IS");
    cout << t.search("HAT") << endl;
    t.printWords();
    t.remove("HAT");
    t.printWords();

    return 0;
}