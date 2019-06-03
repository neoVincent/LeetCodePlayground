148. Sort List.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* sortList(ListNode* head) {
        
        // initial check
        if (!head) return head;
        
        vector<int> v;
        ListNode* p = head;
        while(p)
        {
            v.push_back(p->val);
            p = p->next;
        }
        
        sort(v.begin(), v.end());
        
        p = head;
        for(int val : v)
        {
            p->val = val;
            p = p->next;
        }
        
        return head;
                
    }
};
