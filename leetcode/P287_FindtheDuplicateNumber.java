package leetcode;

import java.util.Scanner;

/**
 * Created by huihui on 8/2/16.
 */
public class P287_FindtheDuplicateNumber{

    public int findDuplicate(int[] nums) {

        int index = 0;

        while (true){

            //In correct position
            if (nums[index] == index+1)
                index++;

            else {

                int curr_num = nums[index];

                while (curr_num != index + 1) {


                    int next_index = curr_num-1;
                    int next_num = nums[next_index];

                    //Swap
                    if (next_num != next_index + 1) {
                        int temp = curr_num;
                        nums[index] = next_num;
                        nums[next_index] = temp;
                    } else
                        return curr_num;

                    curr_num = nums[index];
                }
            }
        }
    }

    public static void main(String[] args){

        /*
        2 1 1
        3 2 1 1
         */

        Scanner in = new Scanner(System.in);

        P287_FindtheDuplicateNumber p = new P287_FindtheDuplicateNumber();

        int n = in.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextInt();
        }

        System.out.println(p.findDuplicate(arr));
    }

}
