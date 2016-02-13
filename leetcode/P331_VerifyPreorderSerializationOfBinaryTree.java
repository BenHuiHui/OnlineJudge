package leetcode;

import java.util.Stack;

/**
 * Created by huihui on 3/2/16.
 */

//Corner case
//    "#"
//    "#, #"
//    Error encountered: stack becomes size 0 => false

public class P331_VerifyPreorderSerializationOfBinaryTree {

    public boolean isValidSerialization(String preorder) {

        Stack<Integer> st = new Stack<Integer>();

        String[] inputs = preorder.split(",");


        if (inputs.length == 1){
            if (inputs[0].equals("#"))
                return true;
            else
                return false;
        }

        for (int i = 0; i < inputs.length; i++) {
            String val = inputs[i];

            if (val.equals("#")){

                if (st.size() <= 0) return false;

                while  (st.size() > 0 && st.peek() == 1){
                    st.pop();
                }

                if (st.size() > 0 && st.pop() == 0)
                    st.push(1);

                if (st.size() <= 0 && i != inputs.length - 1) return false;

            }

            else{
                st.push(0);
            }

        }

        return st.size() == 0;
    }

    public static void main (String[] args){
        //String a = "9,3,4,#,#,1,#,#,2,#,6,#,#";

        String a = "9,3,4,#,#,1,#,#,#,2,#,6,#,#";

        P331_VerifyPreorderSerializationOfBinaryTree p = new P331_VerifyPreorderSerializationOfBinaryTree();

        System.out.println(p.isValidSerialization(a));
    }


}
