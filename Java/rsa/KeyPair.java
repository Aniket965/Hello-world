import java.math.BigInteger;
import java.util.Random;

public class KeyPair {
    private BigInteger p;
    private BigInteger q;
    private BigInteger n;
    private BigInteger fi;
    private BigInteger e;
    private BigInteger d;
    private static final int bitLength = 1024;
    private int pqBigLength;
    private PublicKey publicKey;
    private PrivateKey privateKey;

    public KeyPair() {
        pqBigLength = bitLength / 2;
        do {
            //generate p
            p = BigInteger.probablePrime(pqBigLength, new Random());
            //generate q
            q = BigInteger.probablePrime(pqBigLength, new Random());
            //multiply q and p
            n = p.multiply(q);
        } while (n.bitLength() != bitLength);
        fi = p.subtract(BigInteger.ONE).multiply(q.subtract(BigInteger.ONE));
        e = generatePublicExponent();
        d = e.modInverse(fi);
        publicKey = new PublicKey(e, n);
        privateKey = new PrivateKey(d, n);
    }

    private BigInteger generatePublicExponent() {
        while (true) {
            Random random = new Random();
            int length = pqBigLength + random.nextInt(fi.bitLength() - pqBigLength);
            BigInteger exponent = new BigInteger(length, new Random());
            if (exponent.compareTo(BigInteger.ONE) != 0
                    && exponent.compareTo(fi) == -1
                    && exponent.gcd(fi).compareTo(BigInteger.ONE) == 0) return exponent;
        }
    }

    public PublicKey getPublicKey() {
        return publicKey;
    }

    public PrivateKey getPrivateKey() {
        return privateKey;
    }
}
