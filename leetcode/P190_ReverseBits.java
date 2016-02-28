/**
 * Created by huihui on 28/2/16.
 */
public class P190_ReverseBits {

    public int reverseBits(int n) {

        int result = 0;

        for (int i = 0; i < 32; i++) {
            result = result << 1;
            result |= n & 1;
            n = n>>1;
        }

        return result;

    }

}
