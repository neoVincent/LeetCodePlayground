621_Task_Scheduler.cpp
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // math 
        // record the task
        if (n == 0) return tasks.size();
        
        vector<int> record(26,0);
        size_t res = 0;
        for(auto ch: tasks)
        {
            record[ch-'A']++;
        }
        int maxVal = *max_element(record.begin(),record.end());
        int rest = count_if(record.begin(),record.end(), [=](const int& val){return maxVal == val;});
        res = (n+1)*(maxVal-1)+rest;
        return max(res,tasks.size());
    }
    
    
};