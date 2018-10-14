import java.util.Collections;
import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;

public class LinkedListRecursion {
	public static void main(String Args[]) {
		LinkedList<Integer> ordered = new LinkedList<Integer>();
		LinkedList<Integer> unordered = new LinkedList<Integer>();
		Scanner input = new Scanner(System.in);
		int x, y, num;
		System.out.print("Enter num of integers: ");
		num = input.nextInt();
		if (num <= 0) {
			System.out.println("Wrong input! goodbye");
		} else {
			System.out.print("Enter the range: \nx= ");
			x = input.nextInt();
			System.out.print("y= ");
			y = input.nextInt();
			if (x < y) {
				int temp = x;
				x = y;
				y = temp;
			}
			Random rand = new Random();
			for (int i = 0; i < num; i++) {
				int value = y + rand.nextInt(x - y) + 1;
				unordered.add(value);
			}
			System.out.print("Elements of unorder list: ");
			for (int i = 0; i < unordered.size(); i++) {
				System.out.print(unordered.get(i) + " ");
			}
			System.out.println("\nThe max is: " + findMax(unordered, unordered.get(--num), 0));
			System.out.print("The min is: " + findMin(unordered, unordered.get(--num), 0));
			ordered = unordered;
			Collections.sort(ordered);
			System.out.print("\nElements of ordered list: ");
			for (int i = 0; i < unordered.size(); i++) {
				System.out.print(ordered.get(i) + " ");
			}
		}

	}

	public static int findMax(LinkedList<Integer> list, int max, int size) {

		if ((size + 1 > list.size())) {
			return max;
		}

		else {
			int newMax = list.get(size);
			if (max < newMax) {
				return findMax(list, newMax, size + 1);
			} else
				return findMax(list, max, size + 1);
		}
	}

	public static int findMin(LinkedList<Integer> list, int min, int size) {

		if ((size + 1 > list.size())) {
			return min;
		}

		else {
			int newMin = list.get(size);
			if (min > newMin) {
				return findMin(list, newMin, size + 1);
			} else
				return findMin(list, min, 1 + size);
		}
	}
}
