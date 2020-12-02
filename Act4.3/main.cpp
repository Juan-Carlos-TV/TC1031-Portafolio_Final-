/*
Nombres y matri­culas:
    Esthela SofÃ­a Cedillo Moreno A00828420
    Rodrigo Pelayo Ochoa A00827285
    Juan Carlos Triana Vela A00827629

Equipo 17
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
  //Declarar el mapa de desordenado que almacena los nodos
  unordered_map<string, pair<int, int>> IPNodos;
  
  //Declaramos el archivo
  ifstream archivo("bitacoraACT4_3_B.txt");
  //String de linea
  string line;
  string valor;
  //Declarar número de lineas, nodos, arcos, y 
    //la variable que almacena el mayor número de ataques
  int iLinea = 0, n, m, mayorAccesos = 0;
  //Declaramos el delimitador
  char delim = ' ';

  //Tomamos la primera linea
  getline(archivo, line);
  //String stream de la primera linea
  stringstream linea1(line);

  //Obtenemos el número de nodos
  getline(linea1, valor, delim);
  n = stoi(valor);
  //Obtenemos el número de arcos
  getline(linea1, valor);
  m = stoi(valor);

  //Declaramos la lista de adyacencia de los nodos
  vector<vector<int>> listAdj(n);

  //Mientras no termine el archivo
  while (getline(archivo,line)){
    //Stringstream de la linea
    stringstream ss(line);

    //Si todavía no se han leído todos los nodos
    if (iLinea < n){
        //Obtenemos el valor de la linea
        getline(ss, valor);
        //Declaramos el pair auxiliar
        pair<int,int> entrada;
        //Almacenamos la key de ese elemnto
        entrada.first = iLinea;
        //Inicializamos el outdegree en 0
        entrada.second = 0;
        IPNodos[valor] = entrada;
        //Aumentamos el número de linea (key)
        iLinea++;
    }
    //En cualquier otro caso
    else{
        //Salta el mes
        getline(ss,valor,delim);
        //Salta el día
        getline(ss,valor,delim);
        //Salta la hora
        getline(ss,valor,delim);

        //Obtiene el origen ignorando el puerto
        getline(ss,valor,':');
        //Guardamos la key de la IP de origen
        int origen = IPNodos[valor].first;
        //Aumentamos el outdegree
        IPNodos[valor].second++;

        //Si el outdegree actual es mayor al anterior mayor obtenido
        if ( IPNodos[valor].second > mayorAccesos){
          mayorAccesos = IPNodos[valor].second;
        }

        //Obtiene el destino ignorando el puerto
        getline(ss,valor,delim);
        getline(ss,valor,':');
        //Guarda la key de destino
        int destino = IPNodos[valor].first;
        //Almacena el arco en la lista de adyacencia
        listAdj[origen].push_back(destino);
      }
  }

  cout << "Direcciones con mayor fan out: " << endl;
  //Por cada elemento del unordered map
  for (auto itr=IPNodos.begin(); itr != IPNodos.end(); itr++){
    //Si el outdegree del nodo visitado es igual al número mayor de ataques 
      //lo despliega
    if (itr->second.second == mayorAccesos){
      cout << "IP: " << itr->first << " -> Intentos de ataque: "<< itr->second.second<< endl;
    }
  }
  return 0;
}