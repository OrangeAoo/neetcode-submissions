class MinStack {
private:
    std::vector<int> values_;
    std::vector<int> vmin_; 
public:
    MinStack() {}
    // MinStack(size_t n_vals) {values_.reserve(n_vals);}
    // MinStack(std::vector<int> vals):values_{vals} {}
    // MinStack(std::initializer_list<int> vals) {values_=std::vector<int>(vals);}
    void push(int val) {
        if(values_.empty() || val<=vmin_.back()){vmin_.push_back(val);}
        values_.push_back(val);
    }
    
    void pop() {
        if(!values_.empty()){
            if(vmin_.back()==values_.back()){vmin_.pop_back();}
            values_.pop_back();
        }
    }
    
    int top() {
        if(!values_.empty()){return values_.back();}
        printf("Invalid for empty stack.\n");
        return 0;
    }
    
    int getMin() {
        if(!vmin_.empty()){return vmin_.back();}
        printf("Invalid for empty stack.\n");
        return 0;
    }
};
