#ifndef __ALGORITMOSGRAFOS_H__
#define __ALGORITMOSGRAFOS_H__
#include <iostream>

#include "grafo.hpp"
using namespace ed;
using namespace std;

template <class G_Nodo, class G_Lado>
class AlgoritmosGrafos
{


private:
    void copy(int ** &target, const Grafo<G_Nodo, G_Lado> &g)
    {
        int size = g.getNumNodos();
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                target[i][j] = g.getLado(i, j);
            }
        }
    }
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
    void floyd(const Grafo<G_Nodo, G_Lado> &g, int ** &D, int ** &I)
    {
        int n = g.getNumNodos();
        D = new int *[n];
        I = new int *[n];
        for (int i = 0; i < n; ++i)
        {
            D[i] = new int[n];
            I[i] = new int[n];
        }
        copy(D, g);
        for(int k = 0; k < n; ++k)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; ++j)
                {
                    if(D[i][k] + D[k][j] < D[i][j])
                    {
                        D[i][j] = D[i][k] + D[k][j];
                        I[i][j] = k;
                    }
                }
            }
        }
    }
};

#endif