#include <QCoreApplication>
#include <vector>
#include <stack>
#include <list>
#include <string>
#include <iostream>
#include <unordered_map>
#include <sstream>
#include <array>

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

            //substract the subfuctions
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

/*
vector<int> exclusiveTime(int n, vector<string>& logs) {
    int lastTime = 0; // Remember the time in previous log entry
    stack<int> callStack;
    vector<int> runTime( n, 0 );
    size_t pos;
    for( int i = 0; i < logs.size(); i++ ) {
        // Parse the line
        string str = logs[ i ];
        pos = str.find( ":" );
        int funcId = stoi( str.substr( 0, pos ) );
        str.erase( 0, pos+1 );
        pos = str.find( ":" );
        string type = str.substr( 0, pos );
        str.erase( 0, pos+1 );
        int currTime = stoi( str );

        if ( type == "start" ) {
            // If a new function is called top of stack will contain the execution
            // context of this function. Update the runTime using that and push
            // current function of stack.
            if ( callStack.size() > 0 ) runTime[ callStack.top() ] += currTime-lastTime;
            callStack.push( funcId );
            lastTime = currTime;
        } else {
            // If a function has ended the top of stack will tell us its id
            // Update the runTime using that and pop the function from stack.
            runTime[ callStack.top() ] += currTime+1-lastTime;
            callStack.pop();
            lastTime = currTime+1;
        }
    }
    return runTime;
}
*/

// lines in the format of "a:b:c"
void tokenString(vector<string> lines)
{
    for (auto line : lines)
    {
        istringstream iss(line);
        array<string,3> tokens;
        for(int i = 0 ; i < tokens.size(); ++i)
        {
            getline(iss,tokens[i],':');
        }

        for (string str : tokens)
            cout << "Token: " << str << endl;
    }

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    vector<string> logs
    {
        {"0:start:0"},{"1:start:2"},{"1:end:5"},{"0:end:6"}
    };
//    auto res = exclusiveTime(2,logs);
//    for(int id : res)
//        cout << id << endl;

    tokenString(logs);
    return a.exec();
}
