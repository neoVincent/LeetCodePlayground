Lint_821_Time_Intersection.cpp

/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param seqA: the list of intervals
     * @param seqB: the list of intervals
     * @return: the time periods
     */
    vector<Interval> timeIntersection(vector<Interval> &seqA, vector<Interval> &seqB) {
        typedef pair<int, int> Event;
        vector<Event> es;
        
        for(auto seq : seqA)
        {
            es.push_back({seq.start,1});
            es.push_back({seq.end,-1});
        }
        
        for(auto seq: seqB)
        {
            es.push_back({seq.start,1});
            es.push_back({seq.end,-1});
        }
        
        sort(es.begin(),es.end(),[](const Event& lhs, const Event& rhs){
            if (lhs.first == rhs.first)
                return lhs.second < rhs.second;
            return lhs.first < rhs.first;
        });
        
        vector<Interval> res;
        int onlineNum = 0;
        Interval seq{INT_MIN,INT_MIN};
        for(auto e: es)
        {
            int entering = e.second > 0;
            int x = e.first;
            
            if (entering)
            {
                onlineNum++;
                if (onlineNum == 2)
                {
                    seq.start = x;
                }
            }
            else
            {
                onlineNum--;
                if (seq.start != INT_MIN)
                {
                    seq.end = x;
                    res.push_back(seq);
                    seq.start = INT_MIN;
                }
                
            }
        }
        return res;
    }
};
