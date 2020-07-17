#include <iostream>
#include <cstdlib>
#include<fstream>
#include <ctime> 
#include <string>
using namespace std;

// este bloque declara nuestra clase Simple Queue
class simpleQueue {
private:
	struct nodeQueue {
		string val;
		nodeQueue* next;
	};
	typedef struct nodeQueue nodoQ;

	nodoQ *Q;	// puntero AL FRENTE de la cola, por donde se eliminan los elementos (dequeue)

public:
    simpleQueue();
    simpleQueue(string num);
    ~simpleQueue();

    void enqueue(string);
    string dequeue();
    string front();
    string last();
    int size();
    bool isEmpty();
    void display();
};
// constructor de la clase.. crea la cola vacia
simpleQueue::simpleQueue(){
	cout << "creando Cola simple vacia..." << endl;
	Q = NULL;
}

// constructor de la clase.. crea la cola con un elemento
simpleQueue::simpleQueue(string palab){
    Q = new nodoQ;
    Q->val = palab;
    Q->next = NULL;
}

// destructor de la clase, libera la memoria de todos los nodoQ
simpleQueue::~simpleQueue() {
	nodoQ *p;

	while(Q != nullptr){
 		p = Q;
 		Q = Q->next;
		delete p;
	}
}

// inserta un elemento al final(back) de la cola en tiempo O(n): la recorre desde el front al rear y lo pone al final
void simpleQueue::enqueue(string elem) {
	nodoQ *p = new nodoQ;
	p->val = elem;
	p->next = NULL;

	if (Q == nullptr)
		Q = p;
	else{
		nodoQ *q = Q;
		while (q->next != nullptr)
			q = q->next;
		q->next = p;
	}
	//cout << "Valor agregado correctamente a la cola!" << endl;
}

// Elimina el elemento que esta al frente de la cola y retorna su valo, en tiempo O(1)
string simpleQueue::dequeue(){
	if (Q == nullptr){
		cout << "Queue Vacía !" << endl;
		return "-1";
	}
	nodoQ *p = Q;
    string num = p->val; 
	Q = Q->next;
	delete p;
	//cout << "Valor eliminado correctamente de la cola" << endl;
    return num;
}

// retorna el elemento que esta al frente de la cola, corre en O(1)
string simpleQueue::front(){
	if (Q == nullptr){
		cout << "Queue Vacío !" << endl;
		return "-1";
	}
	//cout << "la cabeza del queue es: " << Q->val << endl;
	return Q->val;
}

// retorna el elemento que esta al final de la cola (el último que se inserto), corre en O(n)
string simpleQueue::last(){
	if (Q == nullptr){
		cout << "Queue Vacío !" << endl;
		return "-1";
	}

	nodoQ *p = Q;
	while(p->next != nullptr)
		p = p->next;

	return p->val;
}

// retorna la cantidad de elementos que hay en la cola, en O(n) time
int simpleQueue::size(){
	if (Q == nullptr)	
		return 0;
	int cant=0;
	nodoQ *p = Q;
	while(p != nullptr){
		cant++;
		p = p->next;
	}
	//cout << "El largo de la cola es: " << cant << endl;
	return cant;
}

// lista la cola
void simpleQueue::display(){
	if (Q == nullptr){
		cout << "Queue Vacía !" << endl;
		return;
	}
	nodoQ *p = Q;
	/*cout << "el queue completo es: ";
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl*/;
}




//agrega todas las lineas del .txt en un arreglo donde cada línea es un elemento
void agregaDatos(string *A, string txt);


int main(int argc, char **argv){
	simpleQueue q1;
	if (argc != 2){
		cout << "Error! Debe ejecutarse como ./colasimple n" << endl;
		exit (EXIT_FAILURE);
	}
	int n = atoi(argv[1]);
	unsigned t0, t1;
 	t0=clock();
 	int rep = 0;
 	string* words= new string[370099];
 	agregaDatos(words,"words_alpha.txt");	
 	srand(time(NULL));
	 cout<<"Ejecutando Simple Queue " << endl;
 	int x = rand()%370099;
 	q1.enqueue(words[x]); //agrega a la cola una palabra al azar
 	q1.display();
 	int k = q1.size();
 	//int hola = 2;
 	//int aux = 0;
 	while(k<n){
 		for (int i = 0; i<2*k; i++){ //agrega 2k elementos a la cola
 			int x = rand()%37099;
 			q1.enqueue(words[x]);
 		}
 		k = q1.size();
 		for (int i = 0; i<int(k/2); i++){
 			q1.dequeue();
 		}
 		k = q1.size();
 		//aux++;
 	}
 	q1.size();
 	q1.display();
 	while(rep < 1000){
 		rep++;
 	}
    t1 = clock();
 	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	cout << "Execution Time: " << time << endl;
	return EXIT_SUCCESS;
}


void agregaDatos(string *A,string txt){
	ifstream file(txt);
	if(file.is_open() ){
			for(int i = 0;i<370099;i++){
				file>>A[i];
			}
		}
	cout << "Todas las palabras han sido exitosamente guardadas en la lista!" << endl;	
}