package leetcode;

import leetcode.leetcode_util.TreeNode;

/**
 * Created by huihui on 7/2/16.
 */
public class P230_KthSmallestElementInABST {

    //Return number of nodes of the subtree
    public int kthSmallest(TreeNode root, int k) {

        int[] arr = new int[1];
        kthSmallest(root, 0, k ,arr);
        return arr[0];
    }

    public int kthSmallest(TreeNode root, int parent, int k, int[] arr){

        if (root == null) return 0;

        int left = kthSmallest(root.left, parent, k, arr);

        if (left +parent == k-1)
            arr[0] = root.val;

        int right = kthSmallest(root.right, left+parent+1, k, arr);

        return left + right + 1;
    }

}
