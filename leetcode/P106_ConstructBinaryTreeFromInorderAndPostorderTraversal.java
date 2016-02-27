/**
 * Created by huihui on 27/2/16.
 */
public class P106_ConstructBinaryTreeFromInorderAndPostorderTraversal {

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        return buildTree(inorder, postorder, 0, inorder.length-1, 0, postorder.length-1);
    }

    public TreeNode buildTree(int[] inorder, int[] postorder, int left1, int right1, int left2, int right2){

        if (left1 > right1) return null;
        if (left1 == right1) return new TreeNode(inorder[left1]);

        //Find mid point
        int mid = left1;
        while (inorder[mid] != postorder[right2]) mid++;
        TreeNode node = new TreeNode(inorder[mid]);

        node.left = buildTree(inorder, postorder, left1, mid-1, left2, left2+(mid-left1-1));
        node.right = buildTree(inorder, postorder, mid+1, right1, left2+(mid-left1), right2-1);

        return node;
    }

}
