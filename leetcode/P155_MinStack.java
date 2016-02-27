import java.util.Stack;

/**
 * Created by huihui on 27/2/16.
 */
public class P155_MinStack {

    private Stack<Integer> st;
    private Stack<Integer> minSt;

        public void push(int x) {

            if (st == null) st = new Stack<Integer>();
            if (minSt == null) minSt = new Stack<Integer>();

            st.push(x);
            if (minSt.size() <= 0) minSt.push(x);
            else {
                int cMin = minSt.peek();
                minSt.push(Math.min(x, cMin));
            }

        }

        public void pop() {
            st.pop();
            minSt.pop();
        }

        public int top() {
            return st.peek();
        }

        public int getMin() {
            return minSt.peek();
        }


}
