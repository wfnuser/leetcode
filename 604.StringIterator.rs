struct StringIterator {
    cv: Vec<char>,
    nv: Vec<i32>,
    index: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl StringIterator {

    fn new(compressedString: String) -> Self {
        let mut cv = vec![];
        let mut nv = vec![];
        let mut index = 0;

        let mut num = 0;

        for ch in compressedString.chars() {
            if ch >= '0' && ch <= '9' {
              num *= 10;
              num += (ch as i32 - '0' as i32);
            } else {
              if num != 0 {
                nv.push(num);
                num = 0;
              }
              cv.push(ch);
            }
        }

        nv.push(num);

        Self {
          cv,
          nv,
          index,
        }
    }
    
    fn next(&mut self) -> char {
      if !self.has_next() {
        return ' ';
      }

      let c: char = self.cv[self.index];
      self.nv[self.index] -= 1;
      if self.nv[self.index] == 0 {
        self.index = self.index + 1;
      }
      c
    }
    
    fn has_next(&self) -> bool {
      self.index < self.cv.len() && self.nv[self.index] > 0
    }
}

/**
 * Your StringIterator object will be instantiated and called as such:
 * let obj = StringIterator::new(compressedString);
 * let ret_1: char = obj.next();
 * let ret_2: bool = obj.has_next();
 */