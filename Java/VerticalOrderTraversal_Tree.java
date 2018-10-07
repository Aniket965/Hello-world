
import java.util.Map;
import java.util.TreeMap;
import java.util.Vector;

class tree{

    Node root;

    tree(){
        root=null;
    }


}

public class VerticalOrderTraversal {

    public static void main(String[] args) {

        tree t= new tree();
        t.root = new Node(1);
        t.root.left = new Node(2);
        t.root.right = new Node(3);
        t.root.left.left = new Node(4);
        t.root.left.right = new Node(5);
        t.root.right.left = new Node(6);
        t.root.right.right = new Node(7);
        t.root.right.left.right = new Node(8);
        t.root.right.right.right = new Node(9);

        System.out.println("Vertical Order traversal is");
        VO(t.root);

    }

    public static void VO(Node root){

        TreeMap<Integer,Vector<Integer>> m= new TreeMap<>();
        int hd=0;
        VerticalOrder(root,hd,m);
        for (Map.Entry<Integer, Vector<Integer>> entry : m.entrySet())
        {
            System.out.println(entry.getValue());
        }

    }

    public static void VerticalOrder(Node root, int hd, TreeMap<Integer,Vector<Integer>> m) {

        if(root==null)
            return;

        Vector<Integer> get =m.get(hd);

        if(get==null){

            get = new Vector<>();
            get.add(root.data);

        }
        else{
            get.add(root.data);
        }

        m.put(hd,get);

        VerticalOrder(root.left,hd-1,m);
        VerticalOrder(root.right,hd+1,m);



    }
}
