#include "grafo.hpp"
#include<iostream>
using std::cout;
using ed::Grafo;
int main(){

	Grafo<int, int> g(5);
	Grafo<int, int> h(g);
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			cout << g._lados[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
	g.borrarGrafo();
}
