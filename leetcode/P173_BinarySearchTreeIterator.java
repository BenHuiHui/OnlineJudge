import java.util.Stack;

/**
 * Created by huihui on 19/3/16.
 */
public class BSTIterator {

    Stack<TreeNode> st;

    public BSTIterator(TreeNode root) {
        st = new Stack<TreeNode>();
        while(root != null){
            st.push(root);
            root = root.left;
        }
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return st.size()>0;
    }

    /** @return the next smallest number */
    public int next() {
        TreeNode nextMin = st.peek();
        st.pop();
        TreeNode right = nextMin.right;
        while(right != null){
            st.push(right);
            right = right.left;
        }
        return nextMin.val;
    }

}
