class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l = 1;
        int maxi = 0;

        for(auto x:piles) maxi = max(maxi,x);

        while(l<=maxi){
            int mid = (l+maxi)/2;

            long timeSpent = 0;

            for(auto x:piles){
                timeSpent += (x + mid -1)/mid;
            }

            if(timeSpent <= h) maxi = mid-1;
            else l = mid+1;
        }

        return l;
    }
};