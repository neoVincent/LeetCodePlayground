Lint_613_High_Five.cpp
class Solution {
public:
    /**
     * @param results a list of <student_id, score>
     * @return find the average of 5 highest scores for each person
     * map<int, double> (student_id, average_score)
     */
    map<int, double> highFive(vector<Record>& results) {
        unordered_map<int, multiset<int>> records;
        for(auto& item : results)
        {
            if (records[item.id].size() < 5)
            {
                records[item.id].insert(item.score);
            }
            else
            {
                if (item.score > *records[item.id].begin())
                {
                    records[item.id].erase(records[item.id].begin());
                    records[item.id].insert(item.score);
                }
            }
        }
        
        map<int, double> res;
        
        for(auto iter = records.begin(); iter != records.end(); iter++)
        {
            double average = accumulate(iter->second.begin(), iter->second.end(),0)/5.0;
            res[iter->first] = average;
        }
        
        return res;
    }
};