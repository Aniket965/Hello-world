package semaphore;
import java.util.concurrent.Semaphore;

public class HRmanager {

    public static void main(String[] args) {
     
        Semaphore QuestionPaperPool =new Semaphore(2);
        TechLead techlead1 = new TechLead(QuestionPaperPool,"amit tcl");
        TechLead techlead2 = new TechLead(QuestionPaperPool,"vivek tcl");
        TechLead techlead3 = new TechLead(QuestionPaperPool,"dinesh tcl");
        TechLead techlead4 = new TechLead(QuestionPaperPool,"raghav tcl");
        techlead1.start();
        techlead2.start();
        techlead3.start();
        techlead4.start();
        System.out.println("no work for hr manager");
    }
    
}
class TechLead extends Thread {
        
    Semaphore QuestionPaperPool;
    public TechLead(Semaphore QuestionPaperPool,String name){
        super(name);
        this.QuestionPaperPool =QuestionPaperPool;
    }
    @Override
    public void run(){
        try {
            System.out.println(Thread.currentThread().getName()+"waiting for test question papers");
            //aquiring one ques ppr
            QuestionPaperPool.acquire();
            System.out.println(Thread.currentThread().getName()+"acuired test paper");
            System.out.println(Thread.currentThread().getName()+"Conducting test");
            Thread.sleep(3000);
            
            System.out.println(Thread.currentThread().getName()+"testdone giving back question paper");
            //giving back accuired question paper
            QuestionPaperPool.release();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}