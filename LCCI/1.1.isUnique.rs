impl Solution {
    pub fn is_unique(astr: String) -> bool {
        let mut vec = vec![0; 26];

        for c in astr.chars() {
            vec[((c as i32) - ('a' as i32)) as usize] = vec[((c as i32) - ('a' as i32)) as usize] + 1;
            if (vec[((c as i32) - ('a' as i32)) as usize] >= 2) {
                return false;
            }
        }

        return true;
    }
}