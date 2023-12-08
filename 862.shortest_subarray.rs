use std::collections::VecDeque;

impl Solution {
    pub fn shortest_subarray(nums: Vec<i32>, k: i32) -> i32 {
      let n = nums.len();
      let mut presum = vec![0; n + 1];
      let mut ans: i32 = i32::MAX;

      // i .. j = presum[j+1] - presum[i]
      for i in 0..n {
        presum[i+1] = presum[i] + nums[i] as i64;
      }

      let mut q: VecDeque<usize> = VecDeque::new();

      for i in 0..n {
        if nums[i] >= k {
          return 1;
        }

        while let Some(&front) = q.front() {
          if presum[i+1] - presum[front] >= k as i64 {
            ans = ans.min(i as i32 - front as i32 + 1);
            q.pop_front();
          } else {
            break;
          }
        }

        while let Some(&back) = q.back() {
          if presum[i] > presum[back] {
            break;
          }
          q.pop_back();
        }

        q.push_back(i);
      }

      if ans > n as i32 {
        -1
      } else {
        ans
      }
    }
}