#include <QCoreApplication>
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int profitMax = 0;

    if (prices.size() <= 1) return 0;

    for(int i = 1 ; i< prices.size(); i++)
    {
        if(prices[i-1] < prices[i])
        {
            profitMax += prices[i] - prices[i-1];
        }
    }
    return profitMax;
}


int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    vector<int> prices = {1,2,3,4,5};
    vector<int> p;
    cout << maxProfit(p)<<endl;
    return app.exec();
}
