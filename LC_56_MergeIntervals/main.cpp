#include <QCoreApplication>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool IntervalCompare( const Interval& lhs, const Interval& rhs)
{
    if (lhs.start < rhs.start) // less
    {
        return false;
    }
    else  //large  lhs.end <= rhs.end , lhs.end > rhs.end
    {
        return true;
    }
}
vector<Interval> merge(vector<Interval>& intervals)
{
    priority_queue<Interval, vector<Interval>, decltype (IntervalCompare)* > prique(IntervalCompare);
    for(Interval i : intervals) prique.push(i);
    vector<Interval> res;
    while(!prique.empty())
    {
        Interval tmp = prique.top();
        prique.pop();
        if (!res.empty())
        {
            if (res.back().end >= tmp.start)
            {
                if (res.back().end < tmp.end)
                    res.back().end = tmp.end;
            }
            else
            {
                res.push_back(tmp);
            }
        }
        else
        {
            res.push_back(tmp);
        }
    }
    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    vector<Interval> intervals
    {
        {1,3},{2,6},{8,10},{15,18}
    };
    auto res = merge(intervals);
    for(Interval i : res)
        cout<< "[ "<<i.start << ", "<<i.end<<" ]" << endl;
    return a.exec();
}
