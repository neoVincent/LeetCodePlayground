Lint_399_Nuts_BoltsProblem.cpp
/**
 * class Comparator {
 *     public:
 *      int cmp(string a, string b);
 * };
 * You can use compare.cmp(a, b) to compare nuts "a" and bolts "b",
 * if "a" is bigger than "b", it will return 1, else if they are equal,
 * it will return 0, else if "a" is smaller than "b", it will return -1.
 * When "a" is not a nut or "b" is not a bolt, it will return 2, which is not valid.
*/
class Solution {
public:
    /**
     * @param nuts: a vector of integers
     * @param bolts: a vector of integers
     * @param compare: a instance of Comparator
     * @return: nothing
     */
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare) {
        sortNutsAndBolts(nuts,bolts,compare,0,nuts.size()-1);
    }
    
    void sortNutsAndBolts(vector<string> &nuts, vector<string> &bolts, Comparator compare, int left, int right)
    {
        
        if (left < right)
        {
            // first pick a pivot from nut
            // then sort the bolts
            string pivot = nuts[right];
            int pos = quicksort(bolts,false,pivot, compare, left, right);
            quicksort(nuts,true,bolts[pos],compare,left,right);
            
            // recursive
            sortNutsAndBolts(nuts,bolts,compare,left,pos-1);
            sortNutsAndBolts(nuts,bolts,compare,pos+1,right);
        }
    }
    
    int quicksort(vector<string>& array, bool isNuts, string& pivot, Comparator compare, int left, int right)
    {
        int i = left - 1;
        int pos = 0;
        for(int j = left; j <= right; j++)
        {
            // the compare result is in reverse order since we change the comparator
            int cmp = isNuts? -compare.cmp(array[j], pivot) : compare.cmp(pivot,array[j]);
            
            // sort in increasing order
            if (cmp == -1)
            {
                i++;
                swap(array[j],array[i]);
            }
            // WRONG 
            // the pos is not right, it may be swapped afterwards if pivot is the largest
            // else if (cmp == 0)
            // {
            //     pos = j;
            //     cout <<"equal " <<"Pos: " << pos << " Pivot "<< pivot <<" " <<array[j]<<endl;
            // }
        }
        
        // the right to i is larger or equal to pivot
        // find the pivot and swap to the 'mid'
        int k = i+1;
        for(; k <= right; k++)
        {
            int cmp = isNuts? compare.cmp(array[k], pivot) : compare.cmp(pivot,array[k]);
            if (cmp == 0)
                break;
        }
        
        i++;
        swap(array[k],array[i]);
        
        return i; 
    }
};