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

bool cargarGrafo(Grafo<G_Nodo, G_Lado> *g)
{
    string ficheroMatriz, ficheroEtiquetas;
    string tokenLabels, tokenMatrix;
    int numberRows = 0;

    cout << "Fichero de la matriz de conexion: ";
    cin >> ficheroMatriz;

    cout << "Fichero de las etiquetas: ";
    cin >> ficheroEtiquetas;

    ifstream matrix(ficheroMatriz, ifstream::in);
    ifstream labels(ficheroEtiquetas, ifstream::in);
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
    labels.open(ficheroEtiquetas);
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

template <class G_Nodo, class G_Lado>
void algoritmoFloyd(const Grafo<G_Nodo, G_Lado> &g)
{
    // TODO
}

#endif
