public class CarPool{
	
	private String name;
	private String place; 
	private String pickupTime; 
	private String departTime;
	private int availableSeats;
	
	public CarPool(String name, String place, String pickupTime, String departTime, int availableSeats) {
		this.name = name;
		this.place = place;
		this.pickupTime = pickupTime;
		this.departTime = departTime;
		this.availableSeats = availableSeats;
	}
	
	public String toString() {
		return "carpool("+this.name+" leaves "+this.place+" at "+this.pickupTime+" returns "+this.departTime+" has "+this.availableSeats+" availible seats)";
	}
	
	public void addRider(int a) {
		this.availableSeats -= a;
	}
	
	public void removeRider(int a) {
		this.availableSeats += a;
	}
	
	public int getAvailibleSeats() {
		return this.availableSeats;
	}
	
}