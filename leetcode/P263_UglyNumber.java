/**
 * Created by huihui on 27/2/16.
 */
public class P263_UglyNumber {

    public boolean isUgly(int num) {

        if (num <= 0) return false;

        while (num % 2 ==0)
            num /= 2;

        while (num %3 == 0)
            num /= 3;

        while (num % 5 == 0)
            num /= 5;

        return num == 1;
    }

}
