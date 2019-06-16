591_ConnectingGraph3.cpp
class ConnectingGraph3 {
public:

    struct Node
    {
      Node* parent;
      int rank;
      Node(){ parent = this;}
    };
    
    vector<Node*> sets;
    int size;
    
    ConnectingGraph3(int n)
    {
        size = n;
        sets.resize(n+1);
        for(auto& s: sets)
            s = new Node();
    }
    
    Node* find(Node* x)
    {
        if (x->parent != x)
        {
            x->parent = find(x->parent);
        }
        return x->parent;
    }
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: nothing
     */
    void connect(int x, int y) {
        Node* xp = find(sets[x]);
        Node* yp = find(sets[y]);
        
        if (xp == yp) return;
        
        if (xp->rank > yp->rank)
        {
            yp->parent = xp;
        }
        else
        {
            xp->parent = yp;
            if (xp->rank == yp->rank)
            {
                yp->rank++;
            }
        }
        size--;
        
    }

    /**
     * @return: An integer
     */
    int query() {
        // write your code here
        return size;
    }
};