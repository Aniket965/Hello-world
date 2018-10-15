public class PrintO {
    public void printLetterO() {
        int x, y, z, w;

        System.out.println(" .d88888b. ");
        System.out.println("d88P\" \"Y88b  ");
        for (z = 0; z < 3; z++) {
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
        if (z == 3) {
            System.out.println("Y88b. .d88P");
            System.out.println(" \"Y88888P\"");
        }
        System.out.println();
        System.out.println();
    }
}
