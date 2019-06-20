Lint_391_Num_Airplanes.cpp

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
     * @param airplanes: An interval array
     * @return: Count of airplanes are in the sky.
     */
    int countOfAirplanes(vector<Interval> &airplanes) {
        typedef pair<int, int> Event;
        vector<Event> es;
        
        for(auto plane: airplanes)
        {
            es.push_back({plane.start,1});
            es.push_back({plane.end,-1});
        }
        sort(es.begin(),es.end(),[](const Event& lhs,const Event& rhs)
        {
           if (lhs.first == rhs.first)
                return lhs.second < rhs.second;
            return lhs.first < rhs.first;
        });      
        
        // test for es
        for(auto e : es)
            cout << e.first << " " << e.second << endl;
        // end test for es
        
        int counter = 0;
        int res = 0;
        for(auto e : es)
        {
            bool landing = e.second < 0;
            
            if (landing)
            {
                counter--;    
            }
            else
            {
                counter++;
                res = max(res,counter);
            }
        }
        return res;
    }
};
