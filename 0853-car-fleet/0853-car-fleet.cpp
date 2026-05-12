class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int,int>>p;

        for(int i=0;i<n;i++){
            p.push_back({position[i],speed[i]});
        }

        sort(p.begin(),p.end());
        stack<double>st;

        int fleet = 0;

        for(int i=n-1;i>=0;i--){

            double time = (double)(target-p[i].first)/p[i].second;

            if(st.empty() || st.top()<time){
                st.push(time);
            }

        }

        return st.size();
    }
};