package leetcode;

import leetcode.leetcode_util.TreeNode;

import java.util.*;


//Error: 1. null 2. line 38 should not be else if

public class P257_BinaryTreePaths {

    public List<String> binaryTreePaths(TreeNode root) {

        if (root == null) return new ArrayList<String>();

        List<String> result = new ArrayList<String>();
        binaryTreePaths(root, "", result);
        return result;
    }

    public void binaryTreePaths(TreeNode node, String s, List<String> results){
        if (node == null){
            results.add(s);
        }
        else{

            if (s.length() <= 0)
                s = ""+node.val;
            else
                s = s+"->"+node.val;

            //left
            if (node.left == null && node.right == null){
                results.add(s);
            }
            if (node.left != null)
                binaryTreePaths(node.left, s, results);
            if (node.right != null)
                binaryTreePaths(node.right, s, results);
        }
    }

}
