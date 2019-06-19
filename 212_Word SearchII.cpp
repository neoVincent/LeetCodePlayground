212_Word SearchII.cpp

typedef pair<int,int> Position;

struct Trie
{
    Trie* children[26];
    bool isEnd;
    string word;
    Trie(): isEnd(false), word("")
    {
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Solution {
    
private: 
    Trie* root;
    int m;
    int n;
    
public:
    void addWord(string s, Trie* root)
    {
        Trie* cur = root;
        for(int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            if (!cur->children[index])
                cur->children[index] = new Trie();
            cur = cur->children[index];
        }
        cur->isEnd = true;
        cur->word = s;
    }
    
    bool isValid(int x, int y)
    {
        if (0<=x && x < m && 0<=y && y < n)
        {
            return true;
        }
        return false;
    }
    
    void search(Position pos, vector<vector<char>>& board, vector<vector<bool>> visited, Trie* cur, set<string>& res)
    {
        
        // cout <<"X: " << pos.first;
        // cout <<" Y: " << pos.second;
        // cout <<" Char " << board[pos.first][pos.second] <<endl;
   
        int x = pos.first;
        int y = pos.second;
        int index = board[x][y] - 'a';
        cur = cur->children[index];

        if (!cur)
        {
            return ;
        }
        
        visited[x][y] = true;
        // cout <<"Visited " << board[x][y] << endl;
        
        if (cur->isEnd)
        {
            // cout <<"Find " << cur->word << endl; 
            res.insert(cur->word);
            // return ;
        }

        // visit its neighbour
        if (isValid(x+1,y) && !visited[x+1][y])
        {
            // cout << "down " << endl;
            int index = board[x+1][y] - 'a';
            search({x+1,y},board,visited,cur,res);
        }

        if (isValid(x-1,y) && !visited[x-1][y])
        {
            // cout <<"up " << endl;
            int index = board[x-1][y] - 'a';
            search({x-1,y},board,visited,cur,res);
        }

        if (isValid(x,y+1) && !visited[x][y+1])
        {
            // cout << "right"<<endl;
            int index = board[x][y+1]-'a';
            search({x,y+1},board,visited,cur,res);
        }

        if (isValid(x,y-1) && !visited[x][y-1])
        {
            // cout << "left"<<endl;
            int index = board[x][y-1]-'a';
            search({x,y-1},board,visited,cur,res);
        }
        // cout << " === " << endl;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // create trie
        root = new Trie();
        m = board.size();
        n = board[0].size();
        
        for(string s: words)
        {
            addWord(s,root);
        }
      
        // search in the trie
        // dfs search
        set<string> res;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                vector<vector<bool>> visited(m,vector<bool>(n,false));
                search({i,j},board,visited,root,res);
            }
        }
        return {res.begin(),res.end()};
    }
};