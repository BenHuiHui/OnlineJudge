package leetcode;

import java.util.HashMap;
import java.util.HashSet;

/*
Error 'abba' 'dog dog dog dog'
 */
public class P290_WordPattern {

    public boolean wordPattern(String pattern, String str) {

        String[] words = str.split(" ");
        HashMap<Character, String> ptr = new HashMap<Character, String>();
        HashSet<String> occu = new HashSet<String>();


        if (words.length != pattern.length())
            return false;

        for (int i = 0; i < pattern.length(); i++) {
            char c = pattern.charAt(i);

            if (ptr.get(c) == null) {
                if (occu.contains(words[i]))
                    return false;
                occu.add(words[i]);
                ptr.put(c, words[i]);
            }
            else{
                if (!ptr.get(c).equals( words[i]))
                    return false;
            }

        }

        return true;
    }

}
