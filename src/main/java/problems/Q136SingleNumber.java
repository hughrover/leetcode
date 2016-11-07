package problems;

/**
 * User: chengcheng.liu
 * Date: 16/10/14
 */
public class Q136SingleNumber {
    public static void main(String[] args) {
        int[] array = new int[]{2, 2, 3, 4, 4};
        System.out.println(singleNumber(array));
    }

    public static int singleNumber(int[] nums) {
        if (nums.length > 0) {
            int result = nums[0];
            for (int i = 1; i < nums.length; i++) {
                result = result ^ nums[i];
            }
            return result;
        } else {
            return 0;
        }
    }
}
