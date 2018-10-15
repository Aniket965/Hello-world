#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Generate a random integer between MIN and MAX.
 */
int _rand(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

/**
 * Program
 */
int main()
{
    int lowest, highest, count;

    // Prompt for the smallest number.
    printf("Smallest number: ");
    scanf("%d", &lowest);

    // Prompt for the largest number.
    printf("Largest number: ");
    scanf("%d", &highest);

    // Prompt for the count of numbers to generate.
    printf("How many numbers to generate? ");
    scanf("%d", &count);

    // Ensure the highest is truly greater than the lowest.
    assert(lowest <= highest);

    // Generate the number.
    for (int i = 0; i < count; i++)
        printf("\n-> %d", _rand(lowest, highest)); // Show the number

    return EXIT_SUCCESS;
}
