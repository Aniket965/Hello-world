public class LyftDriver2 extends LyftDriver{
	public LyftRide[] rides = new LyftRide[2];
	public LyftDriver2(String driverName, int driverID, double pickupFee, double distanceFee, double timeFee) {
		super(driverName, driverID, pickupFee, distanceFee, timeFee);
	}
	
	public void completeRide(int passengerID, double distance, double time) {
		double distancePaid, timePaid,totPaid,pickupPaid;
		distancePaid = distance * this.distanceFee ;
		timePaid = time * this.timeFee;
		pickupPaid = this.pickupFee;
		totPaid = distancePaid + timePaid + pickupPaid;
		this.totalPay += totPaid;
		rides[numRides] = new LyftRide(passengerID, distance, time);
		this.numRides += 1;
	}
	
	public LyftRide[] getRides(){
		return rides;
	}
	
}