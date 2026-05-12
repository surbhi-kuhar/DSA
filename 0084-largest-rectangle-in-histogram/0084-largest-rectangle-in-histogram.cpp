class Solution {
public:

    void findSmallerInRight(vector<int>heights,stack<int>&st,vector<int>&nearestSmallerRight){
        int n = heights.size();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(!st.empty()) nearestSmallerRight[i] = st.top();
            st.push(i);
        }
    }

    void findSmallerInLeft(vector<int>heights,stack<int>&st,vector<int>&nearestSmallerLeft){
        int n = heights.size();

        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }

            if(!st.empty()) nearestSmallerLeft[i] = st.top();
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>nearestSmallerRight(n,-1),nearestSmallerLeft(n,-1);

        stack<int>st1,st2;

        findSmallerInRight(heights,st1,nearestSmallerRight);
        findSmallerInLeft(heights,st2,nearestSmallerLeft);


        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(nearestSmallerRight[i]==-1) nearestSmallerRight[i] = n;
            ans = max(ans, heights[i]*(nearestSmallerRight[i]-nearestSmallerLeft[i]-1));
        }

        return ans;
    }
};