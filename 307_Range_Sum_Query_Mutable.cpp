307_Range_Sum_Query_Mutable.cpp

class SegmentTree
{
public:
    int start;
    int end;
    int sum;
    SegmentTree* left;
    SegmentTree* right;
    SegmentTree(int ss, int se, int sum, SegmentTree* l = nullptr, SegmentTree* r = nullptr)
        : start(ss)
        , end(se)
        , sum(sum)
        , left(l)
        , right(r)
        {}
};

class NumArray {
    
public:
    NumArray(vector<int>& nums) {
        // build tree
        if (nums.size() > 0)
            root = buildTree(nums,0,nums.size()-1);
    }
    
    void update(int i, int val) {
        updateValue(root,i,val);
    }
    
    int sumRange(int i, int j) {
        return sumRange(root,i,j);
    }

private:
    SegmentTree* buildTree(const vector<int>& nums, int start, int end)
    {
        if (start == end)
        {
            SegmentTree* node = new SegmentTree(start,start,nums[start]);
            return node;
        }
        
        int mid = (end - start)/2 + start;
        SegmentTree* left = buildTree(nums,start,mid);
        SegmentTree* right = buildTree(nums,mid+1,end);
        return new SegmentTree(start,end,left->sum+right->sum,left,right);
    }
    
    void updateValue(SegmentTree* node, int idx, const int& val)
    {
        if (node->start == idx && node->end == idx)
        {
            node->sum = val;
            return;
        }
        
        int mid = (node->end - node->start)/2 + node->start;
        if (idx > mid)
            updateValue(node->right,idx,val);
        else
            updateValue(node->left,idx,val);
        
        node->sum = node->left->sum + node->right->sum;
    }
    
    int sumRange(SegmentTree* node, int start, int end)
    {
        if (node->start >= start && node->end <= end)
        {
            return node->sum;
        }
        
        int mid = (node->end - node->start)/2 + node->start;
        if (end <= mid)
            return sumRange(node->left,start,end);
        else if (start > mid)
            return sumRange(node->right,start,end);
        else
            return sumRange(node->left,start,mid) + sumRange(node->right,mid+1,end);
    }
    
private:
    SegmentTree* root;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */