package leetcode;

import java.util.Scanner;
import java.util.regex.Pattern;

/*
    Really need to check this
 */

public class P165_CompareVersionNumbers {

    public int compareVersion(String version1, String version2) {

        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");

        if (v1.length == 0){
            v1 = new String[1];
            v1[0] = version1;
        }

        if (v2.length == 0){
            v2 = new String[1];
            v2[0] = version2;
        }

        int length = v1.length < v2.length ? v1.length : v2.length;

        for (int i = 0; i < length; i++) {

            int n1 = Integer.parseInt(v1[i]);
            int n2 = Integer.parseInt(v2[i]);

            if (n1 < n2)
                return -1;
            else if (n1 > n2)
                return 1;
        }

        if (v1.length > length) {

            for (int i = length; i < v1.length; i++) {
                int n = Integer.parseInt(v1[i]);
                if (n != 0)
                    return 1;
            }

            return 0;
        }
        else if (v1.length == v2.length)
            return 0;

        for (int i = length; i < v2.length; i++) {
            int n = Integer.parseInt(v2[i]);
            if (n!=0)
                return -1;
        }

        return 0;

    }

    public static void main(String[] args){

        /*
        1 0

        1.0 1.1
         */

        Scanner in = new Scanner(System.in);

        P165_CompareVersionNumbers p = new P165_CompareVersionNumbers();

        String a = in.next();
        String b = in.next();

        System.out.println(p.compareVersion(a, b));
    }

}
