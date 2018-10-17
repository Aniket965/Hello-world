#include <iostream>
#include <ctime>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
using namespace std;

void iniciarcasillas(char gato[3][3]);
void imprimirgato(char gato[3][3]);
int validacasilla(int fila, int columna);
int validaganador(char jugador);
int validaempate(int contador, int ganador);

void iniciarcasillas(char gato[3][3])
{
    gato[0][0]= '-';
    gato[1][0]= '-';
    gato[2][0]= '-';
    gato[0][1]= '-';
    gato[1][1]= '-';
    gato[2][1]= '-';
    gato[0][2]= '-';
    gato[1][2]= '-';
    gato[2][2]= '-';
}

void imprimirgato(char gato[3][3])
{
    char lv=179, lh=196;
    int i=0, j=0;
    gato[3][3]=gato[j][i];
    cout<<"\n\n"<<lh<<lh<<lh<<lh<<lh<<lh<<lh<<lh<<endl;
    for (j=0; j<3; j++)
    {
        cout<<lv;
        for (i=0; i<3; i++)
        {
            cout<<gato[j][i]<< " " ;
        }
        cout<<""<<lv<<endl;
    }
    cout<<lh<<lh<<lh<<lh<<lh<<lh<<lh<<lh<<"\n\n"<<endl;

}

int validacasilla (int fila, int columna, char gato[3][3])
{
    int valido;
    system("cls");
    if (gato[fila][columna]=='O' || gato[fila][columna]=='X')
    {
        valido=0;
        cout <<"Casilla ocupada, intentalo de nuevo. :c" <<endl;
    }
    else
    {
        valido=1;
    }
    if ((fila>3 || fila<0) || (columna>3 || columna<0))
    {
        cout<<"Casilla fuera de rango >:c "<<endl;
        valido=0;
    }
    return valido;
}
int validaganador (char jugador, char gato[3][3])
{

    int ganador=0;
    if (
        //Casos horizontales
        (gato[0][0]==jugador && gato[0][1]==jugador && gato[0][2]==jugador) ||
        (gato[1][0]==jugador && gato[1][1]==jugador && gato[1][2]==jugador) ||
        (gato[2][0]==jugador && gato[2][1]==jugador && gato[2][2]==jugador) ||
        //casos verticales
        (gato[0][0]==jugador && gato[1][0]==jugador && gato[2][0]==jugador) ||
        (gato[0][1]==jugador && gato[1][1]==jugador && gato[2][1]==jugador) ||
        (gato[0][2]==jugador && gato[1][2]==jugador && gato[2][2]==jugador) ||
        //casos diagonales
        (gato[0][0]==jugador && gato[1][1]==jugador && gato[2][2]==jugador) ||
        (gato[0][2]==jugador && gato[1][1]==jugador && gato[2][0]==jugador))
    {
        ganador=1;
        system("cls");
        cout <<"El ganador es... " <<jugador<<endl;
    }
    return ganador;
}
int validaempate (int contador, int ganador)
{
    if (contador==9 && ganador==0)
    {
        cout<<"Juego empatado... o-o"<<endl;
        return 1;
    }
    return 0;
}

int main ()
{
    char jugador1, jugador2;
    int ganador=0, empate=0;
    char caracteres[2]= {'O', 'X'};
    char gato[3][3];
    int inicia;
    int contador=0;
    //Esta funcion es para elige quien inicia, si X o O ^^
    iniciarcasillas(gato);

    srand(time(NULL));
    inicia=rand()%2;
    if (inicia==0)
    {
        jugador1=caracteres[0];
        jugador2=caracteres[1];
    }
    else if (inicia==1)
    {
        jugador1=caracteres[1];
        jugador2=caracteres[0];
    }
    cout <<"G A T O: Como ingresar jugadas *u*"<<endl;
    cout <<"Para ingresar una jugada, selecciona una fila y una columna"<<endl;
    cout <<"Ejemplo: fila 0, columna 2. ^^)/"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout <<"Empieza el jugador: " <<jugador1<< " :)"<<endl;
    cout <<"... ¡¡¡¡¡¡ H O R A  D E  J U G A R !!!!! (-w-)9 "<<endl;
    cout<<" " <<endl;
    while (ganador==0 && empate==0)
    {
        int fila, columna;
        int valido=0;
        while (valido==0)
        {
            imprimirgato(gato);
            cout <<"Turno del jugador: " <<jugador1<<endl;
            cout <<"Dame la fila; usa 0, 1, o 2 ^^"<<endl;
            cin>>fila;
            cout <<"Dame columna; usa 0, 1, o 2 ^^"<<endl;
            cin>>columna;
            valido=validacasilla(fila, columna, gato);

        }
        gato[fila][columna]=jugador1;
        ganador=validaganador(jugador1, gato);
        valido=0;
        contador++;
        empate=validaempate(contador, ganador);
        while (valido==0)
        {
            if (ganador==0 && empate==0)
            {
                imprimirgato(gato);
                cout <<"Turno del jugador: " <<jugador2<<endl;
                cout <<"Dame la fila; usa 0, 1, o 2 ^^"<<endl;
                cin>>fila;
                cout <<"Dame columna; usa 0, 1, o 2 ^^"<<endl;
                cin>>columna;
                valido=validacasilla (fila, columna, gato);

            }
            else
            {
                valido=1;
            }
        }
        if (ganador==0 && empate==0)
        {
            gato[fila][columna]=jugador2;
            ganador=validaganador(jugador2, gato);
            contador++;
            empate=validaempate(contador, ganador);
        }
    }
    imprimirgato(gato);
    cin.get();
    return 0;
}
