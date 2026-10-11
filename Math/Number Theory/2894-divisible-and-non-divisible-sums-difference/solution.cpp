class Solution {
public:
    int differenceOfSums(int n, int m) {
        long long total = 1LL * n * (n + 1) / 2;
        long long count = n / m;
        long long divisibleSum = 1LL * m * count * (count + 1) / 2;

        return static_cast<int>(total - 2 * divisibleSum);
    }
};