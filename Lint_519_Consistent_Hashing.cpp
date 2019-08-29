Lint_519_Consistent_Hashing.cpp

class Solution {
public:
    /**
     * @param n a positive integer
     * @return n x 3 matrix
     */
    vector<vector<int>> consistentHashing(int n) {
        // Write your code here
        vector<vector<int>> results;
        vector<int> machine = {0, 359, 1};
        results.push_back(machine);

        for (int i = 1; i < n; ++i) {
            int index = 0;
            for (int j = 1; j < i; ++j) {
                if (results[j][1] - results[j][0] + 1 >
                    results[index][1] - results[index][0] + 1)
                    index = j;
            }

            int x = results[index][0];
            int y = results[index][1];
            results[index][1] = (x + y) / 2;
            
            machine[0] = (x + y) / 2 + 1;
            machine[1] = y;
            machine[2] = i + 1;
            results.push_back(machine);
        }

        return results;
    }
};