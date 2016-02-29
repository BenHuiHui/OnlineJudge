import java.util.HashMap;
import java.util.HashSet;

/**
 * Created by huihui on 29/2/16.
 */
public class P205_IsomorphicStrings {

    public boolean isIsomorphic(String s, String t) {

        if (s.length() != t.length()) return false;

        char[] tchar = t.toCharArray();
        HashMap<Character, Character> mapping = new HashMap<Character, Character>();
        HashSet<Character> used = new HashSet<Character>();

        for (int i = 0; i < s.length(); i++) {

            char tc = t.charAt(i);
            if (mapping.get(tc) != null)
                tchar[i] = mapping.get(tc);
            else{

                char sc = s.charAt(i);
                if (used.contains(sc))
                    return false;

                mapping.put(tc, sc);
                used.add(sc);
                tchar[i] = sc;
            }
        }

        for (int i = 0; i < tchar.length; i++) {
            if (tchar[i] != s.charAt(i))
                return false;
        }

        return true;
    }

}
