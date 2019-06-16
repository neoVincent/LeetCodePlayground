590_ConnectingGraphII.cpp
class ConnectingGraph2 {
public:
    struct Node
    {
      Node* parent;
      int rank;
      int count;
      Node() 
      {
          parent = this;
          count = 1;
      }
    };
    
    vector<Node*> sets;
    /*
    * @param n: An integer
    */ConnectingGraph2(int n) {
        // do intialization if necessary
        sets.resize(n+1);
        for(auto& s: sets)
            s = new Node();
    }
    
    Node* find(Node* x)
    {
        if(x->parent != x)
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
        // write your code here
        Node* xp = find(sets[x]);
        Node* yp = find(sets[y]);
        
        // 判断x,y的parent是否不同
        if (xp == yp) return; 
        
        if (xp->rank > yp->rank)
        {
            yp->parent = xp;
            xp->count += yp->count;
        }
        else
        {
            xp->parent = yp;
            yp->count += xp->count;
            
            if (xp->rank == yp->rank)
            {
                yp->rank++;
            }
        }
        
    }

    /*
     * @param a: An integer
     * @return: An integer
     */
    int query(int a) {
        // write your code here
        return find(sets[a])->count;
    }
};