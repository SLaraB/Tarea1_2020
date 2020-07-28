#include <iostream>
#include <cstdlib>
#include<fstream>
#include <ctime> 
#include <string>
using namespace std;

#define MIN 1
#define MAX 3

void agregaDatos(string *A, string txt);	//agrega todas las lineas del .txt en un arreglo donde cada línea es un elemento
string *CreaPrimaDoble(string *A, int cap);
string *CreaPrimaElimina(string *A, int cap);
void imprimeLista(string *A, int cap);


int main(int argc, char **argv){
	int cap, n;
	unsigned t0, t1;
	if (argc != 2){
		cout << "Error! Debe ejecutarse como ./array n" << endl;
		exit (EXIT_FAILURE);
	}
	n = atoi(argv[1]);

	//crea un strig de tamaño [t]
 	string* words= new string[370099];
 	agregaDatos(words,"words_alpha.txt");	//función que agrega cada palabra de un txt a una celda de mi arreglo

 	//Inicio proceso ArrayQueue
 	t0=clock();	
 	int x = rand()%370099;
 	while((words[x].length() < MIN) | (words[x].length() > MAX))
        x = rand()%370099;
 	cap = 1;
 	string* A = new string[cap];	//Arreglo de tipo string de tamaño cap
 	A[0] = words[x];
	//cout << "A[0]  con 1 elemento antes del while: " << A[0] << endl;
	//cout << "cap: " << cap << endl;
	//cout << "cap*2: " << cap*2 << endl<<endl;
	while(cap<n){

		string *Aprim = CreaPrimaDoble(A, cap); // CREA LISTA  Aprim
		A=Aprim;
		cap=(cap*2)+cap;
		//cout<<"Nuevo cap (largo de la lista)= "<<cap<<endl;
		for (int i=(cap/2)-1;i<cap;i++){ // AGREGA A LA LISTA LAS PALABRAS
			if(A[i]== "nada"){  //SI A[i] es distinto de "nada" agrega una palabra aleatoria (ver funcion CreaPrimaDoble)
				x=rand()%370099;
				while((words[x].length() < MIN) | (words[x].length() > MAX))
	                x = rand()%370099;
				A[i]=words[x];
			}
		}
		/*
		//cout<<"Lista nueva con "<<cap<<" elementos: "<<endl;
		imprimeLista(A,cap);
		cout<<"cantidad de elementos a eliminar: "<<cap/2<<endl;
		cout<<"Elemento(s) en la lista para borrar: ";
		for(int i=0;i<cap/2;i++){
			cout<<A[i]<<" ";
		}
		cout<<endl;  //ESTE FOR MUESTRA EL/LOS ELEMENTOS A BORRAR DE EL ARRAY
		*/
		string *AprimElimina = CreaPrimaElimina(A, cap); //CREA LA LISTA ELIMINANDO CAP/2 ELEMENTOS
		A=AprimElimina;
		cap=cap-(cap/2);
		/*
		//cout<<"Nueva lista con "<<cap<<" elementos: "<<endl;
		imprimeLista(A,cap); //IMPRIME LA LISTA CON LA NUEVA LISTA
		cout<<endl; */
	}
 	
    t1 = clock();	//Fin proceso ArrayQueue
 	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution Time: " << time << endl;
	return EXIT_SUCCESS;
}


void agregaDatos(string *text,string txt){
	ifstream file(txt);
	cout << "Creando arreglo con todas las palabras de 'words_alpha'" << endl;
	if(file.is_open() ){
			for(int i = 0;i<370099;i++){
				file>>text[i];
			}
		}		
	cout << "Todas las palabras han sido exitosamente guardadas en el arreglo!" << endl;	
}

//funcion que crea un arreglo Aprim con los elementos de A mas otros por crear
string *CreaPrimaDoble(string *A, int cap){
	int aux=(cap*2)+cap;//Auxiliar para el nuevo valor de cap
	string* Aprim = new string[aux];//de A, pero con el doble de largo
	for (int i=0; i<cap; i++){//en el main se asigna Aprim a A para que se pueda seguir utilizando
		Aprim[i] = A[i];// como A
	}
	for(int i=cap;i<aux;i++){
		Aprim[i]="nada";    //TODOS LOS ELEMENTOS VACIOS LOS RELLENA CON "nada"
	}
	return Aprim;
}

void imprimeLista(string *A,int cap){
	for (int i=0;i<cap;i++){
		cout<<" A["<<i<<"]= "<<A[i]<<"; ";
	}
	cout<<endl;
}
string *CreaPrimaElimina(string *A,int cap){  //cap=3
	int aux=cap-(cap/2); //Auxiliar para el nuevo largo de la lista
	int indice=0; //indice auxiliar
	string *Aprim = new string[aux];
	for (int i=cap/2;i<cap;i++){
		Aprim[indice]=A[i];
		indice++;
	}
	return Aprim;
}