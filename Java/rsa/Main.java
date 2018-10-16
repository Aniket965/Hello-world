public class Main {
    public static void main(String[] args) {
        KeyPair keyPair = new KeyPair();
        System.out.println("N of Public Key: " + keyPair.getPublicKey().getN());
        System.out.println("E of Public Key: " + keyPair.getPublicKey().getE());
        System.out.println("N of Private Key: " + keyPair.getPrivateKey().getN());
        System.out.println("D of Private Key: " + keyPair.getPrivateKey().getD());
    }
}
