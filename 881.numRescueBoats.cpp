class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int l = 0;
        int r = people.size() - 1;
        int boats = 0;

        while (l <= r) {
            // 特判： 只剩一个人了 直接上船
            if (l == r) {boats++; break;}
            // 两个人可以一起上船 就一起上船
            if (people[l] + people[r] <= limit) {
                // l++ 表示左边的人上船
                l++;
            }
            // r--表示右边的人上船 不管两个人是否能一起上船，右边的人一定会上船
            r--;
            boats++;
        }

        return boats;
    }
};
