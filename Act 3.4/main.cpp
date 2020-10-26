/*
Nombres y matriculas
    Esthela Sofía Cedillo Moreno A00828420
    Rodrigo Pelayo Ochoa A00827285
    Juan Carlos Triana Vela A00827629

Equipo 17
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#include "BST.h"

//Nombre: ipToLong 
//Descipción: convierte una entrada de IP en un valor tipo long long
//Entrada: un valor string de IP formato xx.xxx.xxx.xxx
//Salida: una valor long long resultado de convertir la ip
//Complejidad: O(n)
long long ipToLong(string ip){
	int idx = 0;
	long long datoFinal= 0, dato = 0;
	while (idx < ip.size()){
		if (ip[idx]!= '.'){
			dato = dato*10 + ip[idx]-'0';
		}
		else{
			datoFinal = datoFinal*1000 + dato;
			dato = 0;
		}
		idx++;
	}
	datoFinal = datoFinal*10000 + dato;
	return datoFinal;
}

int main(){
    BST BitacoraBST;
    //Variable de almacenaje de busqueda
    Bitacora almacena;
    
    //Variables de lectura 
    ifstream archivo("bitacoraOrdenada.txt");
    string line;
    string valor;
    int iRegistro=0, contadorAcc = 1;
    char delim=' '; //El delimitador de las variables es el espacio

    //Lectura del archivo
    while(getline(archivo, line)){
      if (iRegistro == 0){
        stringstream ss(line);
        getline(ss,valor,delim); //Saltamo Mes
        getline(ss,valor,delim); //Saltamos Dia
        getline(ss,valor,delim); //Saltamos Hora
        getline(ss,valor,':');//Se usa el IP sin el puerto, antes de ':'
        almacena.IP = valor;
      }
        //Para hacer otro caso que no sea el primero para no errar en el contador
      else{
        stringstream ss(line);
        getline(ss,valor,delim); //Saltamo Mes
        getline(ss,valor,delim); //Saltamos Dia
        getline(ss,valor,delim); //Saltamos Hora
        getline(ss,valor,':'); //Se usa el IP sin el puerto, antes de ':'
          //Cuando la IP sea de igual valor el contador aumentará para posteriormente contar cuantas veces hubo acceso a la IP
        if (almacena.IP == valor){
          contadorAcc++;
        }
        else{
          almacena.accesos = contadorAcc; //Antes de resetear el contador para pasarlo a otro acceso se reseta 
          almacena.IpKey = ipToLong(valor);
          BitacoraBST.add(almacena);
          almacena.IP = valor;
          contadorAcc = 1; 
          }
        }
      iRegistro++;
    }
    //Almacenar los últimos registros de el archivo
    almacena.accesos = contadorAcc;
    almacena.IpKey = ipToLong(valor);
    BitacoraBST.add(almacena);
    archivo.close();

    cout<<"Los 5 IP más accesados fueron: "<<endl;
    BitacoraBST.printAcc();
  
  return 0;
}



