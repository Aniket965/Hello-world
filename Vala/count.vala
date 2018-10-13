
void start  (int min, int max) {
        int try_count = 0;
        int number = Random.int_range (min, max);

        stdout.printf ("Bienvenido a Adivina el número\n\n");
        stdout.printf ("Tengo pensado un número entre %d y %d, ", min, max);
        stdout.printf ("el cual tienes que adivinar. Pero tranquilo, te voy");
        stdout.printf ("a dar algunas pistas\n\n");

        while (true) {
            try_count++;

            stdout.printf ("Intento #%d\n", try_count);
            stdout.printf ("Por favor ingrese un número entre %d y %d: ", min, max);
            int input = int.parse (stdin.read_line ());

            if (number == input) {
                stdout.printf ("¡Ganador! Lo hiciste en %d intentos\n", try_count);
                break;
            } else {
                stdout.printf ("Error, el número es %s que %d.\n",
                               number > input ? "mayor" : "menor", input);
            }
        }
    }
static int main (string[] args){
	stdout.printf("Ingrese el mínimo: ");
	int min = int.parse(stdin.read_line());
	stdout.printf("Ingrese el máximo: ");
	int max = int.parse(stdin.read_line());
	start(min, max);
	return 0;

}
