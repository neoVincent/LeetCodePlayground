589_Connecting_Graph.cpp

class ConnectingGraph {

public:
    struct Node
    {
        Node* parent;
        int rank;
        Node() {parent = this;}
    };
    
    vector<Node*> sets;
    /*
    * @param n: An integer
    */ConnectingGraph(int n) {
        // do intialization if necessary
        sets.resize(n+1);
        for(auto& s : sets)
        {
            s = new Node();
        }
    }

    Node* find(Node* x)
    {
        if (x->parent != x)
        {
           x->parent = find(x->parent);
        }
        return x->parent;
    }
    /*
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int x, int y) {
        // this is union
        Node* xp = find(sets[x]);
        Node* yp = find(sets[y]);
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

    /*
     * @param a: An integer
     * @param b: An integer
     * @return: A boolean
     */
    bool query(int a, int b) {
        // write your code here
        return find(sets[a]) == find(sets[b]);
    }
};