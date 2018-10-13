import java.util.Arrays;
import java.util.Collections;

public class CountingChanges {

    public static int countChange(int money, Integer[] coins) {
        if (money == 0) {
            return 1;
        }
        if (money < 0 || coins.length == 0) {
            return 0;
        }
        return countChange(money, Arrays.copyOfRange(coins, 1, coins.length)) +
                countChange(money - coins[0], coins);
    }

    /**
     * Counting all possible changes with defined coins and money
     * @param args --
     */
    public static void main(String[] args) {
        Integer[] coins = { 3, 2, 4, 6 };
        int money = 19;
        Arrays.sort(coins, Collections.reverseOrder());

        int result = countChange(money, coins);

        if (result < 0) {
            System.out.println("Not possible.");
        } else {
            System.out.print("Max possible combinations are = " + result +
                    "\n Coins = " + Arrays.toString(coins) + " Money= " + money);
        }
    }
}
