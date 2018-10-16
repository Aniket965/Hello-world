public class TestLyftDriver2{

	public static void main(String[] args){
		LyftDriver2 tim = new LyftDriver2("Tim", 1, 3.00, 2.00, 0.20);
		LyftDriver2 jiarui = new LyftDriver2("Jiarui", 2, 4.00, 3.00, 0.25);

		System.out.println("Tim: "+tim+"\nJiarui: "+jiarui);
		tim.completeRide(1729, 5.0, 20.0);
		jiarui.completeRide(24, 40.0, 60.0);
		System.out.println("Tim: "+tim+"\nJiarui: "+jiarui);
		tim.completeRide(314, 20.0, 30.0);
		jiarui.completeRide(271, 4.0, 12.0);
		System.out.println("Tim: "+tim+"\nJiarui: "+jiarui);

		System.out.println("\n\nTesting the getRides method\n\n");

		printRides(tim);  printRides(jiarui);

	}


	public static void printRides(LyftDriver2 driver){
		System.out.println("Driver: "+driver);
		LyftRide[] rides = driver.getRides();
		for (int i=0; i<rides.length; i++){
			System.out.println(rides[i]);
		}
		System.out.println("------\n\n");
	}


	// this version is easier, but doesn't print the index....
	public static void printRides2(LyftDriver2 driver){
		System.out.println("Driver: "+driver);
		for (LyftRide ride: driver.getRides()){
			System.out.println(ride);
		}
		System.out.println("------\n\n");
	}
}
