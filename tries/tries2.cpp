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
    void insertUtil(TrieNode *root, string word, int e)
    {
        TrieNode *curr = root;
        for (int i = 0; i < e; i++)
        {
            int ind = word[i] - 'A';
            if (curr->children[ind] == NULL)
            {
                curr->children[ind] = new TrieNode(word[i]);
            }
            curr = curr->children[ind];
            if (i == e - 1)
                curr->isTerminal = true;
        }
    }
    void insert(string word)
    {
        insertUtil(root, word, word.length());
    }

    bool searchUtil(TrieNode *root, string word, int e)
    {
        TrieNode *curr = root;
        for (int i = 0; i < e; i++)
        {
            int ind = word[i] - 'A';
            if (curr->children[ind] != NULL)
            {
                curr = curr->children[ind];
            }

            else
            {
                return false;
            }
        }
        return curr->isTerminal;
    }

    bool search(string word)
    {
        return searchUtil(root, word, word.length());
    }
    void removeUtil(TrieNode *root, string word, int e)
    {
        TrieNode *curr = root;
        if (search(word))
        {
            for (int i = 0; i < e; i++)
            {
                int ind = word[i] - 'A';
                curr = curr->children[ind];
            }
            curr->isTerminal = false;
            cout << "removed" << endl;
                }
        else
        {
            cout << "word does not exist" << endl;
        }
    }

    void remove(string word)
    {
        removeUtil(root, word, word.length());
    }

    bool prefixUtil(TrieNode *root, string word, int s, int e)
    {
        TrieNode *curr = root;
        for (int i = 0; i < e; i++)
        {
            int ind = word[i] - 'A';
            if (curr->children[ind] != NULL)
            {
                curr = curr->children[ind];
            }

            else
            {
                return false;
            }
        }
        return true;
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