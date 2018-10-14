import java.util.HashMap;
import java.util.Map;

/*
 * Disjoint sets using path compression and union by rank
 * Supports 3 operations
 * 1) makeSet
 * 2) union
 * 3) findSet
 * total time will be O(m). 
 */
public class DisjointSet 
{

    Map<Long, Node> map = new HashMap<>();
    class Node {
        long data;
        Node parent;
        int rank;
    }
// making singleton sets of different elements
    public void makeSet(long data) 
    {
        Node node = new Node();
        node.data = data;
        node.parent = node;
        node.rank = 0;
        map.put(data, node);
    }
    
// merging two sets , if both are already from same set then do not merge them 
// otherwise we have to merge them 

    public boolean union(long data1, long data2) 
    {
        Node node1 = map.get(data1);
        Node node2 = map.get(data2);

        Node parent1 = findSet(node1);
        Node parent2 = findSet(node2);
        
        if (parent1.data == parent2.data)
        {
            return false;
        }

        // set rank wise 
        // 1st element of union will be representative 
        if (parent1.rank >= parent2.rank) 
        {
            //increment rank only if both sets have same rank
            parent1.rank = (parent1.rank == parent2.rank) ? parent1.rank + 1 : parent1.rank;
            parent2.parent = parent1;
        } else {
            parent1.parent = parent2;
        }
        return true;
    }

   // finding representative 
    public long findSet(long data) 
    {
        return findSet(map.get(data)).data;
    }

    // doing path compression 
    
    private Node findSet(Node node) 
    {
        Node parent = node.parent;
        if (parent == node)
        {
            return parent;
        }
        node.parent = findSet(node.parent);
        return node.parent;
    }

    public static void main(String args[]) {
        DisjointSet ds = new DisjointSet();
        ds.makeSet(1);
        ds.makeSet(2);
        ds.makeSet(3);
        ds.makeSet(4);
        ds.makeSet(5);
        ds.makeSet(6);
        ds.makeSet(7);

        ds.union(1, 2);
        ds.union(2, 3);
        ds.union(4, 5);
        ds.union(6, 7);
        ds.union(5, 6);
        ds.union(3, 7);

        System.out.println(ds.findSet(1));
        System.out.println(ds.findSet(2));
        System.out.println(ds.findSet(3));
        System.out.println(ds.findSet(4));
        System.out.println(ds.findSet(5));
        System.out.println(ds.findSet(6));
        System.out.println(ds.findSet(7));
    }
}
