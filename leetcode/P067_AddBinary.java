package leetcode;

/**
 * Created by huihui on 2/2/16.
 */
public class P067_AddBinary {

    public String addBinary(String a, String b) {

        int longer = a.length() > b.length() ? a.length() : b.length();

        String result = new String();


        boolean carry = false;
        for (int i = 0; i < longer; i++) {

            int aIndex = a.length() - i - 1;
            int bIndex = b.length() - i - 1;

            int sum = 0;

            if (aIndex >= 0)
                sum += Integer.parseInt(a.substring(aIndex, aIndex+1));

            if (bIndex >= 0)
                sum += Integer.parseInt(b.substring(bIndex, bIndex+1));

            if (carry)
                sum += 1;

            if (sum >= 2)
                carry = true;
            else
                carry = false;

            sum = sum % 2;

            result = sum + "" + result;
        }

        if (carry)
            result = 1 + "" + result;

        return result;
    }

}
