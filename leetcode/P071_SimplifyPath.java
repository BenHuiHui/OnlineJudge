package leetcode;

import java.util.Scanner;
import java.util.Stack;

/*
Corner cases: 1. 2 corner cases listed in the problems
2. Empty input
 */
public class P071_SimplifyPath {

    public String simplifyPath(String path) {

        String[] paths = path.split("/");
        Stack<String> st = new Stack<String>();

        for (int i = 0; i < paths.length; i++) {

            if (paths[i].equals("..")) {
                if (st.size() > 0)
                    st.pop();
            }
            /*
            else if (paths[i].equals(".."))
                st = new Stack<String>();
            */
            else if (paths[i].length() > 0 && !paths[i].equals("."))
                st.push(paths[i]);

        }

        String s = "";
        while (!st.empty()){
            s = "/"+st.pop()+s;
        }



        if (s.length() <= 0)
            s = "/";

        return s;
    }

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);

        P071_SimplifyPath p = new P071_SimplifyPath();

        String s = in.next();
        System.out.println(p.simplifyPath(s));
    }

}
