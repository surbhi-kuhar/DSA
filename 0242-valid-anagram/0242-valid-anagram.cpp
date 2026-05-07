class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        
        unordered_map<int,int>freq1,freq2;

        for(auto x:s){
            freq1[x]++;
        }

        for(auto y:t){
            freq2[y]++;
        }

        for(auto x:freq1){
            if(freq2.find(x.first)==freq2.end() || freq2[x.first]!=x.second) return false;
        }

        return true;
    }
};