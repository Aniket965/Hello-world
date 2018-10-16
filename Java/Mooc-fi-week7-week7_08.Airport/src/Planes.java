
import java.util.*;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ritik
 */
public class Planes {
    private ArrayList<Plane> planes;
    
    public Planes(){
        this.planes = new ArrayList<Plane>();
    }
    
    public void addPlane(Plane plane){
        this.planes.add(plane);
    }
    
    public void printPlanes(){
        for(Plane plane: this.planes){
            System.out.println(plane);
        }
    }
    
    public Plane getPlane(String id){
        for(Plane plane: this. planes){
            if(plane.getId().equals(id)){
                return plane;
            }
        }
        return null;
    }
}
