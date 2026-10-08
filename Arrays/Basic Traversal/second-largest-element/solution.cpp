#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondLargest(vector<int>& arr) {
        int largest = INT_MIN, second = INT_MIN;
        for(int x : arr) {
            if(x > largest) {
                second = largest;
                largest = x;
            } else if(x < largest && x > second) {
                second = x;
            }
        }
        return second == INT_MIN ? -1 : second;
    }
};