import java.awt.*;
import javax.swing.*;
@SuppressWarnings("serial")
public class AboutMeApplet extends JApplet {
	static String Heading = "Computer Science:";
	static String A1 = "A: Hard working, persistant, kind, intellegent.";
    static String B2 = "B: Messy Handwriting.";
	static String C3 = "C: Individualized approach";
    static String D4 = "D: Lecturing";
	static String E5 = "E: To learn more about java and good programming habits.";

/**
     * Called by the browser or applet viewer to inform this JApplet that it
     * has been loaded into the system. It is always called before the first 
     * time that the start method is called.
     */
    public void init()
    {
        // this is a workaround for a security conflict with some browsers
        // including some versions of Netscape & Internet Explorer which do 
        // not allow access to the AWT system event queue which JApplets do 
        // on startup to check access. May not be necessary with your browser. 
        JRootPane rootPane = this.getRootPane();    
        rootPane.putClientProperty("defeatSystemEventQueueCheck", Boolean.TRUE);
    
        // provide any initialisation necessary for your JApplet
    }

    /**
     * Called by the browser or applet viewer to inform this JApplet that it 
     * should start its execution. It is called after the init method and 
     * each time the JApplet is revisited in a Web page. 
     */
    public void start()
    {
        // provide any code requred to run each time 
        // web page is visited
    }

    /** 
     * Called by the browser or applet viewer to inform this JApplet that
     * it should stop its execution. It is called when the Web page that
     * contains this JApplet has been replaced by another page, and also
     * just before the JApplet is to be destroyed. 
     */
    public void stop()
    {
        // provide any code that needs to be run when page
        // is replaced by another page or before JApplet is destroyed 
    }

    /**
     * Paint method for applet.
     * 
     * @param  g   the Graphics object for this applet
     */
    public void paint(Graphics g)
    {
        // simple text displayed on applet
        g.setColor(Color.CYAN);
        g.fillRect(0, 0, 400, 200);
        g.setColor(Color.black);
        g.drawString(Heading, 20, 20);
        g.setColor(Color.WHITE);
        g.drawString(A1, 20, 40);
        g.setColor(Color.PINK);
        g.drawString(B2, 20, 60);
        g.setColor(Color.RED);
        g.drawString(C3, 20, 80);
        g.setColor(Color.ORANGE);
        g.drawString(D4, 20, 100);
        g.setColor(Color.MAGENTA);
        g.drawString(E5, 20, 120);
    }

    /**
     * Returns information about this applet. 
     * An applet should override this method to return a String containing 
     * information about the author, version, and copyright of the JApplet.
     *
     * @return a String representation of information about this JApplet
     */
    public String getAppletInfo()
    {
        // provide information about the applet
        return "Title:   \nAuthor:   \nA simple applet example description. ";
    }


    /**
     * Returns parameter information about this JApplet. 
     * Returns information about the parameters than are understood by this JApplet.
     * An applet should override this method to return an array of Strings 
     * describing these parameters. 
     * Each element of the array should be a set of three Strings containing 
     * the name, the type, and a description.
     *
     * @return a String[] representation of parameter information about this JApplet
     */
    public String[][] getParameterInfo()
    {
        // provide parameter information about the applet
        String paramInfo[][] = {
                 {"firstParameter",    "1-10",    "description of first parameter"},
                 {"status", "boolean", "description of second parameter"},
                 {"images",   "url",     "description of third parameter"}
        };
        return paramInfo;
    }
}
