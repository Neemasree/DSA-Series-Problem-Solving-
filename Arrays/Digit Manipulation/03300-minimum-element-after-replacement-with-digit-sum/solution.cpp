class Solution {
    int digitSum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for (int x : nums) ans = min(ans, digitSum(x));
        return ans;
    }
};