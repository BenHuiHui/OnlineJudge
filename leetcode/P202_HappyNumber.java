package leetcode;

import java.util.HashSet;

/**
 * Created by huihui on 2/2/16.
 */
public class P202_HappyNumber {

    public boolean isHappy(int n) {

        HashSet<Integer> occurred = new HashSet<Integer>();

        while (true){

            if (occurred.contains(n))
                return false;

            occurred.add(n);

            int newVal = 0;

            while (n > 0){
                int reminder = n % 10;
                newVal += reminder * reminder;
                n /= 10;
            }

            n = newVal;

            if (n == 1)
                return true;

        }

    }

}
