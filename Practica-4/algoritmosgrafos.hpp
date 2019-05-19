#ifndef __ALGORITMOSGRAFOS_H__
#define __ALGORITMOSGRAFOS_H__
#include <iostream>
#include <algorithm>
#include <vector>

#include "grafo.hpp"
using namespace ed;
using namespace std;

template <class G_Nodo, class G_Lado>
class AlgoritmosGrafos
{

    /*
W: matriz de adyacencia
D: matriz de distancias
I: matriz de intermedios
Floyd(IN: W[N,N]; OUT: D[N,N],I[N,N])
Begin
D ← W  al principio D es igual a W
I ← 0  no hay nodos intermedios
For k From 1 To N Do
    For i From 1 To N Do
        For j From 1 To N Do
            If D[i,k]+D[k,j]<D[i,j] Then
                D[i,j] ← D[i,k]+D[k,j]
                I[i,j] ← K
            End-If
        End-For
    End-For
End-For
End.
*/
public:
    void floyd(const Grafo<G_Nodo, G_Lado> &g, int **&D, int **&I)
    {
        int n = g.getNumNodos();
        D = new int *[n];
        I = new int *[n];
        for (int i = 0; i < n; ++i)
        {
            D[i] = new int[n];
            I[i] = new int[n];
        }
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; j++)
            {
                D[i][j] = g.getLado(i, j);
                I[i][j] = -1;
            }
        }
        for (int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; ++j)
                {
                    if (D[i][k] + D[k][j] < D[i][j])
                    {
                        D[i][j] = D[i][k] + D[k][j];
                        I[i][j] = k;
                    }
                }
            }
        }
    }

    vector<int> reconstruirCamino(int **const I, int origen, int destino)
    {
        vector<int> result;
        std::vector<int>::iterator it;
        int intermedio = I[origen][destino];
        result.push_back(origen);
        if (intermedio != -1)
        {
            result = reconstruirCamino(I, origen, intermedio, result);
            result = reconstruirCamino(I, intermedio, destino, result);
        }
        result.push_back(destino);
        it = std::unique(result.begin(), result.end());
        result.resize(std::distance(result.begin(), it));
        return (result);
    }

    vector<int> reconstruirCamino(int **const I, int origen, int destino, vector<int> &result)
    {
        int intermedio = I[origen][destino];
        result.push_back(origen);
        if (intermedio != -1)
        {
            result = reconstruirCamino(I, origen, intermedio, result);
            result = reconstruirCamino(I, intermedio, destino, result);
        }
        result.push_back(destino);
        return (result);
    }
};

#endif