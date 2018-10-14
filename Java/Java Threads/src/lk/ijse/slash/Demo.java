package lk.ijse.dep;

public class Demo {
    public static void main(String[] args) {
//      new Thread(()->{
//          System.out.println("My Thread");
//      }).start();
//
//      try{
//          Thread.sleep(100);
//      } catch (InterruptedException e) {
//          e.printStackTrace();
//      }
//        System.out.println("Main Thread");

        MyThread myThread = new MyThread();
        myThread.setName("Sashika");
        myThread.start();

        Thread.currentThread().setName("Harsha");
        System.out.println(Thread.currentThread().getName());

    }

}
