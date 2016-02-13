package leetcode;

import java.util.Scanner;

/**
 * Created by huihui on 3/2/16.
 */

//Problem : Integer out of range
//Problem : Stop whenever range is greater than n

public class P330_PatchingArray {

    public int minPatches(int[] nums, int n) {

        int range = 0;
        int total = 0;

        for (int i = 0; i < nums.length && range < n; i++) {


            while (range < nums[i]-1){
                range += (range + 1);
                total ++;

                if (range >= n) return total;

            }

            range += nums[i];
        }

        while (range < n){
            range += (range + 1);
            total ++;

            if (range < n && range >= Integer.MAX_VALUE/2){
                total ++;
                break;
            }

        }


        return total;
    }

    public static void main(String[] args){

        /*
            20 3 1 5 10

            2147483647 4 1 2 31 33

            12  15 1 7 21 31 34 37 40 43 49 87 90 92 93 98 99

            20 19 1 2 2 6 34 38 41 44 47 47 56 59 62 73 77 83 87 89 94

         */

        P330_PatchingArray p = new P330_PatchingArray();

        Scanner in = new Scanner(System.in);

        int n = in.nextInt();

        int size = in.nextInt();

        int[] num = new int[size];

        for (int i = 0; i < size; i++) {
            num[i] = in.nextInt();
        }

        System.out.println(p.minPatches(num, n));
    }

}
