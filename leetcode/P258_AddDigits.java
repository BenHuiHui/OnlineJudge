package leetcode;

/**
 * Created by huihui on 2/2/16.
 */
public class P258_AddDigits {

    public int addDigits(int num) {

        while (num >= 10){
            int result = 0;

            while (num > 0){
                result += num %10;
                num /= 10;
            }

            num = result;

        }

        return num;
    }

}
