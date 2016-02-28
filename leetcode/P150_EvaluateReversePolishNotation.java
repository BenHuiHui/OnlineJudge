import java.util.Stack;

/**
 * Created by huihui on 28/2/16.
 */
public class P150_EvaluateReversePolishNotation {

    public int evalRPN(String[] tokens) {
        Stack<Integer> st = new Stack<Integer>();

        for (int i=0; i<tokens.length; i++){

            if (tokens[i].equals("+")){
                int right = st.peek();
                st.pop();
                int left = st.peek();
                st.pop();
                st.push(left + right);
            }

            else if (tokens[i].equals("-")){
                int right = st.peek();
                st.pop();
                int left = st.peek();
                st.pop();
                st.push(left - right);
            }

            else if (tokens[i].equals("*")){
                int right = st.peek();
                st.pop();
                int left = st.peek();
                st.pop();
                st.push(left * right);
            }

            else if (tokens[i].equals("/")){
                int right = st.peek();
                st.pop();
                int left = st.peek();
                st.pop();
                st.push(left / right);
            }

            else{
                st.push(Integer.parseInt(tokens[i]));
            }
        }

        return st.peek();
    }

}
