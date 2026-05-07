class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>max_heap;
        unordered_map<int,int>freq;
        vector<int>ans;

        for(auto x:nums){
            freq[x]++;
        }

        for(auto x:freq){
            max_heap.push({x.second,x.first});
        }

        while(k--){
            auto pair = max_heap.top();
            max_heap.pop();

            ans.push_back(pair.second);
        }

        return ans;
    }
};