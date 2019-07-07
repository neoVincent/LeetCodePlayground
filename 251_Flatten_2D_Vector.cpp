251_Flatten_2D_Vector.cpp
class Vector2D {
private:
    vector<vector<int>>::iterator outerIter;
    vector<vector<int>>::iterator outerEnd;
    int innerIter;
    
public:
    Vector2D(vector<vector<int>>& v) {
        outerIter = v.begin();
        outerEnd = v.end();
        innerIter = 0;
    }
    
    int next() {
        hasNext();
        return (*outerIter)[innerIter++];
    }
    
    bool hasNext() {
        while(outerIter != outerEnd && outerIter->size() == innerIter)
        {
            outerIter++;
            innerIter = 0;
        }
        
        return outerIter != outerEnd;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(v);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
