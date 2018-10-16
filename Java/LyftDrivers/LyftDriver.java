public class LyftDriver{
	protected String driverName;
	protected int driverID;
	protected double pickupFee;
	protected double distanceFee;
	protected double timeFee;
	
	protected double totalPay = 0;
	protected int numRides = 0;
	
	public LyftDriver(String driverName, int driverID, double pickupFee, double distanceFee, double timeFee) {
		this.driverName = driverName;
		this.driverID = driverID; 	
		this.pickupFee = pickupFee;
		this.distanceFee = distanceFee;
		this.timeFee = timeFee;
	}
	
	public void completeRide(int passengerID, double distance, double time) {
		double distancePaid, timePaid,totPaid,pickupPaid;
		distancePaid = distance * this.distanceFee ;
		timePaid = time * this.timeFee;
		pickupPaid = this.pickupFee;
		totPaid = distancePaid + timePaid + pickupPaid;
		this.totalPay += totPaid;
		this.numRides += 1;
	}
	
	public String toString() {
		return "driver("+this.driverName+","+this.driverID+","+this.totalPay+","+this.numRides+")";
	}
	
	public double getTotalPay(){
		return this.totalPay;
	}
	
	public int getNumRides() {
		return this.numRides;
	}
	
	
}