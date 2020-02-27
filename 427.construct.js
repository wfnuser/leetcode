/**
 * // Definition for a QuadTree node.
 * function Node(val,isLeaf,topLeft,topRight,bottomLeft,bottomRight) {
 *    this.val = val;
 *    this.isLeaf = isLeaf;
 *    this.topLeft = topLeft;
 *    this.topRight = topRight;
 *    this.bottomLeft = bottomLeft;
 *    this.bottomRight = bottomRight;
 * };
 */
/**
 * @param {number[][]} grid
 * @return {Node}
 */

var construct = function(grid) {
  root = new Node();
  if (grid.length == 0) {
    return root;
  }
  if (grid.length == 1) {
    if (grid[0][0] == 1) {
      root.val = 1;
    } else {
      root.val = 0;
    }
    root.isLeaf = 1;
    return root;
  }

  let dp = [];

  for (let i = 0; i <= grid.length; i++) {
    dp[i] = [];
    for (let j = 0; j <= grid.length; j++) {
      if (i === 0 || j === 0) {
        dp[i][j] = 0;
      } else {
        dp[i][j] =
          dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + grid[i - 1][j - 1];
      }
    }
  }

  function helper(sx, sy, ex, ey) {
    sx = Math.floor(sx);
    sy = Math.floor(sy);
    ex = Math.floor(ex);
    ey = Math.floor(ey);

    let S = sum(sx, sy, ex, ey);
    if (S === 0 || S === (ex - sx + 1) * (ey - sy + 1)) {
      return new Node(S > 0, 1, null, null, null, null);
    }

    return new Node(
      1,
      0,
      helper(sx, sy, (sx + ex) / 2, (sy + ey) / 2),
      helper(sx, (sy + ey) / 2 + 1, (sx + ex) / 2, ey),
      helper((sx + ex) / 2 + 1, sy, ex, (sy + ey) / 2),
      helper((sx + ex) / 2 + 1, (sy + ey) / 2 + 1, ex, ey)
    );
  }

  function sum(sx, sy, ex, ey) {
    return dp[ex + 1][ey + 1] - dp[sx][ey + 1] - dp[ex + 1][sy] + dp[sx][sy];
  }

  return helper(0, 0, grid.length - 1, grid.length - 1);
};
