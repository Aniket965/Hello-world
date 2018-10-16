//package pq1;

public class TestCarPool {
	static CarPool[] cars = new CarPool[100];
	static int numCars = 0;
	public static void main(String[] args) throws Exception{
		TestCarPool.initCars();
		TestCarPool.printCars();
		TestCarPool.loadCars();
		TestCarPool.printCars();
		TestCarPool.changeCars();
		TestCarPool.printCars();
	}

	public static void initCars(){
		TestCarPool.cars[0] = new CarPool("Tim Hickey","Coolidge Corner","8 am","5 pm",4);
		TestCarPool.cars[1] = new CarPool("Pito Salas","Lexington Center","10 am","6 pm",4);
		TestCarPool.cars[2] = new CarPool("Bruno Mars","Harvard Square","11 am","9 pm",1);
		TestCarPool.numCars=3;

	}

	public static void loadCars() throws Exception{
		cars[0].addRider(2);
		cars[1].addRider(4);
		cars[2].addRider(1);
	}

	public static void changeCars() throws Exception{
		cars[0].addRider(1);
		cars[1].removeRider(3);
		cars[2].removeRider(1);
	}

	public static void printCars(){
		for(int i=0; i<TestCarPool.numCars; i++){
			System.out.printf("car #%d: %s\n",i,TestCarPool.cars[i]);
		}

	}
}