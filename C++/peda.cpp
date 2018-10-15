#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Persona
{
    private:
        string nombre;
        bool estaPeda = false;
        bool estaIntoxicada = false;

    public:
        void setNombre(string nombre) { this->nombre = nombre; }
        void setEstaPeda(bool estaPeda) { this->estaPeda = estaPeda; }
        void setEstaIntoxicada(bool estaIntoxicada) { this->estaIntoxicada = estaIntoxicada; }
        string getNombre() { return this->nombre; }
};

class Peda : public Persona
{
    private:
        bool alcohol;
        bool cigarros;
        bool comida;
        vector<Persona> personas;
        bool alguienEstaPeda = false;
        bool alguienSeIntoxico = false;

    public:
        Peda(bool alcohol, bool cigarros, bool comida)
        {
            this->alcohol = alcohol;
            this->cigarros = cigarros;
            this->comida = comida;

            cout << "Se esta armando la peda.\n" << endl;
        }

        void invitar(int invitaciones)
        {
            string nombre;
            this->personas.resize(invitaciones);

            for(int i=0; i<invitaciones; i++)
            {
                cout << "ingresa el nombre del invitado " << i+1 << ": "; cin >> nombre;
                this->personas[i].setNombre(nombre);
            }

            cout << endl;
        }

        bool seArmo() { if(this->personas.size()>=20 and this->alcohol == true) { return true; } else { return false;  } }

        void alcoholizar()
        {
            srand(time(NULL));
            for(int i=0; i<this->personas.size(); i++)
            {
                if(rand() % 2)
                {
                    personas[i].setEstaPeda(true);
                    cout << personas[i].getNombre() << " esta PEDA!" << endl;
                    this->alguienEstaPeda = true;
                }
            }

            cout << endl;
        }

        void Intoxicar()
        {
            srand(time(NULL));
            for(int i=0; i<this->personas.size(); i++)
            {
                if(rand() % 2)
                {
                    personas[i].setEstaIntoxicada(true);
                    cout << personas[i].getNombre() << " se INTOXICO!" << endl;
                    this->alguienSeIntoxico = true;
                }
            }

            cout << endl;
        }

        bool esSegura() { if(this->alguienEstaPeda or this->alguienSeIntoxico){ return false; } else { return true; } }

        ~Peda() { cout << "\n\nSe acabo la peda." << endl; }
};

int main()
{
    int invitaciones;
    Peda *peda = new Peda(true, true, true);

    cout << "cuantos vas a invitar: "; cin >> invitaciones; cout << endl;

    peda->invitar(invitaciones);

    if(peda->seArmo())
    {
        peda->alcoholizar();
        peda->Intoxicar();

        if(peda->esSegura()) { cout << "pasala tranqui prro"; } else { cout << "Sal de ahiii!!!"; }
    } else { cout << "No se armo :c"; }

    delete(peda);
}
