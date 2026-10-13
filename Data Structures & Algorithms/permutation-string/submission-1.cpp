class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()<s2.size()){return false;}
        std::unordered_map<char, int>s1_cnt_map(s1.size());
        for(size_t i=0;i<s1.size(); ++i){
            s1_cnt_map[s1[i]]++;
        }

        size_t l=0; size_t r=0;
        std::unordered_map<char, int>s2_substr_cnt_map(s1_cnt_map.size());
        while(l<=s2.size()-s1.size()){
            r=l;
            while(r<l+s1.size() && s2_substr_cnt_map[s2[r]]<s1_cnt_map[s2[r]]){
                s2_substr_cnt_map[s2[r]]++;
                r++;
            }
            if(r==l+s1.size()){
                return true;
            }
            l++;
            s2_substr_cnt_map.clear();
            s2_substr_cnt_map.reserve(s1_cnt_map.size());
        }
        return false;
    }
};
