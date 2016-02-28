/**
 * Created by huihui on 28/2/16.
 */
public class P125_ValidPalindrome {
    public boolean isPalindrome(String s) {

        s = s.toLowerCase();
        int left =0, right = s.length()-1;

        while (left < right){

            while (left < right && !isAlphaNumeric(s.charAt(left))) left++;
            while (left < right && !isAlphaNumeric(s.charAt(right))) right--;
            if (!isSame(s.charAt(left), s.charAt(right)))
                return false;
            left++;
            right--;

        }

        return true;
    }

    public boolean isAlphaNumeric(char c){
        if (c >= '0' && c <= '9') return true;
        if (c >= 'a' && c<= 'z') return true;
        if (c >= 'A' && c<= 'Z') return true;
        return false;
    }

    public boolean isSame(char c, char d){
        return c==d;
    }
}
