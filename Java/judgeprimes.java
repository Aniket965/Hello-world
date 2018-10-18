System.out.println("ランダム素数判定プログラム");
java.util.Random rm = new java.util.Random();
int s = rm.nextInt(100);

if (s == 2 || s == 3) {
    System.out.println(s + "は素数です");
} else if (s % 2 == 0 || s % 3 == 0) {
    System.out.println(s + "は素数ではないです");
} else {
    System.out.println(s + "は素数です");
}