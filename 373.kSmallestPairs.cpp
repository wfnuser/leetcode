struct node
{
    int val, x, y;
    node(int val, int x, int y):val(val),x(x),y(y){}
};
 
struct cmp
{
    bool operator()(node a,node b)
    {
        return a.val >= b.val;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        if (nums1.size()==0 || nums2.size()==0) return res;
        priority_queue<node,vector<node>,cmp> pq;
        pq.push(node(nums1[0]+nums2[0], 0, 0));
        unordered_map<string, int> visited;

        for (int i = 0; i < k && !pq.empty(); i++) {
            node n = pq.top();
            pq.pop();
            int x = n.x;
            int y = n.y;
            visited[to_string(x)+"_"+to_string(y)] = 1;
            
            if (x+1<nums1.size() && !visited[to_string(x+1)+"_"+to_string(y)]) {
                pq.push(node(nums1[x+1]+nums2[y], x+1, y));
                visited[to_string(x+1)+"_"+to_string(y)] = 1;
            }
            if (y+1<nums2.size() && !visited[to_string(x)+"_"+to_string(y+1)]) {
                pq.push(node(nums1[x]+nums2[y+1], x, y+1));
                visited[to_string(x)+"_"+to_string(y+1)] = 1;
            }

            res.push_back(vector<int>{nums1[n.x], nums2[n.y]});
        }

        return res;
    }
};