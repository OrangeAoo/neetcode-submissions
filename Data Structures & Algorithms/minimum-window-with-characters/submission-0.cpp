class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()){return "";}
        std::unordered_map<char, int>cnt_map(t.size());
        for(size_t i=0;i<t.size();i++){
            cnt_map[t[i]]++;
        }

        size_t min_len=s.size();
        std::unordered_map<char, int>tmp_cnt_map(cnt_map.size());
        size_t l=0; size_t r=0;
        std::string ans="";
        while(l+t.size()<=s.size()){
            r=l;
            tmp_cnt_map=cnt_map;
            while(r<s.size()&&tmp_cnt_map.size()){
                if(tmp_cnt_map.contains(s[r])){
                    tmp_cnt_map.erase(s[r]);
                }
            }
            if(!tmp_cnt_map.size() && min_len>r-l+1){
                min_len= r-l+1;
                ans=s.substr(l,min_len);
            }
            l++;
        }
        return ans;
    }
};
