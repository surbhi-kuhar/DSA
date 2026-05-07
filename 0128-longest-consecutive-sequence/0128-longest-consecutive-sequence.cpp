class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        for(auto x:nums) s.insert(x);

        int maxLen = 0;
        int len = 0;
        for(auto x:s){
            if(s.find(x-1)==s.end()){
                len++;
                int num = x;
                while(s.find(num+1)!=s.end()) {
                    len++;
                    num = num+1;
                }
                maxLen = max(maxLen,len);
                len = 0;
            }
        }

        return maxLen;
    }
};