public class PrintL {
    public void printLetterL() {
        int x, y, z;
        for (z = 0; z < 6; z++) {
            System.out.println();
            for (x = 0; x < 3; x++) {
                System.out.print("8");
            }
        }
        if (z == 6) {
            System.out.println();
            for (y = 0; y < 10; y++) {
                System.out.print("8");
            }
        }
        System.out.println();
        System.out.println();
    }
}
