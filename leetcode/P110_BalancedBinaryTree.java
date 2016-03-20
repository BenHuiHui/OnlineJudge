/**
 * Created by huihui on 20/3/16.
 */
public class P110_BalancedBinaryTree {

    public boolean isBalanced(TreeNode root) {
        return height(root) != -1;
    }

    private int height(TreeNode node){

        if (node == null) return 0;
        int left = height(node.left);
        int right = height(node.right);

        if(left == -1 || right == -1) return -1;
        if(left-right > 1 || left - right < -1) return -1;
        return left > right ? left+1 : right +1;

    }

}
