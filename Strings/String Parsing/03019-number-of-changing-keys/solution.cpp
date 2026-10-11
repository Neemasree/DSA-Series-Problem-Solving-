class Solution {
public:
    int countKeyChanges(string s) {
        int changes = 0;

        for (int i = 1; i < s.size(); i++) {
            if (tolower(static_cast<unsigned char>(s[i])) !=
                tolower(static_cast<unsigned char>(s[i - 1]))) {
                changes++;
            }
        }
        return changes;
    }
};