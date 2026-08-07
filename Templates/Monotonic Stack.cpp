#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(const vector<int>& values) {
    vector<int> answer(values.size(), -1);
    stack<int> st;

    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        while (!st.empty() && values[st.top()] < values[i]) {
            answer[st.top()] = values[i];
            st.pop();
        }
        st.push(i);
    }
    return answer;
}
