class Solution {
public:
    bool isValid(string s) {
        if(s[0]==')'||s[0]==']'||s[0]=='}') return false;
        if(s.size()%2) return false;
        std::string ss(1,s[0]);
        for(size_t i=1;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){ss+=s[i];continue;}
            if(ss.back()=='(' && s[i]==')'){ss.pop_back();continue;}
            if(ss.back()=='[' && s[i]==']'){ss.pop_back();continue;}
            if(ss.back()=='{' && s[i]=='}'){ss.pop_back();continue;}
            return false;
        }
        return ss.size()==0;
    }
};
