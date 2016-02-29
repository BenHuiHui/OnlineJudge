/**
 * Created by huihui on 29/2/16.
 */
public class P043_MultiplyStrings {

    public String multiply(String num1, String num2) {

        String result = "";

        for (int i = num2.length()-1; i >=0 ; i--) {

            int ten = num2.length()-1-i;

            String inter = multiply(num1, num2.charAt(i)-'0');

            for (int j = 0; j < ten; j++) {
                inter = inter + "0";
            }

            result = add(result, inter);
        }

        return result;
    }

    public String multiply(String num1, int factor){

        int carry = 0;
        String result = "";

        for (int i = num1.length()-1; i >=0 ; i--) {
            int sum = (num1.charAt(i) - '0') * factor + carry;
            carry = sum / 10;
            result = (char)('0' + sum % 10) + result;
        }

        if (carry > 0)
            result = ((char)('0' + carry)) + result;

        //Remove trailing zeros
        int index = -1;
        for (int i = 0; i < result.length(); i++) {
            if (result.charAt(i) == '0')
                index = i;
            else
                break;
        }

        result = result.substring(index+1);
        if (result.length() <= 0)
            result = "0";

        return result;
    }

    public String add(String num1, String num2){
        int length = num1.length() > num2.length() ? num1.length()-1 : num2.length()-1;
        int carry = 0;
        String result = "";

        for (int i = 0; i <= length ; i++) {

            int left = num1.length()-1-i;
            int right = num2.length()-1-i;

            int l=0, r=0;

            if (left>=0) l = num1.charAt(left) - '0';
            if (right >= 0) r = num2.charAt(right) - '0';

            int sum = l + r + carry;

            carry = sum / 10;
            char s = (char)('0' + sum%10);
            result = s + result;
        }

        if (carry > 0)
            result = "1" + result;

        return result;
    }

    public static void main(String[] args){
        String num1 = "1";
        String num2 = "1";
        P043_MultiplyStrings p = new P043_MultiplyStrings();

        System.out.print(p.multiply(num1, num2));
    }

}
