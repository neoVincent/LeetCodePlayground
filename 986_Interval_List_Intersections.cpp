986_Interval_List_Intersections.cpp
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        size_t i = 0;
        size_t j = 0;
        vector<vector<int>> res;
        while( i < A.size() && j < B.size())
        {
            const int s = max(A[i][0],B[j][0]);
            const int e = min(A[i][1],B[j][1]);
            if (s <= e)
                res.push_back({s,e});
            
            if (A[i][1] < B[j][1])
                i++;
            else 
                j++;
        }
        return res;
    }
};

struct Event
{
    int time;
    int isStart;
    Event(int t, int ss): time(t), isStart(ss){}
    
};

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        // sweep line
        vector<Event> events;
        for(auto a : A)
        {
            events.push_back({a[0],1});
            events.push_back({a[1],0});
        }
        
        for(auto b: B)
        {
            events.push_back({b[0],1});
            events.push_back({b[1],0});
        }
        
        std::sort(events.begin(),events.end(),[](const Event& lhs, const Event& rhs)
                  {
                      if (lhs.time != rhs.time)
                        return lhs.time < rhs.time; 
                      else
                        return lhs.isStart > rhs.isStart;
                  });
        
        // test
//         for(auto e: events)
//         {
//             cout <<"time " << e.time<<endl;
//             cout <<"isStart " << e.isStart << endl;
//         }
        
        int counter = 0;
        vector<vector<int>> res;
        stack<Event> stk;
        for(auto e: events)
        {
            if (e.isStart == 1)
            {
                stk.push(e);
                counter++;
            }
            else
            {
                auto pre = stk.top();
                stk.pop();
                if (counter > 1)
                {
                    res.push_back({pre.time, e.time});
                }
                counter--;
            }
        }
        return res;
    }
};
