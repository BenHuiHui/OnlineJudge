package leetcode;

import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by huihui on 4/2/16.
 */
public class P242_ValidAnagram {

    public boolean isAnagram(String s, String t) {

        if (s.length() != t.length()) return false;

        HashMap<Character, Integer> occ = new HashMap<Character, Integer>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            Integer val = occ.get(c);
            if (val == null)
                val = 0;
            val ++;
            occ.put(c, val);
        }

        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);

            Integer val = occ.get(c);

            if (val == null || val < 1){
                return false;
            }

            val --;

            if (val >= 1)
                occ.put(c, val);
            else
                occ.remove(c);

        }

        return occ.size() == 0;

    }

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);

        String s = in.next();
        String t = in.next();

        P242_ValidAnagram p = new P242_ValidAnagram();
        System.out.println(p.isAnagram(s, t));
    }

}
