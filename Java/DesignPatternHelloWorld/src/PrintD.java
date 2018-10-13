public class PrintD {
    public void printLetterD() {
        int x, y, z, v, w;

        for (z = 0; z < 7; z++) {
            System.out.print("8");
        }
        System.out.println("b.");

        for (z = 0; z < 8; z++) {
            System.out.print("8");
            if (z == 2) {
                for (x = 3; x < 6; x++) {
                    System.out.print(" ");
                }
            }
        }
        System.out.println();

        for (v = 0; v < 3; v++) {
            for (x = 0; x < 3; x++) {
                System.out.print("8");
            }
            for (y = 0; y < 5; y++) {
                System.out.print(" ");
            }
            for (w = 0; w < 3; w++) {
                System.out.print("8");

            }
            System.out.println();
        }


        for (z = 0; z < 8; z++) {
            System.out.print("8");
            if (z == 2) {
                for (x = 3; x < 6; x++) {
                    System.out.print(" ");
                }
            }
        }
        System.out.println();
        for (z = 0; z < 7; z++) {
            System.out.print("8");
        }
        System.out.println("P'");
    }
}
