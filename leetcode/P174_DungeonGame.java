/**
 * Created by huihui on 20/3/16.
 */
public class P174_DungeonGame {

    public int calculateMinimumHP(int[][] dungeon) {
        if(dungeon.length <= 0) return 0;

        int row = dungeon.length;
        int col = dungeon[0].length;

        int[][] minHealth = new int[row][col];

        int initial = dungeon[row-1][col-1] < 0 ? 1 - dungeon[row-1][col-1] : 1;
        minHealth[row-1][col-1] = initial;

        //Last column
        for(int i=row-2; i>=0; i--){
            int health = minHealth[i+1][col-1] - dungeon[i][col-1];
            if (health <= 0) health = 1;
            minHealth[i][col-1] = health;
        }

        //Last row
        for(int i=col-2; i>=0; i--){
            int health = minHealth[row-1][i+1] - dungeon[row-1][i];
            if (health <= 0) health = 1;
            minHealth[row-1][i] = health;
        }

        //Remaining
        for(int i=col-2; i>=0; i--){
            for(int j=row-2; j>=0; j--){
                int health1 = minHealth[j+1][i] - dungeon[j][i];
                int health2 = minHealth[j][i+1] - dungeon[j][i];
                int health = health1 < health2 ? health1 : health2;
                if (health < 0) health = 1;
                minHealth[j][i] = health;
            }
        }

        return minHealth[0][0];
    }

    public static void main(String[] args){
        P174_DungeonGame p = new P174_DungeonGame();
        int[][]d = {{0, -3}};
        System.out.println(p.calculateMinimumHP(d));
    }

}
