class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> >pq;

        int i;
        for(i=0;i<k;i++){
            pq.push(nums[i]);
        }

        while(i<nums.size()){
            pq.push(nums[i]);
            i++;

            if(pq.size()>k) pq.pop();
        }

        return pq.top();

    }
};