#include <iostream>
#include <cstdlib> //para usar srand()

#include "arbolbinarioordenadoenlazado.hpp"
#include "operadornodo.hpp"
#include "persona.hpp"
#include "generarpersona.hpp"

#include "macros.hpp"

using std::cout;
using std::cin;

using namespace ed;


int main()
{
  
  srand(time(0));
  
  ArbolBinarioOrdenadoEnlazado<Persona> a;
  EscribirNodo<Persona> op;

  int i, n, opt = -1;

  //Generar e insertar personas
  cout << BIGREEN << "Bienvenido al test del Arbol Binario Ordenado Enlazado";
  cout << RESET <<'\n';
  cout << IBLUE <<"Introduce el número de personas a insertar:\t" << RESET;
  cin >> n;

  for(i = 0; i < n; i++){
    a.insertar(generarDatosPersonales());
  }
  
  while(opt != 0){
    cout << BIRED << "Elige opción\n" << RESET;
    cout << BICYAN << "1. Insertar más personas\n";
    cout << "2. Buscar una persona\n3. Mostrar contenido\n";
    cout << "4. Borrar una persona\n5. Borrar el árbol\n";
    cout << "0. Salir\n" << RESET;
    cin >> opt;
    switch (opt)
    {
      case 1:{
        cout << IBLUE <<"Introduce el número de personas a insertar:\t" << RESET;
        cin >> n;
        for(i = 0; i < n; i++){
          a.insertar(generarDatosPersonales());
        }
      }break;
      case 2:{
        if(! a.estaVacio()){
          int aux;
          Persona p;
          cout << IBLUE << "Introduce el DNI que buscas:\t" << RESET;
          cin >> aux;
          p.dni(aux);
          if(a.buscar(p)) 
            cout << GREEN << a.actual() << '\n' << RESET;
          else 
            cout << IRED << "La persona buscada no está en el árbol\n" << RESET;      
        }
        else{
          cout << IRED << "No se puede buscar en un árbol vacío\n" << RESET;
        }   
      }break;
      case 3:{
        if(a.estaVacio()){
          cout << IRED << "No se puede mostrar un árbol vacío\n" << RESET;
        }
        else{
          int opt2 = -1;
          while((opt2 != 0) && (opt2 != 1) && (opt2 != 2)){
            cout << BIRED << "Elige opción\n" << RESET;
            cout << BICYAN << "1. Pre-Orden\n2. Post-Orden\n";
            cout << "3. In-Orden\n" << RESET;
            cin >> opt2;
          }
          switch (opt2)
          {
            case 1:
              a.recorridoPreOrden(op);
              break;
            case 2:
              a.recorridoPostOrden(op);
              break;
            case 3:
              a.recorridoInOrden(op);
              break;
            default:
              break;
          }
        }
      }break;
      case 4:{
        if(! a.estaVacio()){
          Persona p;
          cout << IBLUE << "Introduce los datos que buscas:\n" << RESET;
          cin >> p;
          if(a.buscar(p)){
            if(a.borrar())
              cout << GREEN << "BORRADO CORRECTO\n";
            else 
              cout << IRED << "FALLO AL BORRAR\n";
            cout << RESET;
          }
          else{
            cout << IRED << "La persona buscada no está en el árbol\n" << RESET;    
          }
        }
        else{
          cout << IRED << "No se puede borrar de un árbol vacío\n" << RESET;
        }
      }break;
      case 5:{
        a.borrarArbol();
      }break;
      case 0:{
        cout << BIBLUE << "Saliendo...\n" << RESET;
      }break;
    
      default:
        cout << RED << "Opción no válida\n" << RESET;

        break;
    }
    if (opt != 0){
      cout << "Pulse [ENTER] para continuar\n";
      cin.ignore();
      cin.get();
      system("clear");
    }
  }
}
