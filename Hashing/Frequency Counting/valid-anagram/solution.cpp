#include <bits/stdc++.h>
using namespace std;
class Solution{public:bool isAnagram(string s,string t){if(s.size()!=t.size())return false;array<int,26>f{};for(char c:s)++f[c-'a'];for(char c:t)if(--f[c-'a']<0)return false;return true;}};