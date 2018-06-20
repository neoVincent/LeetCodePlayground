#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <iterator>
#include <unordered_map>

using namespace std;

int maxProfit(vector<int>& prices)
{
    unordered_map<int,int> profitMap;
    profitMap[0] = 0;
    int max = 0;
    for(int j = 1 ; j< prices.size(); j++)
    {
        for(int i = 0; i< j ; i++)
        {
            if (prices[j] - prices[i] > max) max = prices[j] - prices[i];
        }
        profitMap[j] = max;
    }
    return profitMap[prices.size()-1];
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
