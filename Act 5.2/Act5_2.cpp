/*
Nombres y matri­culas:
    Esthela SofÃ­a Cedillo Moreno A00828420
    Rodrigo Pelayo Ochoa A00827285
    Juan Carlos Triana Vela A00827629

Equipo 17
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <vector>

using namespace std;

//Estructura que servirá para cuardar los registos de la bitacora
struct registro{
  string IP;
  vector<string> fecha;
  vector<string> concepto;
  int accesos = 0;
};

//Nombre: buscar
//Descripción: despliega el resumen de una IP dada 
//Entrada: un unordered_map válido cuyas key sean la IP
//Salida: ninguna
void buscar(unordered_map<string,registro> bitacora){
  char opcion = 'S';
  string IPEntrada;

  //Ejecuta el loop hasta que ya no se quieran seguir buscando datos
  while (opcion == 'S' || opcion == 's'){
    //Se introduce el IP a buscar
    cout << "Introduzca una IP a buscar: " ;
    cin >> IPEntrada;

    // Despliega los datos
    cout << "IP: " << bitacora[IPEntrada].IP << endl;
    cout  << "Número de accesos: "<< bitacora[IPEntrada].accesos << endl;
    cout << "Resumen: " << endl;
    
    //Despliega el resumen (fecha y error)
    for (int i=0; i<bitacora[IPEntrada].fecha.size(); i++){
      cout << " " << bitacora[IPEntrada].fecha[i];
      cout << " " << bitacora[IPEntrada].concepto[i] << endl; 
    }
    cout << "\n¿Desea buscar un nuevo IP?: S(sí) o N(no) "; 
    cin >> opcion ;
  }
}


int main(){
  //Declarar el unordered_map
  unordered_map<string, registro> bitacora;
  
  //Se declara el archivo
  ifstream archivo("bitacoraACT5_2.txt");
  //String de linea
  string line;
  string valor, dia, mes, concepto, fecha, IP;
  /*Se declara el número de líneas, arcos, nodos y
  el registro*/
  int accesos;
  char delim = ' ';
  registro Actualregist;
  
  while(getline(archivo, line)){
        stringstream ss(line);
        //Mes
        getline(ss,valor,delim);
        mes = valor;
        //Día
        getline(ss,valor,delim);
        dia = valor;
        fecha = mes + " " + dia;
        //Hora
        getline(ss,valor,delim);
        //IP
        getline(ss,valor,':');
        IP = valor;
        getline(ss,valor,delim);

        //concepto
        getline(ss,valor);
        concepto = valor;

        //Guarda los valores de la IP
        bitacora[IP].IP = IP;
        bitacora[IP].fecha.push_back(fecha);
        bitacora[IP].concepto.push_back(concepto);
        bitacora[IP].accesos++;
  }
  //Cierra el archivo
  archivo.close();

  buscar(bitacora);

  cout << "Fin" << endl;

  return 0;
}