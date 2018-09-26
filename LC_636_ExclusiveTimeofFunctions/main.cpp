#include <QCoreApplication>
#include <vector>
#include <stack>
#include <list>
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;


vector<int> exclusiveTime(int n, vector<string>& logs)
{
    unordered_map<int,int> timeMap;
    vector<int> res;
    stack<string> logStart;
    stack<pair<int,int>> subFunction;
    for (int i = 0 ; i < logs.size(); i++)
    {
        if (logs[i].find("start") < logs[i].length())
        {
            logStart.push(logs[i]);
        }
        else
        {
            string start = logStart.top();
            logStart.pop();

            int startTime = stoi(start.substr(start.find_last_of(":") + 1));
            int endTime = stoi(logs[i].substr(logs[i].find_last_of(":") + 1));
            int timeSpan = endTime - startTime + 1;
            int id = stoi(start.substr(0, start.find_first_of(":")));
            int duration = timeSpan;

            while(!subFunction.empty() && subFunction.top().first == id)
            {
                duration -= subFunction.top().second;
                subFunction.pop();
            }
            if (!logStart.empty())
            {
                string pString = logStart.top();
                int pId = stoi(pString.substr(0, pString.find_first_of(":")));
                subFunction.push({pId,timeSpan});
            }

            timeMap[id] = timeMap[id] + duration;
        }
    }
    for(int  i = 0 ; i < n ;i++)
    {
        res.push_back(timeMap[i]);
    }
    return res;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<string> logs
    {
        {"0:start:0"},{"1:start:2"},{"1:end:5"},{"0:end:6"}
    };
    auto res = exclusiveTime(2,logs);
    for(int id : res)
        cout << id << endl;
    return a.exec();
}
