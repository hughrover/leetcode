package problems;

/**
 * User: chengcheng.liu
 * Date: 16/9/23
 */
public class Q70ClimbingStairs_v {
    public static void main(String[] args) {
        System.out.println(climbStairs(5));
    }

    public static int climbStairs(int n) {
        if (n == 0 || n == 1 || n == 2)
            return n;

        int[] midNum = new int[n + 1];
        midNum[1] = 1;
        midNum[2] = 2;

        for (int i = 3; i <= n; i++) {
            midNum[i] = midNum[i - 1] + midNum[i - 2];
        }
        return midNum[n];
    }

    // Time Limit Exceeded
    public static int climbStairs_old(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        return climbStairs_old(n - 1) + climbStairs_old(n - 2);
    }
}



/*
    先转换为数学问题斐波那契数列，再选择动态规划存储中间解，避免重复计算
*/
