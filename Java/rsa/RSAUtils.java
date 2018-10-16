import java.math.BigInteger;

public class RSAUtils {
    public static byte[] modPowByte(byte[] arg, BigInteger e, BigInteger n) {
        BigInteger source = new BigInteger(1, arg);
        BigInteger result = source.modPow(e, n);
        return getBytesWithoutSign(result);
    }

    private static byte[] getBytesWithoutSign(BigInteger arg) {
        byte[] sourceArray = arg.toByteArray();
        if (sourceArray[0] != 0) {
            return sourceArray;
        } else {
            byte[] withoutSign = new byte[sourceArray.length - 1];
            System.arraycopy(sourceArray, 1, withoutSign, 0, withoutSign.length);
            return withoutSign;
        }
    }
}
