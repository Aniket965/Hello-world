/**
 * Solve minimum number of packages needed to pack items.
 * Big package size is 5
 * Small is 1
 * If cant pack, return -1
 */

class MinimalBoxCount {

    companion object {
        const val BIG_PACKAGE_CAPACITY = 5
    }

    fun main(args: Array<String>) {
        System.out.print(minimalNumberOfPackages(16, 2, 10))
    }

    private fun minimalNumberOfPackages(items: Int, availableLargePackage: Int, availableSmallPackage: Int): Int {
        var largePackages = items.div(BIG_PACKAGE_CAPACITY)
        if (items.rem(BIG_PACKAGE_CAPACITY) == 0 && largePackages < availableLargePackage)
            return largePackages

        largePackages = if (largePackages > availableLargePackage) availableLargePackage else largePackages

        val smallPackages = items.minus(largePackages.times(BIG_PACKAGE_CAPACITY))

        return if (smallPackages > availableSmallPackage) return 1
        else largePackages.plus(smallPackages)
    }
}