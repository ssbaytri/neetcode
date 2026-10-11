class WordDictionary {
public:
    WordDictionary *children[26];
    bool isWord;

    WordDictionary() {
        isWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
    
    void addWord(string word) {
        WordDictionary *curr = this;
        for (char c : word)
        {
            int idx = c - 'a';
            if (curr->children[idx] == nullptr)
                curr->children[idx] = new WordDictionary();
            curr = curr->children[idx];
        }
        curr->isWord = true;
    }
    
    bool search(string word) {
        return searchFrom(this, word, 0);
    }

    private:
        bool searchFrom(WordDictionary* node, string word, int i)
        {
            if (i == (int) word.size())
                return node->isWord;

            int c = word[i];
            if (c == '.')
            {
                for (int k = 0; k < 26; k++)
                {
                    if (node->children[k] != nullptr && searchFrom(node->children[k], word, i + 1))
                        return true;
                }
                return false;
            }
            else
            {
                int idx = c - 'a';
                if (node->children[idx] == nullptr)
                    return false;
                return searchFrom(node->children[idx], word, i + 1);
            }
        }
};
