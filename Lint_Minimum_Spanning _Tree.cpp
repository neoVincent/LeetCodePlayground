Lint_Minimum_Spanning _Tree.cpp
/**
 * Definition for a Connection.
 * class Connection {
 * public:
 *   string city1, city2;
 *   int cost;
 *   Connection(string& city1, string& city2, int cost) {
 *       this->city1 = city1;
 *       this->city2 = city2;
 *       this->cost = cost;
 * }
 */

struct Node 
{
    int rank;
    Node* parent;
    Node()
    {
        parent = this;
    }
};

class Solution {
public:
    
    Node* find(Node* x)
    {
        if (x->parent != x)
        {
            x->parent = find(x->parent);
        }
        return x->parent;
    }
    
    void Union(Node* x, Node* y)
    {
        Node* xp = find(x);
        Node* yp = find(y);
        
        if (xp->rank > yp->rank)
        {
            yp->parent = xp;
        }
        else
        {
            xp->parent = yp;
            if (xp->rank == yp->rank)
                yp->rank++;
        }
    }
    /**
     * @param connections given a list of connections include two cities and cost
     * @return a list of connections from results
     */
    vector<Connection> lowestCost(vector<Connection>& connections) {
        // city name, node
        unordered_map<string,Node*> sets;
        vector<Connection> res;
        
        // sort the connections
        sort(connections.begin(),connections.end(),[](const Connection& lhs, const Connection& rhs){
            if (lhs.cost == rhs.cost)
            {
                if(lhs.city1 == rhs.city1)
                {
                    return lhs.city2 < rhs.city2;
                }
                return lhs.city1 < rhs.city1;
            }
            return lhs.cost < rhs.cost;
        });
        
        // test for sort
        // for(auto c: connections)
        //     cout << c.cost <<" ";
        // cout << endl;

        int count = 0;
        for(auto conn: connections)
        {
            if (sets.find(conn.city1) == sets.end())
            {
                sets[conn.city1] = new Node();
                count++;
            }
            
            if (sets.find(conn.city2) == sets.end())
            {
                sets[conn.city2] = new Node();
                count++;
            }
            
            if (find(sets[conn.city1]) != find(sets[conn.city2]))
            {
                Union(sets[conn.city1], sets[conn.city2]);
                res.push_back(conn);
                count--;
            }
                
        }
        
        // check the number of component
        if (count > 1)
            return {};
        else
            return res;
    }
};