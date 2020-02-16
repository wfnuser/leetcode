class PhoneDirectory {
public:

    int total = 0;
    unordered_map<int, int> m;

    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        total = maxNumbers;    
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        for (int i = 0; i < total; i++) {
            if (!m[i]) {
                m[i] = 1;
                return i;
            }
        }
        return -1;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        if (number>=total || number < 0) return false;
        return !m[number];

    }
    
    /** Recycle or release a number. */
    void release(int number) {
        m[number] = 0;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */