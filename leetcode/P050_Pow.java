package leetcode;

import java.util.Scanner;

/**
 * Created by huihui on 4/2/16.
 */

/*
Problem n can be negative
 */

public class P050_Pow {

    public double myPow(double x, int n) {

        if (n == 1) return x;
        if (n == 0) return 1;
        boolean isNegative = n < 0;

        if (isNegative) n = -n;

        double pow = myPow(x, n/2);

        double result = pow * pow;

        if (n % 2 == 1)
            result *= x;

        if (isNegative) result = 1 / result;

        return result;
    }


    public static void main (String[] args){
        P050_Pow p = new P050_Pow();

        Scanner in = new Scanner(System.in);

        double x = in.nextDouble();
        int n = in.nextInt();

        System.out.println(p.myPow(x, n));
    }
}
