// queue::push/pop

#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Contacto.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe los datos del objeto contacto (dado) en un archivo binario con el nombre dado en la posicion dada
//Nota: Se deben poder agregar varios contactos en un solo archivo
void escribir(string nombre_archivo, Contacto*contacto, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in);
    out.seekp(34*posicion);
    out.write(contacto->nombre.c_str(),10);
    out.write(contacto->correo.c_str(),20);
    out.write((char*)&contacto->numero,4);
    out.close();
}

//Devuelve un contacto previamente escrito (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varios contactos de un solo archivo
Contacto* leer(string nombre_archivo, int posicion)
{
    ifstream in(nombre_archivo.c_str());
    char nombre[10];
    char correo[20];
    int numero;

    in.seekg(34*posicion);

    in.read(nombre,10);
    in.read(correo,20);
    in.read((char*)&numero,4);

    in.close();

    Contacto *c = new Contacto(nombre,correo,numero);
    return c;
}

//Devuelve un vector que contenga todos los nombres de los contactos previamente ingresados en el archivo con nombre dado
vector<string> getNombres(string nombre_archivo)
{
    vector<string>nombres;
    char nombre_leido[10];
    int tam;
        ifstream in(nombre_archivo.c_str());

        in.seekg(0,ios::end);
        tam = in.tellg()/34;
        in.seekg(0,ios::beg);

        for(int i=0;i<tam;i++)
        {
            in.read(nombre_leido,10);
            nombres.push_back(nombre_leido);
        }
    return nombres;
}

//Devuelve true si valor_buscado (dado) se encuentra dentro de mi_cola (dada), de lo contrario devuelve false
bool existe(queue<char> mi_cola, char valor_buscado)
{
    char resultado;
    while(!mi_cola.empty())
    {
        resultado = mi_cola.front();
        mi_cola.pop();
        if(resultado==valor_buscado)
        return true;
    }
    return false;
}

//Devuelve true si valor (dado) existe dentro de mi_set (dado)
bool existe(set<int> mi_set,int valor)
{
    if(mi_set.find(valor)!=mi_set.end())
        return true;
    return false;
}

//Devuelve una lista inversa de mi_lista (dada)
list<double> invertir(list<double>mi_lista)
{
    double numero;
    list<double> invertida;

    for(list<double>::iterator i=mi_lista.begin();i!=mi_lista.end();i++)
    {
        numero = *i;
        invertida.push_front(numero);
    }
    return invertida;
}

//Devuelve la cantidad de nodos que contiene un arbol con raiz dada
int contar(NodoBinario* raiz)
{
    int cant=0;
      for(NodoBinario*i=raiz;i!=NULL;i=i->hijo_izq)
        {
            if(i->hijo_izq!=NULL)
            {
                cant++;
            }

            for(NodoBinario*d=i;d!=NULL;d=d->hijo_der)
            {
                if(d->hijo_der!=NULL)
                {
                     cant++;
                }
            }
        }
    return cant;
}

//Cambia todos los valores de un arbol con raiz dada
void cambiarValores(NodoBinario* raiz,int nuevo_valor)
{
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}

