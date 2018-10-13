public class PrintE {

    public void printLetterE() {
        int x, y, z, v, w;

        for (x = 0; x < 10; x++) {
            System.out.print("8");

        }
        if (x == 10) {
            System.out.println();
            for (z = 0; z < 2; z++) {
                for (y = 0; y < 3; y++) {
                    System.out.print("8");

                }
                System.out.println();
            }
            if (z == 2) {

                for (x = 0; x < 8; x++) {
                    System.out.print("8");
                }
                if (x == 8) {
                    //System.out.println();
                    System.out.println();
                    for (z = 0; z < 2; z++) {
                        for (y = 0; y < 3; y++) {
                            System.out.print("8");

                        }
                        System.out.println();
                    }
                }
            }
            if (z == 2) {

                for (x = 0; x < 10; x++) {
                    System.out.print("8");
                }

            }
        }
        System.out.println();
        System.out.println();
    }

}
