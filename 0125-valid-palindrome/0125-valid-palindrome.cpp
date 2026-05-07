class Solution {
public:
    bool isPalindrome(string s) {
        string forward = "";
       
        for(auto x:s){
            if(x>='a' && x<='z' || x>='A' && x<='Z'){
                forward += tolower(x);
            }
            else if(x>='0' && x<='9') forward += x;
        }

        string backward = forward;
        reverse(backward.begin(),backward.end());

        return forward==backward;
    }
};