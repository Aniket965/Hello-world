/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author ritik
 */
import java.util.*;

public class Flight {

    private HashMap<String, Plane> flights;

    public Flight() {
        this.flights = new HashMap<String, Plane>();
    }

    public void addFlight(String path, Plane plane) {
        this.flights.put(path, plane);
    }

    public void printFlights() {
        for (String path : this.flights.keySet()) {
            System.out.println(this.flights.get(path) + " (" + path + ")");
        }
    }
}
