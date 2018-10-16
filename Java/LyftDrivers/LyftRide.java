public class LyftRide implements Comparable<Person> {
	private int custID;
	private double miles;
	private double minutes;
	
	public LyftRide(int custID, double miles, double minutes) {
		this.custID = custID;
		this.miles = miles;
		this.minutes = minutes;
	}
	
	public String toString() {
		return "LyftRide("+this.custID+","+this.miles+","+this.minutes+")";
	}
}