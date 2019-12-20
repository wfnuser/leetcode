var countAndSay = function(n) {
    let prev = '1'
    for(let i = 1; i < n; i++){
        console.log(i, "terms: ")
        prev = prev.replace(/(\d)\1*/g, item =>{
            console.log(item);
            return `${item.length}${item[0]}`
        })
    }
    return prev
};

countAndSay(10);

// 作者：wangquanfugui12138
// 链接：https://leetcode-cn.com/problems/count-and-say/solution/tong-guo-zheng-ze-he-bing-xiang-tong-yuan-su-wan-c/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。