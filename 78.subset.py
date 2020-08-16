class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)

        def helper(i, res):
            if i >= n:
                return res
            resL = len(res)
            for j in range(resL):
                each = res[j]
                tmp = each[:]
                tmp.append(nums[i])
                res.append(tmp)
            return helper(i+1, res)

        return helper(0, [[]])