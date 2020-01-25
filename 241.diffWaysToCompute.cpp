class Solution {
public:
    vector<int> dfs(vector<char> ops, vector<int> nums) {
        vector<int> tmp;
        if (ops.size() == 0) {
            tmp.push_back(nums[0]);
            return tmp;
        }

        for (int i = 0; i < ops.size(); i++) {
            vector<char> ops1;
            vector<char> ops2;
            vector<int> nums1;
            vector<int> nums2;
            
            for (int j = 0; j < i; j++) {
                ops1.push_back(ops[j]);
                nums1.push_back(nums[j]);
            } 
            nums1.push_back(nums[i]);
            for (int j = i+1; j < ops.size(); j++) {
                ops2.push_back(ops[j]);
                nums2.push_back(nums[j]);
            }
            nums2.push_back(nums[nums.size()-1]);

            switch(ops[i]) {
                case '*': {
                    for (auto part1: dfs(ops1, nums1)) {
                        for (auto part2: dfs(ops2, nums2)) {
                            tmp.push_back(part1*part2);
                        }
                    }
                    break;
                }
                case '+': {
                    for (auto part1: dfs(ops1, nums1)) {
                        for (auto part2: dfs(ops2, nums2)) {
                            tmp.push_back(part1+part2);
                        }
                    }
                    break;
                }
                case '-': {
                    for (auto part1: dfs(ops1, nums1)) {
                        for (auto part2: dfs(ops2, nums2)) {
                            tmp.push_back(part1-part2);
                        }
                    }
                    break;
                }
                case '/': {
                    for (auto part1: dfs(ops1, nums1)) {
                        for (auto part2: dfs(ops2, nums2)) {
                            if (part2 != 0) tmp.push_back(part1/part2);
                        }
                    }
                    break;
                }
            }
        }   
        return tmp;
    }

    vector<int> diffWaysToCompute(string input) {
        if (input.size() == 0) {
            return vector<int>();
        }
        int pre = input[0]-'0';
        if (input.size() == 1) {
            return vector<int>{pre};
        }

        vector<char> ops;
        vector<int> nums;

        for (int i = 1; i < input.size(); i++) {
            if (input[i]!='*'&&input[i]!='/'&&input[i]!='+'&&input[i]!='-') {
                pre *= 10;
                pre += input[i]-'0';
            } else {
                ops.push_back(input[i]);
                nums.push_back(pre);
                pre = 0;
            }
        }
        nums.push_back(pre);

        return dfs(ops, nums);
    }
};