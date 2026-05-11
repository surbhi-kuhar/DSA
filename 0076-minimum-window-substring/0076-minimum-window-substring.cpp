class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>freqt;
        unordered_map<char,int>currWin;

        for(auto x:t) freqt[x]++;

        int i = 0;
        int j = 0;

        int matched = 0;
        int ans = INT_MAX;
        string str = "";
        int start = 0;

        while(j<s.size()){

            currWin[s[j]]++;
            if(freqt.count(s[j]) && freqt[s[j]]==currWin[s[j]]) matched++;
            
            while(matched == freqt.size()){
                if(j-i+1 < ans){
                    ans = min(ans,j-i+1);
                    start = i;
                }
                currWin[s[i]]--;
                if(freqt.count(s[i]) && currWin[s[i]]<freqt[s[i]]) matched--;
                i++;
            }

            j++;
        }

        return ans==INT_MAX ? "" : s.substr(start,ans);
    }
};