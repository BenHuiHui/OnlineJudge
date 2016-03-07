import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/**
 * Created by huihui on 29/2/16.
 */

/*
Key here is to convert infix to postfix expression
 */

public class P224_BasicCalculator {

    public int calculate(String s) {
        List<String> infix = infixFromString(s);
        List<String> postfix = postfix(infix);
        return evaluatePostfix(postfix);
    }

    List<String> infixFromString(String s){

        List<String> infix = new ArrayList<String>();

        String num = "";

        for (int i = 0; i < s.length(); i++) {

            if (s.charAt(i) == ' ') {

                if (!num.equals("")){
                    infix.add(num);
                    num = "";
                }

            }

            else if (s.charAt(i) <= '9' && s.charAt(i) >= '0'){
                num += s.charAt(i);
            }

            //operands & brackets
            else{

                if (!num.equals("")){
                    infix.add(num);
                    num = "";
                }

                String op = ""+s.charAt(i);
                infix.add(op);
            }

        }

        if (!num.equals(""))
            infix.add(num);

        return infix;
    }


    //Convert an infix expression to postfix expression
    public List<String> postfix(List<String> infix){

        List<String>post = new ArrayList<String>();
        Stack<String> st = new Stack<String>();

        for (int i = 0; i < infix.size(); i++) {

            String op = infix.get(i);

            //Operator

            //Push left bracket
            if (op.equals("(")){
                st.push(op);
            }

            //Pop all operators between brackets
            else if (op.equals(")")){

                while (!st.peek().equals("(")){
                    post.add(st.peek());
                    st.pop();
                }

                st.pop();
            }

            else if (op.equals("+") || op.equals("-")
                    || op.equals("*") || op.equals("/")){

                while (st.size() > 0){

                    String top = st.peek();

                    //Lower precedence
                    if (precedence(op) - precedence(top) <= 0){
                        post.add(top);
                        st.pop();
                    }
                    else
                        break;

                }

                st.push(op);
            }

            // Operand
            else{
                post.add(op);
            }

        }

        //Add the remaining operators
        while (st.size() > 0){
            post.add(st.peek());
            st.pop();
        }

        return post;
    }

    public int evaluatePostfix(List<String> postfix){

        Stack<Integer> st = new Stack<Integer>();

        for (int i = 0; i < postfix.size(); i++) {

            String op = postfix.get(i);

            if (isInteger(op)){
                st.add(Integer.parseInt(op));
            }

            else{

                int right = st.peek();
                st.pop();
                int left = st.peek();
                st.pop();

                if (op.equals("+"))
                    st.push(left + right);

                else if (op.equals("-"))
                    st.push(left - right);

                else if (op.equals("*"))
                    st.push(left * right);

                else if (op.equals("/"))
                    st.push(left / right);
            }
        }

        return st.peek();
    }

    public  boolean isInteger(String s) {
        try {
            Integer.parseInt(s);
        } catch(NumberFormatException e) {
            return false;
        } catch(NullPointerException e) {
            return false;
        }
        // only got here if we didn't return false
        return true;
    }

    public int precedence(String operator){
        if (operator.equals("+") || operator.equals("-"))
            return 1;
        if (operator.equals("*") || operator.equals("/"))
            return 2;

        return -1;
    }

    public static void main(String[] args) {
        P224_BasicCalculator p = new P224_BasicCalculator();
        String formula = " 2-1 + 2 ";
        System.out.print(p.calculate(formula));
    }
}
