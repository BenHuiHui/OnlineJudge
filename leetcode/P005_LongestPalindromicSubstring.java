/**
 * Created by huihui on 27/2/16.
 */
public class P005_LongestPalindromicSubstring {
    //O(n^2)
    public String longestPalindrome(String s) {

        int max = 0;
        String maxStr = "";

        for (int i=0; i<s.length(); i++){

            int start = i;
            int end = i;

            while (start >= 0 && end < s.length()){

                if (s.charAt(start) != s.charAt(end))
                    break;

                if (end - start + 1 > max){
                    max = end - start +1;
                    maxStr = s.substring(start, end+1);
                }

                start --;
                end ++;
            }

            start = i;
            end = i+1;

            while (start >= 0 && end < s.length()){

                if (s.charAt(start) != s.charAt(end))
                    break;

                if (end - start + 1 > max){
                    max = end - start +1;
                    maxStr = s.substring(start, end+1);
                }

                start --;
                end ++;
            }
        }

        return maxStr;
    }

}
