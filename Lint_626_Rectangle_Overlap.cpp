Lint_626_Rectangle_Overlap.cpp
class Solution {
public:
    /**
     * @param l1: top-left coordinate of first rectangle
     * @param r1: bottom-right coordinate of first rectangle
     * @param l2: top-left coordinate of second rectangle
     * @param r2: bottom-right coordinate of second rectangle
     * @return: true if they are overlap or false
     */
    typedef pair<int,int> Interval;
    
    bool doOverlap(Point &l1, Point &r1, Point &l2, Point &r2) {
        Interval h1({l1.x,r1.x});
        Interval v1({r1.y,l1.y});
        Interval h2({l2.x,r2.x});
        Interval v2({r2.y,l2.y});
        
        return isOverlap(h1,h2) && isOverlap(v1,v2);
    }
    
    bool isOverlap( Interval& m1,  Interval& m2) 
    {
        // sort
        if (m1.first > m2.first)
            swap(m1,m2);
        // compare
        if (m1.second >= m2.first) return true;
        return false;
        
        
    }
};