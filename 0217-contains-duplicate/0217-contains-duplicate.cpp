class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>freq;

        for(auto x:nums){
            if(freq.find(x)!=freq.end()){
                return true;
            }
            freq[x]++;
        }

        return false;
    }
};