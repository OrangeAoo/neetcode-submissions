class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t n=s.size();    
        if(n==0||n==1){return n;}            
        size_t l=0;
        int max_len=0;
        std::vector<bool>visited(256, false);
        for(size_t i=0;i<n;i++){
            unsigned char c = s[i];
            // while(visited[c]){
            //     visited[static_cast<unsigned char>(s[l])]=false;
            //     l++;
            // }
            if(visited[c]){
                std::fill(visited.begin(), visited.end(), false);
            }
            visited[c]=true;
            max_len=std::max(max_len, int(i-l+1));
        }
        return max_len;
    }
};
