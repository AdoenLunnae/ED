#ifndef __FUNCIONES_HPP
#define __FUNCIONES_HPP

#include <iostream>
#include <cstring>
#include <cstdlib> //Para usar system
#include <fstream> //Para trabajar con ficheros
#include <sstream>

#include "grafo.hpp"
#include "algoritmosgrafos.hpp"

using namespace std;
using namespace ed;

int menu()
{
    int opcion;

    system("clear");
    cout << "  0. Salir................................\n";
    cout << "  1. Cargar grafo desde fichero...........\n";
    cout << "  2. Algoritmo de Floyd (GD y GND)......\n";

    cout << "Introduzca opcion...:";
    cin >> opcion;

    return opcion;
}

template <class G_Nodo, class G_Lado>

bool cargarGrafo(Grafo<G_Nodo, G_Lado> * &g)
{
    string ficheroMatriz, ficheroEtiquetas;
    string tokenLabels, tokenMatrix;
    int numberRows = 0;

    cout << "Fichero de la matriz de conexion: ";
    cin >> ficheroMatriz;

    cout << "Fichero de las etiquetas: ";
    cin >> ficheroEtiquetas;

    ifstream matrix(ficheroMatriz.c_str(), ifstream::in);
    ifstream labels(ficheroEtiquetas.c_str(), ifstream::in);
    if (!matrix.is_open())
    {
        cout << "Error al abrir el fichero de la matriz\n";
        return (false);
    }
    else if (!labels.is_open())
    {
        cout << "Error al abrir el fichero de etiquetas\n";
        return (false);
    }

    while (getline(labels, tokenLabels))
    {
        numberRows++;
    }
    labels.close();
    labels.open(ficheroEtiquetas.c_str(), ifstream::in);
    g->reservaMemoria(numberRows);

    for (int i = 0; i < g->getNumNodos(); ++i)
    {
        getline(labels, tokenLabels, '\n');

        //Aparece un retorno de carro que hay que eliminar
        if(*(tokenLabels.end() - 1) == '\r')
            tokenLabels.erase(tokenLabels.end() - 1);
        g->setNodo(i, tokenLabels);
        for (int j = 0; j < g->getNumNodos() - 1; ++j)
        {
            getline(matrix, tokenMatrix, ' ');
            g->setLado(i, j, atoi(tokenMatrix.c_str()));
        }
        getline(matrix, tokenMatrix, '\n');
        g->setLado(i, g->getNumNodos() - 1, atoi(tokenMatrix.c_str()));
    }

    matrix.close();
    labels.close();
    g->printNodos();
    g->printLados();
    return (true);
}
int myFind(string* const array, const string target, int size)
{  
    int result;
    for(result = 0; result < size; result++)
    {
        if(target == array[result])
        {
            return result;
        }
    }
    return result;
}
template <class G_Nodo, class G_Lado>
void algoritmoFloyd(const Grafo<G_Nodo, G_Lado> &g)
{
    int **D;
    int **I;
    int posOrigen, posDestino;
    G_Nodo origen;
    G_Nodo destino;
    AlgoritmosGrafos<G_Nodo, G_Lado> algoritmo;
    algoritmo.floyd(g, D, I);
   /*  for(int i = 0; i < g.getNumNodos(); ++i)
    {
        for(int j = 0; j < g.getNumNodos(); ++j)
        {
            cout << D[i][j] << "  ";
        }
        cout << "\n\n";
    }
    cout << "\n\n\n";
    for(int i = 0; i < g.getNumNodos(); ++i)
    {
        for(int j = 0; j < g.getNumNodos(); ++j)
        {
            cout << I[i][j] << "  ";
        }
        cout << "\n\n";
    } */
    G_Nodo *nodos = g.getNodos();
    int size = g.getNumNodos();
    do
    {
        cout << "Introduce el origen:\t";
        cin >> origen;
        cin.ignore();
        posOrigen = myFind(nodos, origen, size);
    } while (posOrigen == size);
    
    do
    {
        cout << "Introduce el destino:\t";
        cin >> destino;
        cin.ignore();
        posDestino = myFind(nodos, destino, size);
    } while (posDestino == size);
    cout << "La distancia de " << origen << " a " << destino << " es " << D[posOrigen][posDestino] << "\n";
    vector<int>result = algoritmo.reconstruirCamino(I, posOrigen, posDestino);
    for(int i = 0; i < result.size() - 1; ++i){
        cout << nodos[i] << " -> ";
    }
    cout << nodos[result.size() - 1] << "\n";

}

#endif
