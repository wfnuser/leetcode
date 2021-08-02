/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int rob(TreeNode root) {
        int[] res = robNode(root);
        return Math.max(res[0], res[1]);
    }

    public int[] robNode(TreeNode node) {
        if (node == null) return new int[]{0,0};
        int[] left = robNode(node.left);
        int[] right = robNode(node.right);

        int r1 = node.val + left[0] + right[0];
        int r2 = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);

        return new int[]{r2, r1};
    }
}
