import java.util.Scanner;

class PilhaComArray {
	private static int[] pilha;
	private static int head;
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		
		int tamanho = Integer.parseInt(scanner.nextLine());
		criaPilha(tamanho);
		String operacoes;
		operacoes = scanner.nextLine();
		while(!(operacoes.equals("end"))) {
			if(operacoes.equals("peek")) {
				System.out.println(peek());
			} else if( operacoes.equals("pop")) {
				pop();
			} else if(operacoes.equals("print")) {
				System.out.print(print());
			} else {
				String[] entrada = operacoes.split(" ");	
				push(Integer.parseInt(entrada[1]));
			}
			operacoes = scanner.nextLine();
		}
	}
	
	public static void criaPilha(int tamanho) {
		pilha = new int[tamanho];
		head = -1;
	}
	
	public static boolean isEmpty() {
		return head == -1;
	}
	
	public static boolean isFull() {
		return head == (pilha.length-1);
	}
	
	public static String print() {
		if(isEmpty()) {
			return "empty\n" ;
		}
		String conteudo = "";
		for(int i = 0; i <= head; i++) {
			conteudo += pilha[i] + " ";
		}
		return conteudo.trim() + "\n";
	}
	
	public static String peek() {
		if(isEmpty()) {
			return "empty";
		}
		String saida = "";
		saida += pilha[head];
		return saida;
	}
	
	public static void push(int n) {
		if(isFull()) {
			System.out.println("full");
		} else {
		head++;
		pilha[head] = n;
		}
	}
	
	public static void pop() {
		if(isEmpty()) {
			System.out.println("empty");
		} else {
			head--;
		}
	}
	
}