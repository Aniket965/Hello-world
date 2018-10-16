import java.math.BigInteger;

public class PrivateKey {
    private BigInteger d;
    private BigInteger n;

    public PrivateKey(BigInteger d, BigInteger n) {
        this.d = d;
        this.n = n;
    }

    public BigInteger getD() {
        return d;
    }

    public BigInteger getN() {
        return n;
    }

    public byte[] decrypt(byte[] cipherText) {
        return RSAUtils.modPowByte(cipherText, d, n);
    }
    public byte[] encrypt(byte[] plainText) {
        byte[] cipherText = RSAUtils.modPowByte(plainText, d, n);
        return cipherText;
    }
}
