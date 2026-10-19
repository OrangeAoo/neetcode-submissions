class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<size_t>ids;
        std::vector<int> res(temperatures.size(),0);

        for(size_t i=0;i<temperatures.size();++i){
            while(!ids.empty() && \
            temperatures[ids.top()]<temperatures[i]){
                size_t idx=ids.top();
                res[idx]=int(i-idx);
                ids.pop();
            }
            ids.push(i);
        }
        while(!ids.empty()){
            size_t idx=ids.top();
            res[idx]=int(0);
            ids.pop();
        }
        return res;
    }
};
