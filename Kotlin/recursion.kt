import java.math.BigInteger
fun main(args : Array<String>){

    var num=BigInteger("89")

    println(fact1(num))
}

fun fact1(num : BigInteger): BigInteger {

    if(num== BigInteger.ZERO)
       // return BigInteger("1")
         return  BigInteger.ONE
    else
        return num*fact1(num- BigInteger.ONE)


}
