#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

struct Node
{
    int rank;
    Node* p;
    Node(): rank(0), p(nullptr){}
};
class UnionFind
{
public:
    UnionFind(vector<vector<char>> grid)
    {
        _counter = 0;
        _sets.resize(grid.size()*grid[0].size());
        for(int i = 0; i < _sets.size(); i++)
        {
            _sets[i] = new Node();
            _sets[i]->p = _sets[i];
            _counter++;
        }
    }

    void unionSet(int p1, int p2 )
    {
        cout <<"Union point1: " << p1 << endl;
        cout <<"Union point2: " << p2 <<endl;
        cout << endl;
        Node* rep1 = findSet(p1);
        Node* rep2 = findSet(p2);
        if (rep1 == rep2)
        {
            cout << "===Same Rep===" << endl;
        cout <<"Union point1: " << p1 << endl;
        cout <<"Union point2: " << p2 <<endl;
            cout << "===Same Rep===" << endl;
        cout << endl;
            return;
        }
        //cout <<"Union point1: " << r1 <<" "<<c1 << endl;
        //cout <<"Union point2: " << r2 <<" "<<c2 <<endl;
        //cout << endl;
        if (rep1->rank > rep2->rank)
        {
            rep2->p = rep1;
        } else
        {
            rep1->p = rep2;
            if (rep1->rank == rep2->rank)
            {
                rep2->rank += 1;
            }
        }
        _counter--;
    }

    Node* findSet(int index)
    {
        Node* node = _sets[index];
        if (node->p != node)
        {
            node = findSet(node->p);
        }
        return node;
    }

    Node* findSet(Node* node)
    {
        if (node->p != node)
        {
            node = findSet(node->p);
        }
        return node;
    }

    int setSize()
    {
        return _counter;
    }

private:
    vector<Node*> _sets;
    int _counter;


};

int numIslands(vector<vector<char>>& grid)
{
    UnionFind unionFind(grid);
    cout <<"Union Set Size: " << unionFind.setSize() << endl;
    int index = -1;
    int colSize = grid[0].size();
    int rowSize = grid.size();
    int nonIslandsNum = 0;
    for(int r = 0 ; r < rowSize; r++)
    {
        for(int c = 0 ; c < colSize; c++)
        {
            index++;
            if (grid[r][c] == '0')
            {
                nonIslandsNum++;
                continue;
            }
            if (r == 0 && c == 0 ) continue;
            if (r == 0 && grid[r][c-1] != '0')
            {
                unionFind.unionSet(index,index-1);
                continue;
            }
            else if( c == 0 && grid[r-1][c] != '0')
            {
                unionFind.unionSet(index,index - colSize);
                continue;
            }

            if ( grid[r][c-1] != '0' )
            {
                unionFind.unionSet(index,index-1);
            }

            if (grid[r-1][c] != '0')
            {
                unionFind.unionSet(index,index - colSize);
            }

        }
    }
    int wholeSize = grid.size()*grid[0].size();
    return unionFind.setSize()- nonIslandsNum;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
