
import java.util.*;

public class Main {

    public static void main(String[] args) {
        // Write your main program here. Implementing your own classes will be useful.
        
        Scanner reader = new Scanner(System.in);
        Planes planes = new Planes();
        Flight flights = new Flight();
        airportPanel(reader, planes, flights);
        flightService(reader, planes, flights);
    }

    public static void airportPanel(Scanner reader, Planes planes, Flight flights) {
        System.out.println("Airport panel\n" +
"--------------------");
        
        System.out.println();
        
        while (true) {
            printAirportMenu();
            String input = reader.nextLine();

            if (input.equals("1")) {
                addAirplane(reader, planes);
            }

            if (input.equals("2")) {
                addFlight(reader, planes, flights);
            }
            if (input.equals("x")) {
                break;
            }
        }
    }

    public static void flightService(Scanner reader, Planes planes, Flight flights) {
        System.out.println("Flight service\n" +
"------------");
        
        System.out.println();
        
        while (true) {
            printFlightMenu();
            String input = reader.nextLine();
            
            if(input.equals("1")){
                planes.printPlanes();
            }
            if(input.equals("2")){
                flights.printFlights();
            }
            if(input.equals("3")){
                System.out.print("Give plane ID: ");
                String id = reader.nextLine();
                System.out.println(planes.getPlane(id));
            }
            if (input.equals("x")) {
                break;
            }
        }
    }

    public static void printAirportMenu() {
        System.out.println("Choose operation:\n"
                + "[1] Add airplane\n"
                + "[2] Add flight\n"
                + "[x] Exit");

    }

    public static void addAirplane(Scanner reader, Planes planes) {
        System.out.print("Give plane ID: ");
        String id = reader.nextLine();
        System.out.print("Give plane capacity: ");
        int cap = Integer.parseInt(reader.nextLine());
        planes.addPlane(new Plane(id, cap));
    }

    public static void addFlight(Scanner reader, Planes planes, Flight flights) {
        System.out.print("Give plane ID: ");
        String id = reader.nextLine();
        Plane newPlane = planes.getPlane(id);
        System.out.print("Give departure airport code: ");
        String path = reader.nextLine() + "-";
        System.out.print("Give destination airport code: ");
        path = path + reader.nextLine();
        flights.addFlight(path, newPlane);
    }

    public static void printFlightMenu() {
        System.out.println("Choose operation:\n"
                + "[1] Print planes\n"
                + "[2] Print flights\n"
                + "[3] Print plane info\n"
                + "[x] Quit");
    }
}
