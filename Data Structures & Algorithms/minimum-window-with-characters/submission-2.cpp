class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size() || t=="" ){return "";}
        std::unordered_map<char, int>cnt_map(t.size());
        for(size_t i=0;i<t.size();i++){
            cnt_map[t[i]]++;
        }

        size_t min_len=s.size()+1;
        std::unordered_map<char, int>tmp_cnt_map;
        tmp_cnt_map.reserve(cnt_map.size());
        size_t l, r, l_nxt;
        l=0; r=0; l_nxt=0;
        std::string ans="";
        // std::cout<<tmp_cnt_map.size()<<std::endl;
        tmp_cnt_map=cnt_map;
        // std::cout<<tmp_cnt_map.size()<<std::endl;
        while(l+t.size()<=s.size()){
            r=l;
            tmp_cnt_map=cnt_map;
            std::cout<<tmp_cnt_map.size()<<std::endl;
            while(r<s.size()&& tmp_cnt_map.size()){
                if(tmp_cnt_map.contains(s[r])){
                    tmp_cnt_map[s[r]]--;
                    if(tmp_cnt_map[s[r]]==0){tmp_cnt_map.erase(s[r]);}
                    std::cout<<tmp_cnt_map.size()<<std::endl;
                }
                else if(!cnt_map.contains(s[r])){l_nxt=r;}
                r++;
            }
            if(!tmp_cnt_map.size() && min_len>r-l){
                min_len= r-l;
                ans=s.substr(l,min_len);
            }
            l = std::max(l_nxt, l)+1;
            l_nxt=0;
        }
        return ans;
    }
};
