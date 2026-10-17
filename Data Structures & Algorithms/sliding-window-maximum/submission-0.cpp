class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        k=size_t(k);
        std::vector<int> res;    
        res.reserve(nums.size()-k);
        if(k==1){return nums;}
        if(k==nums.size()){
            res.push_back(*std::max_element(nums.begin(), nums.end())); 
            return res;
        }
        using pis=std::pair<int,size_t>;
        std::priority_queue<pis> maxq_k, popped;
        maxq_k.emplace(pis(nums[0], size_t(0)));
        for(size_t i=1;i<nums.size();++i){
            maxq_k.emplace(pis(nums[i],i));
            if(i>=k-1){
                pis tmp=maxq_k.top();
                // std::cout<<tmp.second<<", i-k="<<i-k<<"\n";
                while(tmp.second<(i-k+1)){
                    maxq_k.pop();
                    tmp=maxq_k.top();
                }
                res.push_back(tmp.first);
            }
        }
        return res;
    }
};
