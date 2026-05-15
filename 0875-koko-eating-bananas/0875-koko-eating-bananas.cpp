class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int hSpeed = 0;

        for(auto x:piles) hSpeed = max(hSpeed,x);

        long hoursSpent = 0;
        while(l<=hSpeed){
            int mid = (l+hSpeed)/2;

            long hoursSpent = 0;

            for(auto x:piles){
                hoursSpent += (x + mid - 1) / mid;   // so that it computes division like math integer
            }

            if(hoursSpent <= h) hSpeed = mid - 1;
            else l = mid+1;
        }

        return l;
    }
};