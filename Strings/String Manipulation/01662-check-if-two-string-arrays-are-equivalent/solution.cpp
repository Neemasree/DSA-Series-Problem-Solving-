class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first, second;

        for (const string& word : word1) first += word;
        for (const string& word : word2) second += word;

        return first == second;
    }
};