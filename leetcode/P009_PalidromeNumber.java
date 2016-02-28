/**
 * Created by huihui on 28/2/16.
 */
public class P009_PalidromeNumber {

    public boolean isPalindrome(int x) {

        if (x < 0) return false;

        //Get number of digits
        int tmp = x;
        int digits = 0;

        while (tmp > 0){
            digits++;
            tmp = tmp/10;
        }

        int y=0;
        for (int i = 0; i < digits/2; i++) {
            y = y*10;
            y+= x%10;
            x = x/10;
        }

        if (digits %2 ==1)
            x = x/10;

        return x == y;
    }


}
