struct MinStack {
    v: Vec<i32>,
    minv: Vec<i32>
}


/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MinStack {
    
    /** initialize your data structure here. */
    fn new() -> Self {
        Self{
            v: Vec::new(),
            minv: Vec::new(),
        }
    }
    
    fn push(&mut self, x: i32) {
        self.v.push(x);
        if (self.minv.len() == 0 || self.minv[self.minv.len()-1] > x) {
            self.minv.push(x);
        } else {
            self.minv.push(self.minv[self.minv.len()-1])
        }
    }
    
    fn pop(&mut self) {
        self.minv.pop();
        self.v.pop();
    }
    
    fn top(&self) -> i32 {
        return self.v[self.v.len()-1];
    }
    
    fn get_min(&self) -> i32 {
        return self.minv[self.minv.len()-1];
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * let obj = MinStack::new();
 * obj.push(x);
 * obj.pop();
 * let ret_3: i32 = obj.top();
 * let ret_4: i32 = obj.get_min();
 */