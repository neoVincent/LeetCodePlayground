211_Add_Search_Word.cpp
const int ALPHABET_SIZE = 26;

struct TrieNode
{
    TrieNode* children[ALPHABET_SIZE];
    bool isEnd;
    TrieNode(): isEnd(false)
    {
        for(int i = 0; i < ALPHABET_SIZE; ++i)
        {
            children[i] = nullptr;
        }
    }
    
};


class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* cur = root;
        for(int i = 0 ; i < word.size(); ++i)
        {
            int index = word[i] - 'a';
            if (!cur->children[index])
            {
                cur->children[index] = new TrieNode();
            }
            cur = cur->children[index];
        }
        cur->isEnd = true;
    }
    
    bool searchWord(string& word, int n, int pos, TrieNode* cur)
    {
        if (!cur) return false;
        if (n == pos) return cur->isEnd;
        
        
        if (word[pos] == '.')
        {
            for(int i = 0 ; i < ALPHABET_SIZE; i++ )
            {
                if (searchWord(word,n,pos+1,cur->children[i]))
                {
                    return true;
                }
            }
        }
        else
        {
            int index = word[pos] - 'a';
            if (cur->children[index])
            {
                return searchWord(word,n,pos+1,cur->children[index]);
            }
        }
        return false;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchWord(word,word.size(),0,root);
    }
    
private:
    TrieNode* root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
