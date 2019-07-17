347_Top_K_Frequent_Elements.cpp

class Solution {
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> account;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> heap;
        
        for(int n: nums)
        {
            account[n]++;
        }
        
        for(auto iter = account.begin(); iter != account.end(); iter++)
        {
            heap.push({iter->second,iter->first});
        }
        
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(heap.top().second);
            heap.pop();
        }
        
        return res;
    }
};

class Solution {
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        typedef pair<int,int> Node;
        priority_queue<int,vector<int>,less<int>> basicHeap;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> heap;
        
        for(int n: nums)
        {
            basicHeap.push(n);
        }
        basicHeap.push(INT_MIN);
        
        int val;
        int preVal = basicHeap.top();
        int freq = 0;
        while(!basicHeap.empty())
        {
            int val = basicHeap.top();
            if (val != preVal)
            {
                heap.push({freq,preVal});
                freq = 1;
                preVal = val;
            }
            else
            {
                freq++;
            }
            basicHeap.pop();
        }
        
        vector<int> res;
        for(int i = 0; i < k; i++)
        {
            res.push_back(heap.top().second);
            heap.pop();
        }
        
        return res;
    }
};