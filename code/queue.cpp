#include <iostream>
#include <cstdlib>
#include<fstream>
#include <ctime> 
using namespace std;

// este bloque declara nuestra clase Queue
class Queue {
private:
	struct nodeQueue {
		int val;
		nodeQueue* next;
	};
	typedef struct nodeQueue nodoQ;

	nodoQ *Q;	// puntero AL FRENTE de la cola, por donde se eliminan los elementos (dequeue)

public:
    Queue();
    Queue(int num);
    ~Queue();

    void enqueue(int);
    int dequeue();
    int front();
    int last();
    int size();
    bool isEmpty();
    void display();
};

// constructor de la clase.. crea la cola vacia
Queue::Queue(){
	cout << "creando Cola vacia..." << endl;
	Q = NULL;
}

// constructor de la clase.. crea la cola con un elemento
Queue::Queue(int num){
    Q = new nodoQ;
    Q->val = num;
    Q->next = NULL;
}

// destructor de la clase, libera la memoria de todos los nodoQ
Queue::~Queue() {
	nodoQ *p;

	while(Q != nullptr){
 		p = Q;
 		Q = Q->next;
		delete p;
	}
}

// inserta un elemento al final(back) de la cola en tiempo O(n): la recorre desde el front al rear y lo pone al final
void Queue::enqueue(int elem) {
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
}

// Elimina el elemento que esta al frente de la cola y retorna su valo, en tiempo O(1)
int Queue::dequeue(){
	if (Q == nullptr){
		cout << "Queue Vacía !" << endl;
		return -1;
	}
	nodoQ *p = Q;
   int num = p->val; 
	Q = Q->next;
	delete p;

   return num;
}

// retorna el elemento que esta al frente de la cola, corre en O(1)
int Queue::front(){
	if (Q == nullptr){
		cout << "Queue Vacío !" << endl;
		return -1;
	}

	return Q->val;
}

// retorna el elemento que esta al final de la cola (el último que se inserto), corre en O(n)
int Queue::last(){
	if (Q == nullptr){
		cout << "Queue Vacío !" << endl;
		return -1;
	}

	nodoQ *p = Q;
	while(p->next != nullptr)
		p = p->next;

	return p->val;
}

// retorna la cantidad de elementos que hay en la cola, en O(n) time
int Queue::size(){
	if (Q == nullptr)	
		return 0;
	int cant=0;
	nodoQ *p = Q;
	while(p != nullptr){
		cant++;
		p = p->next;
	}
	return cant;
}

// lista la cola
void Queue::display(){
	if (Q == nullptr){
		cout << "Queue Vacía !" << endl;
		return;
	}
	nodoQ *p = Q;
	cout << "Queue: " << endl;
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}
void agregaDatos(string *A, string txt);
int main(int argc, char **argv){
	unsigned t0, t1;
 	t0=clock();
 	int rep = 0;
 	string* words= new string[370099];
 	agregaDatos(words,"words_alpha.txt");		
 	
  	
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
				cout <<"palabra: "<<A[i]<<" añadida correctamente a la lista"<<endl;
			}
		}	
	
}