class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        result.push_back({});

        for(int n : nums) {
            int size = result.size();

            for(int i=0; i<size; i++) {
                vector<int> subset = result[i];
                subset.push_back(n);
                result.push_back(subset);
            }
        }
        return result;
    }
};