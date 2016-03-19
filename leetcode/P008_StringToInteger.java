/**
 * Created by huihui on 18/3/16.
 */
public class P008_StringToInteger {

    public int myAtoi(String str) {

        int result = 0;
        boolean isNegative = false;

        int start = 0;

        //Pass empty spaces
        while (start<str.length() && str.charAt(start) == ' ')start++;

        //Check +/- at the beginning of string
        if (start<str.length() && str.charAt(start) == '+') start++;
        else if (start<str.length() && str.charAt(start) == '-'){
            isNegative = true;
            start++;
        }

        for (int i = start; i < str.length(); i++) {

            //Not a number
            char c = str.charAt(i);
            if (c > '9' || c < '0')
                break;

            //Overflow
            if (result > Integer.MAX_VALUE / 10 || (Integer.MAX_VALUE - result*10 < c - '0')){
                if (isNegative) return Integer.MIN_VALUE;
                return Integer.MAX_VALUE;
            }

            result = result*10 + c- '0';
        }

        if (isNegative) result = -result;

        return result;
    }

    public static void main(String[] args){
        P008_StringToInteger p = new P008_StringToInteger();
    }

}
