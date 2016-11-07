package problems;

import java.util.Arrays;

/**
 * User: chengcheng.liu
 * Date: 16/9/20
 */
public class Q27RemoveElement {
    public static void main(String[] args) {
        int[] nums = new int[]{2, 2, 2};
        System.out.println(removeElement(nums, 3));
        System.out.println(Arrays.toString(nums));
    }

    public static int removeElement(int[] nums, int val) {
        if (nums.length < 1) {
            return 0;
        }

        int i = 0;
        int j = nums.length - 1;

        while (i < j) {
            while (nums[i] != val && i < j) i++;
            while (nums[j] == val && j > i) j--;

            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }

        return nums[i] != val ? ++i : i;
    }
}
