class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>result;

        for(int j=0;j<nums.size();j++){

            while(!dq.empty() && dq.front() <= j-k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[j]){
                dq.pop_back();
            }

            dq.push_back(j);

            if(j >= k-1){
                result.push_back(nums[dq.front()]);
            }

        }

        return result;
           
    }
};