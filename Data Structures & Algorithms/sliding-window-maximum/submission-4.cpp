class Solution {
public:
    using vi=std::vector<int>;
    // vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    //     k=size_t(k);
    //     std::vector<int> res;    
    //     res.reserve(nums.size()-k);
    //     if(k==1){return nums;}
    //     if(k==nums.size()){
    //         res.push_back(*std::max_element(nums.begin(), nums.end())); 
    //         return res;
    //     }
    //     using pis=std::pair<int,size_t>;
    //     std::priority_queue<pis> maxq_k;
    //     maxq_k.emplace(pis(nums[0], size_t(0)));
    //     for(size_t i=1;i<nums.size();++i){
    //         maxq_k.emplace(pis(nums[i],i));
    //         if(i>=k-1){
    //             pis tmp=maxq_k.top();
    //             // std::cout<<tmp.second<<", i-k="<<i-k<<"\n";
    //             while(tmp.second<(i-k+1)){
    //                 maxq_k.pop();
    //                 tmp=maxq_k.top();
    //             }
    //             res.push_back(tmp.first);
    //         }
    //     }
    //     return res;
    // }

    vi maxSlidingWindow(const vi& nums, int k){
        vi res;
        res.reserve(nums.size()-k+1);
        if(k==1){return nums;}
        if(k==nums.size()){
            res.push_back(*std::max_element(nums.begin(), nums.end()));
            return res;
        }
        std::deque<int> maxs;
        maxs.push_back(nums[0]);
        // std::cout<<maxs.front()<<", nums[0]="<<nums[0]<<'\n';
        for(size_t i=1;i<nums.size();i++){
            while(!maxs.empty() && nums[i]>maxs.back()){
                maxs.pop_back();
            }
            maxs.push_back(nums[i]);
            
            // std::cout<<maxs.front()<<","<<maxs.back()<<'\n';
            if(i>=k-1){
                if(i>=k && maxs.front()==nums[i-k]){
                    maxs.pop_front();
                }
                res.push_back(maxs.front());
            }
        }
        return res;
    }

};
// k=3
// nums: 1 1 3 2 2 1 1 1 1 4 7 5 6 
// maxs: 4

//3 2 