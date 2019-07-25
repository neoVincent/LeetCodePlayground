133_Clone_Graph.cpp
class Solution {
public:
    // BFS
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        Node* copy = new Node(node->val, {});
        unordered_map<Node*, Node*> copies;
        copies[node] = copy;
        deque<Node*> que;
        que.push_back(node);
        
        while(!que.empty())
        {
            Node* cur = que.front();
            que.pop_front();
            for(Node* nb : cur->neighbors)
            {
                if (copies.find(nb) == copies.end())
                {
                    copies[nb] = new Node(nb->val,{});
                    que.push_back(nb);
                }
                copies[cur]->neighbors.push_back(copies[nb]);
            }
        }
        return copy;
    }
};

class Solution {
private:
    unordered_map<Node*,Node*> copies;
    
public:
    // dfs
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        if (copies.find(node) == copies.end())
        {
            copies[node] = new Node(node->val,{});
            for(Node* nb: node->neighbors)
            {
                copies[node]->neighbors.push_back(cloneGraph(nb));
            }
        }
        return copies[node];
    }
};