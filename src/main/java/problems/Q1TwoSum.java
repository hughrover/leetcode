package problems;

import java.util.Arrays;
import java.util.HashMap;

/**
 * User: chengcheng.liu
 * Date: 16/9/9
 */
public class Q1TwoSum {

    public static void main(String[] args) {
        int[] numArray = {1, 2, 3, 4, 5, 6, 7};
        int target = 10;
        System.out.println(Arrays.toString(twoSum(numArray, target)));
    }

    public static int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> completeIndexMap = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            Integer complete = target - nums[i];
            if (!completeIndexMap.containsKey(complete)) {
                completeIndexMap.put(complete, i);
            }
        }

        for (int j = 0; j < nums.length; j++) {
            if (completeIndexMap.containsKey(nums[j])) {
                int indexOne = completeIndexMap.get(nums[j]);
                if (indexOne != j) {
                    return new int[]{j, indexOne};
                }
            }
        }
        throw new IllegalArgumentException("No two sum solution");
    }
}
