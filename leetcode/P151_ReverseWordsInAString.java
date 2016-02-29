/**
 * Created by huihui on 29/2/16.
 */
public class P151_ReverseWordsInAString {

    public String reverseWords(String s) {
        s= s.trim();
        String result = "";

        String[] sp = s.split(" ");
        for (int i = sp.length-1; i >=0 ; i--) {

            if (sp[i].equals(" ") || sp[i].equals(""))
                continue;

            result+=sp[i];
            result+= " ";
        }

        result = result.trim();
        return result;
    }

    public static void main(String[] args){
        P151_ReverseWordsInAString p = new P151_ReverseWordsInAString();
        p.reverseWords("   a    b");
    }

}
