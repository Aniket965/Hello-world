object insertionSort {
    def main(args: Array[String]): Unit ={
      val unsrt = Array(10, 8, 7, 11, 22, 5, 0, 4, 6) // unsorted array
      val len = unsrt.length
      for (i <- 1 to len-1){
        for(j <- i-1 to 0 by -1){
          if(unsrt(j) > unsrt(j+1)){
            val tmp = unsrt(j+1)
            unsrt(j+1) = unsrt(j)
            unsrt(j) = tmp
          }
        }
      }
      println(unsrt.toList)
    }
}
