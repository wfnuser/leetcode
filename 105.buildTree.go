/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 func buildTree(preorder []int, inorder []int) *TreeNode {
    if len(preorder) == 0 {
        return nil;
    }

    var root TreeNode;
    
    if len(preorder) == 1 {
        root.Val = preorder[0];
        return &root;
    }

    for i := range inorder { 
        if (preorder[0] == inorder[i]) {
            inLeft := inorder[0:i]
            inRight := inorder[i+1:]
            preLeft := preorder[1:i+1]
            preRight := preorder[i+1:]

            root.Val = preorder[0]
            root.Left = buildTree(preLeft, inLeft)
            root.Right = buildTree(preRight, inRight)
            break;
        }
    }

    return &root;
}