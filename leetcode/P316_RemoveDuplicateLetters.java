import java.util.HashMap;

/**
 * Created by huihui on 28/2/16.
 */
public class P316_RemoveDuplicateLetters {

    public String removeDuplicateLetters(String s) {

        if (s.length() <= 0) return s;

        HashMap<Character, Integer> hm = new HashMap<Character, Integer>();
        for (int i=0; i<s.length(); i++){
            char c = s.charAt(i);

            Integer integer = hm.get(c);

            if (integer == null)
                integer = 0;

            integer ++;
            hm.put(c, integer);
        }

        //Create the string
        int start = 0;

        int minIndex = 0;
        char minChar = s.charAt(0);

        int strStart = 0;
        char[] newStr = new char[hm.size()];

        while (start < s.length()){

            char c = s.charAt(start);

            if (hm.get(c) == null){
                start ++;
                continue;
            }

            if (minChar > c || hm.get(minChar) == null){
                minChar = c;
                minIndex = start;
            }

            Integer occur = hm.get(c);

            if (occur == null){
                start ++;
            }

            else if (occur > 1){
                hm.put(c, occur-1);
                start++;
            }

            else{

                if (strStart < newStr.length)
                    newStr[strStart++] = s.charAt(minIndex);
                //Put the char back
                for (int i=minIndex+1; i<start; i++){
                    if (hm.get(s.charAt(i)) != null)
                        hm.put(s.charAt(i), hm.get(s.charAt(i))+1);
                }
                hm.remove(minChar);

                start = minIndex+1;
                if (start < s.length()){
                    minIndex = start;
                    minChar = s.charAt(start);
                }

            }
        }

        return new String(newStr);
    }

    public static void main(String[] args){
        P316_RemoveDuplicateLetters p = new P316_RemoveDuplicateLetters();
        System.out.print(p.removeDuplicateLetters("bbbacacca"));
    }

}
