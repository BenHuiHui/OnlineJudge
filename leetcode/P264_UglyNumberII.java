import java.util.ArrayList;

/**
 * Created by huihui on 27/2/16.
 */
public class P264_UglyNumberII {

    public int nthUglyNumber(int n) {

        ArrayList<Integer> results = new ArrayList<Integer>();
        results.add(1);
        int handle2 = 0;
        int handle3 = 0;
        int handle5 = 0;

        while (results.size() < n ){

            int two = results.get(handle2) * 2;
            int three = results.get(handle3) * 3;
            int five = results.get(handle5) * 5;

            if (two <= three && two <= five){
                results.add(two);
                handle2 ++;

                if (two == three)
                    handle3++;
                if (two == five)
                    handle5 ++;
            }

            else if (three <= two && three <= five){
                results.add(three);
                handle3 ++;

                if (two == three)
                    handle2++;
                if (three == five)
                    handle5 ++;
            }
            else{
                results.add(five);
                handle5 ++;

                if (five == three)
                    handle3++;
                if (two == five)
                    handle2 ++;
            }
        }

        return results.get(n-1);
    }

}
