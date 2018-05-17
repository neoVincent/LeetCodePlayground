#include <QCoreApplication>
#include <vector>
#include <iostream>

using namespace std;


int minCost(vector<int>& cost, int i);

int minCostClimbingStairs(vector<int>& cost)
{
    return minCost(cost,cost.size()-1);
}

int minCost(vector<int> &cost, int i)
{
    static vector<int> stairCost(cost.size(),-1);
    if (i < 0) return 0;
    if (stairCost[i] >= 0 ) return stairCost[i];
    stairCost[i] = cost[i] + min(minCost(cost,i-1),minCost(cost,i-2));

    return stairCost[i];

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> cost{0,0,1,1};
    cout << "Min cost: " <<  minCostClimbingStairs(cost) << endl;
    return a.exec();
}
