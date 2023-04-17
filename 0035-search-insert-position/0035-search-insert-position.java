public class Solution {
    public int searchInsert(int[] nums, int target) {
        return bs(nums, 0, nums.length -1, target);
    }
    private int bs(int[]nums, int start, int end, int target) {
        if (start > end) {
            return end + 1;
        }
        int mid = (start + end) / 2;
        if (nums[mid] < target) {
            return bs(nums, mid + 1, end, target);
        }
        if (nums[mid] > target) {
            return bs(nums, start, mid - 1, target);
        }
        return mid;
    }
}