/**
 * Created by huihui on 7/3/16.
 */
public class P123_BestTimeToBuyAndSellStockIII {

    public int maxProfit(int[] prices) {

        if (prices.length <= 0) return 0;

        int[] first = new int[prices.length];
        int[] second = new int[prices.length];

        int min = prices[0];

        for (int i = 0; i < prices.length; i++) {

            int profit = prices[i] - min;

            first[i] = profit > 0 ? profit : 0;

            if (i > 0 && first[i] < first[i-1])
                first[i] = first[i-1];

            if (min > prices[i])
                min = prices[i];
        }

        int max = prices[prices.length-1];
        for (int i = prices.length-1; i >=0 ; i--) {

            int profit = max - prices[i];
            second[i] = profit > 0 ? profit : 0;

            if (i < prices.length-1 && second[i]  <= second[i+1])
                second[i] = second[i+1];

            if (max < prices[i])
                max = prices[i];
        }

        int maxProfit = 0;

        for (int i = 0; i < prices.length; i++) {

            int profit = first[i];

            if (i < prices.length-1) profit += second[i+1];

            if (maxProfit < profit)
                maxProfit = profit;
        }

        return maxProfit;
    }

    public static void main(String[] args){
        P123_BestTimeToBuyAndSellStockIII p = new P123_BestTimeToBuyAndSellStockIII();

        int[] prices = {3,2,6,5,0,3};
        System.out.println(p.maxProfit(prices));
    }

}
