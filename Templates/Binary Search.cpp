#include <bits/stdc++.h>
using namespace std;

template <class Predicate>
int firstTrue(int low, int high, Predicate ok) {
    int answer = high + 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (ok(mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return answer;
}
