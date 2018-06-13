#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <set>
#include <unordered_set>

//Algorithms: https://leetcode.com/problems/distribute-candies/solution/

using namespace std;


int distributeCandies(vector<int>& candies)
{
    sort(candies.begin(),candies.end());
    int size = candies.size();
    candies.erase((unique(candies.begin(),candies.end())),candies.end());
    int kinds = candies.size();

    return kinds >= size/2? size/2:kinds;

}

int distributeCandies2(vector<int>& candies)
{
    set<int> kinds;
    for(int candy : candies) kinds.insert(candy);
    int types = kinds.size();
    return types >= candies/2 ? candies/2 : types;

//    unordered_set<int> kinds(candies.begin(),candies.end());
//    return min(kinds.size(),candies.size()/2);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<int> candies{1,1,2,2,3,3};
    cout<< "result: "<<distributeCandies(candies)<<endl;
    return a.exec();
}
