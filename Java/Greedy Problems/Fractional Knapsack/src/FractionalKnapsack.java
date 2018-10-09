import java.util.Arrays;
import java.util.Scanner;

class Item{
	
	float weight;
	float profit;
	float pwratio;
	
	public Item(float w , float p , float pw) {
		weight = w;
		profit = p;
		pwratio = pw;
	} 
}
public class FractionalKnapsack {

	public FractionalKnapsack() {
		// TODO Auto-generated constructor stub
	}

	public static Item arr_items[];
	public static void main(String[] args) {
		
		Scanner s = new Scanner(System.in);
		
		System.out.println("Enter the number of item's you have : ");
		int items = s.nextInt();
		
		arr_items = new Item[items];
		
		System.out.println("Enter the Weight of Knapsack : ");
		float W = s.nextFloat();
		int p = 0 , w = 0 , count = 0;
		for(int i = 0 ; i < items ; i++)
		{
			System.out.println("Enter Profit : ");
			p = s.nextInt();
			System.out.println("Enter Weight : ");
			w = s.nextInt();
			
			Item item = new Item(w , p , (float)p/w);
			arr_items[count] = item;
			count++;
			item = null;
		}
		
		getMaxProfit(arr_items , W, count);
	}
	
	public static void getMaxProfit(Item[] arr_items , float Weight , int size)
	{
		float W = Weight;
		Item temp;
		int weightcount = 0;
		
		for(int i = 0 ; i < arr_items.length ; i++)
		{
			for(int j = i+1 ; j < arr_items.length ; j++)
			{
				if(arr_items[i].pwratio < arr_items[j].pwratio)
				{
					temp = arr_items[i];
					arr_items[i] = arr_items[j];
					arr_items[j] = temp;
				}
			}
		}
		
		
			float profit = 0;
			for(int i = 0 ; i < arr_items.length ; i++)
			{
				if(W > arr_items[i].weight) {
					profit = profit + arr_items[i].profit;
					W = W - arr_items[i].weight;
					weightcount++;
				}
				else 
				{
					//W = arr_items[i].weight - W;
					profit = profit + (arr_items[i].pwratio * W);
					W = 0;
					weightcount++;
				}
				
				if(W == 0)
					break;
			}
		
		System.out.println("The Maximum Profit = " + profit);
		System.out.println("The number of item's user  = " + weightcount++);
	}

}
