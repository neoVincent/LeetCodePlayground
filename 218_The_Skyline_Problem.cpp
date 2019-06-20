218_The_Skyline_Problem.cpp

class Solution {
private:
    int maxHeight() const {
        if (hs_.empty()) return 0;
        return *hs_.rbegin();
    }
    multiset<int> hs_;

public:
    // pos, height
    // height > 0, start
    // height < 0, end
    typedef pair<int,int> Event;
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        typedef pair<int, int> Event; 
        // events,  x,   h
        vector<Event> es;        
        hs_.clear();
        
        for (const auto& b : buildings) {
            es.emplace_back(b[0], b[2]);
            es.emplace_back(b[1], -b[2]);
        }
        
        // Sort events by x
        sort(es.begin(), es.end(), [](const Event& e1, const Event& e2){
            if (e1.first == e2.first) return e1.second > e2.second;
            return e1.first < e2.first;
        });
        
        vector<vector<int>> ans;
        
        // Process all the events
        for (const auto& e: es) {            
            int x = e.first;
            bool entering = e.second > 0;
            int h = abs(e.second);
            
            if (entering) {                
                if (h > this->maxHeight()) 
                    ans.push_back({x, h});
                hs_.insert(h);
            } else {
                hs_.erase(hs_.equal_range(h).first);
                if (h > this->maxHeight())
                    ans.push_back({x, this->maxHeight()});
            }            
        }
        
        return ans;
    }
};


struct Point
{
    int pos;
    int hi;
    bool isStart;
    Point(int p, int h, bool s): pos(p), hi(h), isStart(s){}

};

class Solution {
public:
    
    bool static compHeight(const Point& lhs, const Point& rhs)
    {
        if (lhs.pos == rhs.pos)
        {
            
        }
    
        if (lhs.hi == rhs.hi)
            return lhs.pos < rhs.pos;

        return lhs.hi > rhs.hi;
    }
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        if (buildings.size() == 0) return {};

        vector<Point> points;
        for(auto b : buildings)
        {
            points.push_back(Point(b[0],b[2],true));
            points.push_back(Point(b[1],b[2],false));
        }

        // sort by the position
        sort(points.begin(),points.end(), [](const Point& lhs, const Point& rhs)
                                             {
                                                 if (lhs.pos == rhs.pos)
                                                 {
                                                     if (lhs.isStart && rhs.isStart)
                                                     {
                                                        return lhs.hi > rhs.hi; 
                                                     }
                                                     
                                                     if (!lhs.isStart && !rhs.isStart)
                                                     {
                                                        return lhs.hi < rhs.hi; 
                                                     }
                                                     
                                                     return lhs.isStart;
                                                 }
                                                 return lhs.pos < rhs.pos;
                                             });

        // // test for sorting
        // cout <<" Test for sorting"<<endl;
        // for(auto p: points)
        //     cout << p.pos<<" " << p.hi<<" "<< p.isStart << endl;
        // cout << endl;
        // // end for testing
        
        // max heap
        // height, point pair
        multiset<int,greater<int>> heap;
        vector<vector<int>> res;
        
        // push the point in first pos
        heap.insert(points[0].hi);
        res.push_back({points[0].pos, points[0].hi});
        
        for(int i = 1; i < points.size(); i++)
        {
            int top = -1;
            if (heap.size() > 0 )
                top = *heap.begin();
            // cout << "Pos " << points[i].pos <<" " << points[i].hi << "  " << points[i].isStart << endl;
            if (points[i].isStart) 
            {
                if (points[i].hi > top)
                    res.push_back({points[i].pos,points[i].hi});
                heap.insert(points[i].hi);
            }
            else
            {
                if (heap.size() == 1)
                {
                    res.push_back({points[i].pos, 0});
                    heap.erase(points[i].hi);
                }
                else 
                {
                    heap.erase(heap.lower_bound(points[i].hi));
                    if (points[i].hi >= top)
                    {
                        if(points[i].hi != *heap.begin() )
                            res.push_back({points[i].pos,*heap.begin()});
                    }
                }
            }
        }
        return res;
        
    }
};
