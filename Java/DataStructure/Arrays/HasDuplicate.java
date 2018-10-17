/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array,
 and it should return false if every element is distinct.
 */



import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

public class HasDuplicate {
    public static boolean containsDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();

        for(int i=0;i<nums.length;i++){
            if (set.contains(nums[i])) { return true; }
            else { set.add(nums[i]); }
        }
        return false;
    }

    public static void main(String[] args) {
        int[] input = {1, 2, 3, 4,4, 5};
        System.out.println(Arrays.toString(input));
        System.out.println(containsDuplicate(input));
    }
}

/*
alternate solution
public boolean containsDuplicate(int[] nums) {
        HashSet<Integer> set = new HashSet();
        for(int i = 0;i < nums.length;i++)
           set.add(nums[i]);
        return set.size() != nums.length;
    }
 */
