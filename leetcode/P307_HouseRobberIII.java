/**
 * Created by huihui on 20/3/16.
 */
public class P307_HouseRobberIII {

    public int rob(TreeNode root) {
        HashMap<TreeNode, Integer>cache = new HashMap<TreeNode, Integer>();

        return rob(root, true, cache);
    }

    public int rob(TreeNode node, boolean canBeRobbed, HashMap<TreeNode, Integer>cache){

        if (node == null) return 0;

        if(canBeRobbed){
            Integer maxCache = cache.get(node);
            if (maxCache != null) return maxCache;
        }

        int max = Integer.MIN_VALUE;

        if(canBeRobbed){
            int max1 = node.val + rob(node.left, false, cache) + rob(node.right, false, cache);
            if (max1 > max) max = max1;
        }

        int max2 = rob(node.left, true, cache) + rob(node.right, true, cache);
        if (max2 > max) max = max2;

        if(canBeRobbed)
            cache.put(node, max);

        return max;
    }

}
