class ProductOfNumbers {
public:
    vector<int> products;
    vector<int> zero;
    
    ProductOfNumbers() {
        products = vector<int>();
    }
    
    void add(int num) {
        if (num == 0) {
            zero.push_back(zero.size());
            products.push_back(0);
        } else {
            if (products.empty()) products.push_back(num);
            else if (products.back() == 0) products.push_back(num); 
            else products.push_back(products.back()*num);
            
            if (zero.size()) zero.push_back(zero.back());
            else zero.push_back(-1);
        }
    }
    
    int getProduct(int k) {
        int last = zero.size()-1;
        if (zero[last] >= (zero.size()-k) && zero[last] != -1) {
            return 0;
        }
        if (products.size() == 1) return products[last];
        else if (last-k<0) return products[last];
        else if (products[last-k] == 0) return products[last];
        else return products[last]/products[last-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */