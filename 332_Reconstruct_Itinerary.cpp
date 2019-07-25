332_Reconstruct_Itinerary.cpp

class Solution {
private:
    unordered_map<string,multiset<string>> targets;
    vector<string> route;
    
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto t: tickets)
            targets[t[0]].insert(t[1]);
        visit("JFK");
        return vector<string>(route.rbegin(),route.rend());
    }
    
    void visit(string airport)
    {
        while(targets[airport].size())
        {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        route.push_back(airport);
    }
};