package leetcode;

import leetcode.leetcode_util.TreeNode;

/**
 * Created by huihui on 7/2/16.
 */
public class P236_LowestCommonAncestorOfABinaryTree {

    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {

        if (root == p) return p;
        if (root == q) return q;
        if (root == null) return null;

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        if (left != null && right != null)
            return root;

        else if (left != null)
            return left;

        else if (right != null)
            return right;

        else
            return null;

    }

}
