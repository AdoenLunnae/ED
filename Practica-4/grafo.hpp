#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <cassert>
#include <iostream>
#include <string>

using namespace std;

namespace ed
{

template <class G_Nodo, class G_Lado>
class Grafo
{
public:
    G_Lado **_lados;

    G_Nodo *_nodos;

    int _numNodos;

public:
    // constructores
    Grafo()
    {
        _lados = new G_Lado *;
        _nodos = new G_Nodo;
        _numNodos = 0;
    }

    Grafo(int const n)
    {
        reservaMemoria(n);
    }

    void reservaMemoria(int n)
    {
        //borrarGrafo();
        setNumNodos(n);
        _lados = new G_Lado *[n];
        for (int i = 0; i < n; i++)
        {
            _lados[i] = new G_Lado[n];
        }
        _nodos = new G_Nodo[n];
    }

    Grafo(const Grafo<G_Nodo, G_Lado> &g)
    {
        int n = g.getNumNodos();
        reservaMemoria(n);
        for (int i = 0; i < n; i++)
        {
            setNodo(i, g.getNodo(i));
            for (int j = 0; j < n; j++)
            {
                setLado(i, j, g.getLado(i, j));
            }
        }
    }

    // destructor
    ~Grafo()
    {
        borrarGrafo();
        cout << "Destructor usado\n";
    }

    // funciones
    // TODO
    void borrarGrafo()
    {
        if (_nodos)
        {
            delete[] _nodos;
            _nodos = NULL;
        }
        for (int i = 0; i < _numNodos; i++)
        {
            if (_lados[i])
                delete[] _lados[i];
        }
        if (_lados)
        {
            delete[] _lados;
            _lados = NULL;
        }
        setNumNodos(0);
    }

    Grafo operator&=(Grafo &g)
    {
    }

    void setLado(int const i, int const j, G_Lado const &l) { _lados[i][j] = l; }

    void setNodo(int const i, G_Nodo const &n) { _nodos[i] = n; }

    void setNumNodos(int const n) { _numNodos = n; }

    G_Nodo *getNodos() const { return _nodos; }

    G_Lado getLado(int const i, int const j) const { return (_lados[i][j]); }

    G_Nodo getNodo(int const i) const { return (_nodos[i]); }

    int getNumNodos() const { return _numNodos; }

    void printLados() const
    {
        for (int i = 0; i < getNumNodos(); i++)
        {
            for (int j = 0; j < getNumNodos(); j++)
            {
                cout << getLado(i, j) << " ";
            }
            cout << "\n\n";
        }
    }

    void printNodos() const
    {
        for (int i = 0; i < getNumNodos(); i++)
        {
            cout << getNodo(i) << " ";
        }
        cout << "\n\n";
    }
};
} // namespace ed

#endif
