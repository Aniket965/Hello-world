package lk.ijse.dep;

public class Demo {
    public static void main(String[] args) {

        MyThread myThread = new MyThread();
        myThread.setName("Sashika");
        myThread.start();

        Thread.currentThread().setName("Sandeepana");
        System.out.println(Thread.currentThread().getName());

    }

}
