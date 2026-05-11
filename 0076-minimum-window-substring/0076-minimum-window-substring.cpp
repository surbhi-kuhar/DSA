class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> freqt;
        unordered_map<char,int> currWin;

        for(auto x : t) freqt[x]++;

        int i = 0, j = 0;

        int matched = 0;

        int start = 0;
        int minLen = INT_MAX;

        while(j < s.size()) {

            currWin[s[j]]++;

            if(freqt.count(s[j]) &&
               currWin[s[j]] == freqt[s[j]]) {
                matched++;
            }

            while(matched == freqt.size()) {

                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                currWin[s[i]]--;

                if(freqt.count(s[i]) &&
                   currWin[s[i]] < freqt[s[i]]) {
                    matched--;
                }

                i++;
            }

            j++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};