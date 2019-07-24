547_Friend Circles.cpp
class Solution {
public:
    // dfs
    int findCircleNum(vector<vector<int>>& M) {
        int res = 0;
        vector<int> circles(M.size(),-1);
        for(int i = 0; i < M.size(); i++)
        {
            // unvisited
            if (circles[i] == -1)
            {
                res++;
                dfs(M,i,circles,res);
            }
        }
        return res;
    }
    
    void dfs(vector<vector<int>>& M, int v, vector<int>& circles, int& n)
    {
        circles[v] = n;
        for(int i = 0 ; i < M[v].size(); i++)
        {
            if (M[v][i] == 1 && circles[i] == -1)
            {
                circles[i] = n;
                dfs(M,i,circles,n);
            }
        }
    }
};

class Solution {
public:
    // BFS
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> circles(M.size(),-1);
        int res = 0;
        for(int i = 0; i < M.size(); i++)
        {
            if (circles[i] == -1)
            {
                res++;
                circles[i] = res;
                bfs(M,i,circles,res);
            }
        }
        return res;
    }
    
    void bfs(vector<vector<int>>& M, int v, vector<int>& circles, int res)
    {
        deque<int> que;
        que.push_back(v);
        while(!que.empty())
        {
            int u = que.front();
            que.pop_front();
            for(int i = 0 ; i < M[u].size(); i++)
            {
                if (M[u][i] == 1 && circles[i] == -1)
                {
                    circles[i] = res;
                    que.push_back(i);
                }
            }
            
        }
    }
};


class Solution {
private:
    vector<int> sets;
    int count;
public:
    int find(int x)
    {
        if (sets[x] != x)
        {
            sets[x] = find(sets[x]);
        }
        return sets[x];
    }
    
    void Union(int x, int y)
    {
        int xp = find(x);
        int yp = find(y);
        if (xp != yp)
        {
            sets[yp] = xp;
            count--;
        }
        
    }
    
    // union find
    int findCircleNum(vector<vector<int>>& M) {
        sets.resize(M.size());
        count = M.size();
        
        // initialzie
        for(int i = 0; i < sets.size();i++)
            sets[i] = i;
        
        for(int i = 0; i < M.size(); i++)
        {
            for(int j = 0; j < M[i].size(); j++)
            {
                cout <<i << " " << j <<endl;
                if(i != j && M[i][j] == 1 && find(i) != find(j))
                {
                    Union(i,j);
                }
            }
        }
        return count;
    }
};
