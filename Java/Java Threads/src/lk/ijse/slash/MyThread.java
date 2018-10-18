package lk.ijse.dep;

public class MyThread extends Thread{
    @Override
    public void run() {

        while (true)
        System.out.println("My Thread");
    }
}
