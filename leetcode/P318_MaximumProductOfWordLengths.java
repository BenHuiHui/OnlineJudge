package leetcode;

import java.util.HashSet;

/*
Use bit to store !!!!!
 */

public class P318_MaximumProductOfWordLengths {

    public int maxProduct(String[] words) {

        int n = words.length;
        int[] elements = new int[n];
        for (int i=0;i<n;i++){
            for(int j=0;j<words[i].length();j++){
                elements[i] |= 1 << (words[i].charAt(j) - 'a');
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((elements[i] & elements[j]) == 0)
                    ans = Math.max(ans,words[i].length() * words[j].length());
            }
        }
        return ans;

        /*
        int max = 0;

        for (int i = 0; i < words.length; i++) {
            for (int j = i+1; j < words.length; j++) {
                if (!hasCommChar(words[i], words[j])){
                    int prod = words[i].length() * words[j].length();

                    if (prod > max)
                        max = prod;

                }
            }
        }

        return max;
        */
    }

    public boolean hasCommChar(String s1, String s2){
        HashSet<Character> occ = new HashSet<Character>();

        for (int i = 0; i < s1.length(); i++) {
            occ.add(s1.charAt(i));
        }

        for (int i = 0; i < s2.length(); i++) {
            if (occ.contains(s2.charAt(i)))
                return true;
        }

        return false;
    }

}
