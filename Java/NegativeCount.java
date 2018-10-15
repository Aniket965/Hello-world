// Use stream and Lambdas to count the negative numbers in an array

import static java.util.Arrays.*;

public class NegativeCount {

    public static void main( String[] args ) {
        int[] nums = { 5, -1, -3, 20, 47, -10, -8, -4, 0, -6, -6 };
        int[] nums1 = { -5, -1, -3, -20, -47, -10, -8, -4, -6, -6 };
        int[] nums2 = { 5, 1, 3, 20, 47, 0, 6, 6 };
        int[] nums3 = {};
        countNegatives( nums );
        countNegatives( nums1 );
        countNegatives( nums2 );
        countNegatives( nums3 );
    }
    // Use stream operations to count how many numbers in a given array
    // of integers are negative
    private static void countNegatives( int[] nums ) {
        // note: count() returns a long.
        long howMany = stream( nums )
                .filter( n -> n < 0 )
                .count();
        System.out.println( String.format( "This array contains %s negative numbers.", howMany ) );
    }
}
