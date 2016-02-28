/**
 * Created by huihui on 28/2/16.
 */
public class P134_GasStation {

    public int canCompleteCircuit(int[] gas, int[] cost) {

        int length = gas.length;

        for (int i = 0; i < gas.length; i++) {

            int total = gas[i] - cost[i];
            int next = (i+1) % length;

            while (total >= 0){
                total += (gas[next] - cost[next]);
                if (next == i) return i;
                next = (next+1) % length;
            }

            if (next > i)
                i = next - 1;
            if (i < 0) i=0;
        }

        return -1;
    }

}
