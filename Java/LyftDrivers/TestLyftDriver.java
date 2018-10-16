public class TestLyftDriver{

	public static void main(String[] args){
		LyftDriver tim = new LyftDriver("Tim", 1, 3.00, 2.00, 0.20);
		LyftDriver jiarui = new LyftDriver("Jiarui", 2, 4.00, 3.00, 0.25);

		System.out.println("Tim: "+tim+"\nJiarui: "+jiarui);

		tim.completeRide(1729, 5.0, 20.0);
		jiarui.completeRide(24, 40.0, 60.0);
		System.out.printf("Tim   completed %3d rides and has made $%.2f total pay. Should be 1 ride for $17\n",
				tim.getNumRides(),tim.getTotalPay());
		System.out.printf("Jiarui completed %3d rides and has made $%.2f total pay. Should be 1 ride for $139\n",
				jiarui.getNumRides(),jiarui.getTotalPay());

		tim.completeRide(314, 20.0, 30.0);
		jiarui.completeRide(271, 4.0, 12.0);
		System.out.printf("Tim   completed %3d rides and has made $%.2f total pay. Should be 2 ride for $66\n",
				tim.getNumRides(),tim.getTotalPay());
		System.out.printf("Jiarui completed %3d rides and has made $%.2f total pay. Should be 2 ride for $158\n",
				jiarui.getNumRides(),jiarui.getTotalPay());

		System.out.println("Tim: "+tim+"\nJiarui: "+jiarui);

	}
}
