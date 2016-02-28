import apple.laf.JRSUIUtils;

/**
 * Created by huihui on 28/2/16.
 */
public class P101_SymmetricTree {

public boolean isSymmetric(TreeNode root) {

        if (root == null) return true;
        return isSymmetric(root.left, root.right);
}

        public boolean isSymmetric(TreeNode left, TreeNode right){
                if (left == null && right == null) return true;
                if (left == null || right == null) return false;

                return isSame(left, right) && isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
        }

    public boolean isSame(TreeNode node1, TreeNode node2){
            if (node1 == null && node2 == null) return true;
            return node1!=null && node2!=null && node1.val == node2.val;
    }

}
