func moveZeroes(nums []int)  {
    length := len(nums)
    temp := 0
    if length == 0 {
        return
    }
    for i := 0; i < length; i++ {
        if nums[i] != 0 {
            nums[i], nums[temp] = nums[temp], nums[i]
            temp++
        }
    }
    return
}