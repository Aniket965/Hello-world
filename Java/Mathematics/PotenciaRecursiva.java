public class PotenciaRecursiva {

	public static double potencia(int base, int expoente) {

		if (base == 0 && expoente == 0) { throw new IllegalArgumentException("indeterminação 0^0!"); }
		if (base == 0 && expoente < 0) { throw new IllegalArgumentException("indeterminação, divisão por zero!"); }

		if (base == 0) { return 0; }
		if (expoente == 0) { return 1; }

		if (ehNegativo(expoente)) {
			double b = potencia(base, -expoente);
			return 1 / b;
		}

		if (ehPar(expoente)) {
			double baseElevadaAMetadeDoExpoente = potencia(base, expoente / 2);
			return baseElevadaAMetadeDoExpoente * baseElevadaAMetadeDoExpoente;
		}
		else {
			return potencia(base, expoente - 1) * base;
		}

	}

	private static boolean ehPar(int numero) {
		return numero % 2 == 0;
	}

	private static boolean ehNegativo(int numero) {
		return numero < 0;
	}

}
