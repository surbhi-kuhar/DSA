class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int>prefix_prod(n,1),suff_prod(n,1);
        vector<int>ans(n,1);
        
        prefix_prod[0] = nums[0];
        suff_prod[n-1] = nums[n-1];

        for(int i=1;i<n;i++){
            prefix_prod[i] = prefix_prod[i-1]*nums[i];
        }

        for(int i=n-2;i>=0;i--){
            suff_prod[i] = suff_prod[i+1]*nums[i];
        }

        for(int i=0;i<n;i++){
            if(i+1>=n) ans[i] = prefix_prod[i-1];
            else if(i-1 <0) ans[i] = suff_prod[i+1];
            else ans[i] = suff_prod[i+1]*prefix_prod[i-1];
        }

        return ans;
    }
};