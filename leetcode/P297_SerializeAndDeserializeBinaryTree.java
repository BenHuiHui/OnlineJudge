import java.util.List;
import java.util.Vector;

/**
 * Created by huihui on 12/3/16.
 */
public class P297_SerializeAndDeserializeBinaryTree {

    public class Codec {

        // Encodes a tree to a single string.
        public String serialize(TreeNode root) {

            if (root == null) return "#";

            String self = root.val+"";
            String left = serialize(root.left);
            String right = serialize(root.right);
            return self+","+left+","+right;
        }

        // Decodes your encoded data to tree.
        public TreeNode deserialize(String data) {

            List<String>d = new Vector<String>();
            String[] indi = data.split(",");

            for (String s:indi) {
                d.add(s);
            }

            return deserialize(d);
        }

        public TreeNode deserialize(List<String> data){

            if (data.size()<=0)return null;
            if (data.get(0).equals("#")){
                data.remove(0);
                return null;
            }

            TreeNode node = new TreeNode(Integer.parseInt(data.get(0)));
            data.remove(0);
            node.left = deserialize(data);
            node.right = deserialize(data);
            return node;
        }
    }

}
