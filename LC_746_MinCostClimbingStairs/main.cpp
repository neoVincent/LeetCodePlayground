#include <QCoreApplication>
#include <vector>
#include <iostream>

using namespace std;


int minCost(vector<int> &cost, int i, vector<int>& stairCost)
{
    if (i < 0) return 0;
    if (stairCost[i] >= 0 ) return stairCost[i];
    stairCost[i] = min(minCost(cost,i-1,stairCost)+cost[i],minCost(cost,i-2,stairCost)+cost[i]);

    return min(stairCost[i],stairCost[i-1]);

}

int minCostClimbingStairs(vector<int>& cost)
{
    vector<int> stairCost(cost.size(),-1);
    auto res = minCost(cost,cost.size()-1,stairCost);
    return res;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> cost{0,1,1,0};
    cout << "Min cost: " <<  minCostClimbingStairs(cost) << endl;
    return a.exec();
}
