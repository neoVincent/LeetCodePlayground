30_Insert_Interval.cpp

class Solution {
public:
    void printInterval(Interval i)
    {
        cout << "Interval [" <<i.start <<", "<<i.end<<" ]" <<endl;
    }
    /**
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        
        // trick for the following case and put the newInterval to the last
        // [(1,5)] (6,8)
        intervals.push_back({INT_MAX,INT_MAX});
        
        auto iter = intervals.begin();
        while(iter != intervals.end())
        {
            if (isOverlap(*iter,newInterval))
            {
                newInterval = mergeInterval(*iter,newInterval);
                iter = intervals.erase(iter);
                printInterval(newInterval);
            }
            else if (newInterval.end < iter->start)
            {
                // no overlap 
                printInterval(*iter);
                printInterval(newInterval);
                iter = intervals.insert(iter,newInterval);
                break;
            }
            else 
            {
                iter++;
            }
                
        }
        return {intervals.begin(),intervals.end()-1};
    }
    
    bool isOverlap(const Interval& lhs, const Interval& rhs)
    {
        // 反过来写
        return !(lhs.start > rhs.end || rhs.start > lhs.end);
    }
    
    Interval mergeInterval(const Interval& lhs, const Interval& rhs)
    {
        Interval res;
        res.start = min(lhs.start, rhs.start);
        res.end = max(lhs.end,rhs.end);
        return res;
    }
};
