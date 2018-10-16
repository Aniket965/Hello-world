import java.awt.EventQueue;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

/**
 * Classe GridFrame crea una crea una griglia di bottoni in base ai argomenti
 passati dalla linea di commmando, altrimenti usando dei valori di default che
 sono 10 righe e 10 colonne
 *
 * @author Fadil Smajilbasic
 */
public class GridFrame extends JFrame implements ActionListener {

    /**
     * Varaibile rows definisce quante righe deve avere la griglia
     */
    private int rows;
    /**
     * Varaibile columns definisce quante colonne deve avere la griglia
     */
    private int columns;

    /**
     * Metodo setter per la variabile rows se il valore non è valido viene
     * impostato a 10
     *
     * @param rows il numero di righe da impostare
     */
    public void setRows(int rows) {
        if (rows > 0) {
            this.rows = rows;
        } else {
            this.rows = 10;
        }

    }

    /**
     * Metodo setter per la variabile columns se il valore non è valido viene
     * impostato a 10
     *
     * @param columns rows il numero di colonne da impostare
     */
    public void setColmuns(int columns) {
        if (columns > 0) {
            this.columns = columns;

        } else {
            this.columns = 10;
        }
    }

    /**
     * Metodo costruttore vuoto che richiama il secondo costruttore con i
     * parametri 10 e 10
     */
    public GridFrame() {
        this(10, 10);
    }

    /**
     * Metodo costruttore principale che imposta il layout del contenitore, crea
     * e aggiunge i bottoni al contenitore
     *
     * @param rows il numero di righe della griglia
     * @param columns il numero di colonne della griglia
     */
    public GridFrame(int rows, int columns) {
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);

        setRows(rows);
        setColmuns(columns);

        this.setLayout(new GridLayout(this.rows, this.columns));
        for (int i = 0; i < this.rows; i++) {
            for (int j = 0; j < this.columns; j++) {
                JButton grid = new JButton(j + ":" + i);
                grid.addActionListener(this);
                this.getContentPane().add(grid);
            }
        }
        pack();
        setSize(900, 900);
        this.setVisible(true);
    }

    /**
     * Il medodo paint è responsabile per il disegno della applicazione
     *
     * @param g il contesto grafico
     */
    @Override
    public void paint(Graphics g) {
        super.paint(g);
    }

    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                if (args.length == 2) {
                    try {
                        new GridFrame(Integer.parseInt(args[0]),
                                Integer.parseInt(args[1])
                        );
                    } catch (NumberFormatException e) {
                        new GridFrame();
                    }
                } else {
                    new GridFrame();
                }
            }
        });
    }

    /**
     * Metodo actionPerformed è un metodo della interafccia ActionListener viene
     * chiamato quando un azione viene compiuta su un componente
     *
     * @param e Un evento che indica che un'azione è stata compiuta da un
     * componente
     */
    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println("Button clicked: " + ((JButton) e.getSource()).getText());
    }

}
