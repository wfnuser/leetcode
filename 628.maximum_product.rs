impl Solution {
    pub fn maximum_product(nums: Vec<i32>) -> i32 {
        let (mut s1, mut s2, mut b1, mut b2, mut b3) = (i32::MAX, i32::MAX, i32::MIN, i32::MIN, i32::MIN);

        for n in nums {
            if n < s1 {
                s2 = s1;
                s1 = n;
            } else if n < s2 {
                s2 = n;
            }

            if n > b1 {
                b3 = b2;
                b2 = b1;
                b1 = n;
            } else if n > b2 {
                b3 = b2;
                b2 = n;
            } else if n > b3 {
                b3 = n;
            }
        }

        (s1 * s2 * b1).max(b2 * b3 * b1)
    }
}