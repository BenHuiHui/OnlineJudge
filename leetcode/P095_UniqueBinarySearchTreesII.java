import java.util.ArrayList;
import java.util.List;

/**
 * Created by huihui on 27/2/16.
 */
public class P095_UniqueBinarySearchTreesII {

    public List<TreeNode> generateTrees(int n) {
        List<TreeNode> roots = new ArrayList<TreeNode>();

        roots = generateTrees(1, n);

        if (roots.size() == 1 && roots.get(0) == null)
            return new ArrayList<TreeNode>();

        return roots;
    }

    public List<TreeNode> generateTrees(int left, int right){

        List<TreeNode> results = new ArrayList<TreeNode>();

        if (left > right) {
            results.add(null);
            return results;
        }

        if (left == right) {
            results.add(new TreeNode(left));
            return results;
        }

        for (int i = left; i <= right ; i++) {

            List<TreeNode> lefttree = generateTrees(left, i-1);
            List<TreeNode> righttree = generateTrees(i+1, right);

            //Combine all the possible combinations

            for (int j = 0; j < lefttree.size(); j++) {

                for (int k = 0; k < righttree.size(); k++) {

                    TreeNode node = new TreeNode(i);
                    node.left = lefttree.get(j);
                    node.right = righttree.get(k);
                    results.add(node);
                }
            }
        }

        return results;
    }

}
