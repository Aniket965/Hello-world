public class PrintW {
    public void printLetterW() {
        int x, y;
        for (x = 0; x < 3; x++) {
            System.out.print("8");
        }
        for (y = 0; y < 7; y++) {
            System.out.print(" ");
        }
        for (x = 0; x < 3; x++) {
            System.out.print("8");
        }

        System.out.println();

        for (x = 0; x < 12; x++) {
            System.out.print("8");
            if (x == 2) {
                for (y = 2; x < 8; x++) {
                    System.out.print(" ");
                    if (x == 4) {
                        System.out.print("o");
                    }
                }
            }

        }
        System.out.println();

        for (x = 0; x < 10; x++) {
            System.out.print("8");
            if (x == 2) {
                for (y = 2; x < 6; x++) {
                    System.out.print(" ");
                    if (x == 3) {
                        System.out.print("d8b");
                    }
                }
            }
        }

        System.out.println();

        for (x = 0; x < 8; x++) {
            System.out.print("8");
            if (x == 2) {
                for (y = 2; x < 4; x++) {
                    System.out.print(" ");
                    if (x == 2) {
                        System.out.print("d888b");
                    }
                }
            }
        }
        System.out.println();

        for (x = 0; x < 11; x++) {
            System.out.print("8");
            if (x == 2) {
                System.out.print("d");
            }
            if (x == 7) {
                System.out.print("b");
            }
        }

        System.out.println();

        for (x = 0; x < 10; x++) {
            System.out.print("8");
            if (x == 4) {
                System.out.print("P");

                System.out.print(" ");

                System.out.print("Y");
            }
        }

        System.out.println();

        for (x = 0; x < 8; x++) {
            System.out.print("8");
            if (x == 3) {
                System.out.print("P");

                System.out.print("   ");

                System.out.print("Y");
            }

        }

        System.out.println();
        System.out.println();
    }
}
