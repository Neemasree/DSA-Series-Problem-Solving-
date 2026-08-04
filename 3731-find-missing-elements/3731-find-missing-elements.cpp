class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        // Store all numbers for O(1) lookup
        unordered_set<int> st(nums.begin(), nums.end());
        // Find smallest and largest numbers
        int mini = *min_element(nums.begin(), nums.end());
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> ans;
        // Check every number in the range
        for (int i = mini; i <= maxi; i++) {
            // If number is missing, add it
            if (st.find(i) == st.end()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};