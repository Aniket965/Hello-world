import java.util.Scanner;

public class ValidaCPF
{
	public static void main(String[] args)
	{
		Scanner teclado;
		teclado = new Scanner(System.in);
		int CPF[], i, multiplicador, soma, resto, DV1, DV2;
		CPF = new int[11];

		System.out.println("Entre com o CPF que deseja validar:");
		for (i = 0; i < 11; i++)
		{
			System.out.print("Informe o " + (i+1) + "� d�gito do CPF: ");
			CPF[i] = teclado.nextInt();
		}

		// c�lculo do 1� d�gito verificador

		multiplicador = 10;
		soma = 0;

		for (i = 0; i < 9; i++)
		{
			soma = soma + multiplicador * CPF[i];
			multiplicador--;
		}

		resto = soma % 11;
		if (resto < 2)
			DV1 = 0;
		else
			DV1 = 11 - resto;

		// c�lculo do 2� d�gito verificador

		multiplicador = 11;
		soma = 0;

		for (i = 0; i < 10; i++)
		{
			soma = soma + multiplicador * CPF[i];
			multiplicador--;
		}

		resto = soma % 11;
		if (resto < 2)
			DV2 = 0;
		else
			DV2 = 11 - resto;

		System.out.println();

		if ((DV1 == CPF[9]) && (DV2 == CPF[10]))
			System.out.println("CPF V�LIDO!");
		else
			System.out.println("CPF INV�LIDO!");

		System.out.print("O CPF ");
		for (i = 1; i < 12; i++)
		{
			System.out.print(CPF[i-1]);
			if (i % 9 == 0)
				System.out.print("-");
			else
				if (i % 3 == 0)
					System.out.print(".");
		}

		if ((DV1 == CPF[9]) && (DV2 == CPF[10]))
			System.out.print(" � V�LIDO!");
		else
			System.out.print(" � INV�LIDO!");

		teclado.close();
	}
}
