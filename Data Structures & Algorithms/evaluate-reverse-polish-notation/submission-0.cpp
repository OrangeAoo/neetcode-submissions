class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> nums;
        int ans=0;
        for(size_t i=0;i<tokens.size();++i){
            if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
               nums.push(std::stoi(tokens[i]));
            }
            else{
                int b=nums.top();
                nums.pop();
                int a=nums.top();
                nums.pop();
                if(tokens[i]=="+"){
                    nums.push(a+b);
                } 
                else if(tokens[i]=="-"){
                    nums.push(a-b);
                }   
                else if(tokens[i]=="*"){
                    nums.push(a*b);
                } 
                else if(tokens[i]=="/"){
                    nums.push(std::floor(a/b));
                }  
            }
        }
        return nums.top();
    }
};
