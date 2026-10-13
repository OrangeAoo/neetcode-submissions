class Solution {
public:
    // string minWindow(string s, string t) {
    //     if(s.size()<t.size() || t=="" ){return "";}
    //     std::unordered_map<char, int>cnt_map(t.size());
    //     for(size_t i=0;i<t.size();i++){
    //         cnt_map[t[i]]++;
    //     }

    //     size_t min_len=s.size()+1;
    //     std::unordered_map<char, int>tmp_cnt_map;
    //     tmp_cnt_map.reserve(cnt_map.size());
    //     size_t l, r, l_nxt;
    //     l=0; r=0; l_nxt=0;
    //     std::string ans="";
    //     // std::cout<<tmp_cnt_map.size()<<std::endl;
    //     tmp_cnt_map=cnt_map;
    //     // std::cout<<tmp_cnt_map.size()<<std::endl;
    //     while(l+t.size()<=s.size()){
    //         r=l;
    //         tmp_cnt_map=cnt_map;
    //         // std::cout<<tmp_cnt_map.size()<<std::endl;
    //         while(cnt_map.contains(s[l]) && r<s.size()&& tmp_cnt_map.size()){
    //             if(tmp_cnt_map.contains(s[r])){
    //                 tmp_cnt_map[s[r]]--;
    //                 if(tmp_cnt_map[s[r]]==0){tmp_cnt_map.erase(s[r]);}
    //                 // std::cout<<tmp_cnt_map.size()<<std::endl;
    //             }
    //             else if(!cnt_map.contains(s[r]) && !l_nxt){l_nxt=r;}
    //             r++;
    //         }
    //         if(!tmp_cnt_map.size() && min_len>r-l){
    //             min_len= r-l;
    //             ans=s.substr(l,min_len);
    //         }
    //         l = (l_nxt>l)? l_nxt+1 : l+1;
    //         l_nxt=0;
    //     }
    //     return ans;
    // }
    string minWindow(string s, string t) {
        std::string ans = "";
        std::unordered_map<char,int>ms, mt;
        mt.reserve(53); ms.reserve(53);
        for(size_t i=0;i<t.size();++i){
            mt[t[i]]++;
        }
        size_t l, r, rest_cnt, min_len;
        rest_cnt=mt.size(); 
        l=0;r=s.size()-1;
        //trim s
        if(r==l && s!=t){return ans;}
        while(l<=r){
            if(mt.contains(s[l]) && mt.contains(s[r])){break;}
            if(!mt.contains(s[l])){l++;}
            if(!mt.contains(s[r])){r--;}
        }
        if(r<l || r-l+1<t.size()){return ans;}
        s=s.substr(l,r-l+1);
        std::cout<<s<<"\n";
        
        l=0;r=0;min_len=s.size()+1;
        while(l+t.size()<=s.size() && r<s.size()){
            while(rest_cnt>0&&r<s.size()){
                if(!mt.contains(s[r])){r++; continue;}
                ms[s[r]]++;
                if(mt[s[r]]==ms[s[r]]){rest_cnt--;}
                r++;
            }
            while(!mt.contains(s[l]) || ms[s[l]]>mt[s[l]]){
                if(mt.contains(s[l])){ms[s[l]]--;}
                l++;
            }
            // std::cout<<'('<<l<<','<<r<<"), #rest="<<rest_cnt<<"\n";
            if(rest_cnt==0 && min_len >r-l){
                min_len=r-l;
                ans=s.substr(l,min_len);
                if(min_len==t.size()){break;}
            }
            // pop s[l] out of ms;
            ms[s[l]]--;
            rest_cnt++;
            l++;
        }
        return ans;
    }
};
