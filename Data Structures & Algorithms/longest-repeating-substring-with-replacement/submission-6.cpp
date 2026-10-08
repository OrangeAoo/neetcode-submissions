class Solution {
public:
/*
    int characterReplacement(string s, int k) {
        std::unordered_map<char,int>cnt_dict(26);
        int max_strike =0;
        for(size_t i=0;i<s.size();i++){
            for(size_t k=0;k<26;k++){
                char c='A'+k;
                cnt_dict[c]=0;
                // cout<<c<<" "<<cnt_dict[c]<<"\n";
            }
            int max_cnt=-1;
            for(size_t j=i;j<s.size();j++){
                cnt_dict[s[j]]++;
                int len=1+j-i;
                // cout<<s[j]<<" "<<cnt_dict[s[j]]<<"\n";
                max_cnt=std::max(max_cnt, cnt_dict[s[j]]);
                // cout<<s[j]<<" "<<cnt_dict[s[j]]<<" max_cnt="<<max_cnt<<" len="<<len<<"\n";
                
                // min_chg=std::min(min_chg, len-cnt_dict[s[j]]);
                if(len-max_cnt<=k){max_strike=std::max(max_strike, len);}
            }
        }
        return max_strike;
    }
*/
    int characterReplacement(string s, int k) {
        std::unordered_map<char,int>cnt_dict(26);
        for(size_t i=0;i<26;i++){
            char c='A'+i;
            cnt_dict[c]=0;
        }
        size_t l=0; size_t r=0; cnt_dict[s[l]]=1;
        int max_cnt=1; 
        int res=1;
        while(l<s.size()){
            while(int(r-l+1)-max_cnt<=k && r<s.size()){
                res=std::max(res, int(r-l+1));
                r++;
                cnt_dict[s[r]]++;
                max_cnt=std::max(max_cnt, cnt_dict[s[r]]);
                // cout<<"l="<<l<<",r="<<r<<" ("<<s[l]<<","<<s[r]<<") max_cnt="<<max_cnt<<" cnt_r="<<cnt_dict[s[r]]<<"\n";
            }
            cnt_dict[s[l]]--;
            l++;
            max_cnt=std::max_element(
                cnt_dict.begin(), cnt_dict.end(),
                [](const auto& a, const auto& b) {
                return a.second < b.second;
            })->second;
            // cout<<"l="<<l<<",r="<<r<<" ("<<s[l]<<","<<s[r]<<") max_cnt="<<max_cnt<<" cnt_l="<<cnt_dict[s[l]]<<"\n";
        }
        return res;
    }
};
