class Cashier {
public:
    int discount;
    int n;
    unordered_map<int, int> priceMap;
    int index = 0; // 用于标记第几个顾客
    
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this->n = n;
        this->discount = discount;
        
        for (int i = 0; i < products.size(); i++) {
            priceMap[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        index++;
        double sum = 0;
        for (int i = 0; i < product.size(); i++) {
            sum += priceMap[product[i]] * amount[i];
        }
        
        // 是否要打折
        if (index % n == 0) {
            sum = sum - (discount * sum) / 100;
        }
        
        return sum;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */