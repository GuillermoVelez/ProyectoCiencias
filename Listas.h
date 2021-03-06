#ifndef Listas_h
#define Listas_h
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
struct Nodo
{ Nodo <T> *sig;
  T info; // Info de la lista
};

template <class T>
class Lista{ Nodo <T> *cab; 
	 int tam;
	 T valor_Nulo;
	 public: Lista(){ 
	 	cab= NULL;
	 	tam=0;
	 	
 }
	 void imprimir();
	 bool lista_vacia();
	 int tamano_lista();
	 T obtenerDato(int pos);
	 bool eliminar(int pos);
	 void insertar_final(T infoNueva);
	 void insertar_pos(T infoNueva, int pos);
	 void insertar_inicio(T infoNueva);
	 bool cambiar(int pos ,T infoNueva);
	  };
 
 
 template <class T>
 void Lista<T>::imprimir(){
 	if(lista_vacia()){
 		cout<<"La lista no tiene Informacion"<<endl;
 	}
 	else{
 		cout<<"La informacion de la Lista es:"<<endl;
 		Nodo <T> *aux;
 		aux=cab;
 		int pos= 1;
 		while(aux!= NULL){
 			cout<<"Infor"<<pos<<":"<<aux->info<<endl;
 			aux= aux->sig;
 			pos++;
		 }
	 }
};

template <class T>
void Lista<T>::insertar_pos(T infoNueva, int pos){
	if(pos>tam)	
	insertar_final(infoNueva);
	else {
		if(pos==1)
		insertar_inicio(infoNueva);
		else{
			Nodo <T> *nuevo, *aux;
			nuevo = new Nodo <T>;
			nuevo->info = infoNueva;
			aux = cab;
			int p = 1;
			while (p<pos-1 && aux!=NULL)
			{aux = aux->sig;
			p++;
			}
			nuevo->sig=aux->sig;
			aux->sig=nuevo;
			tam++;
		}
	}
};

template <class T>
void Lista<T>::insertar_final(T infonueva){
	Nodo <T> *nuevo;
	nuevo = new Nodo <T>;
	nuevo->info = infonueva;
	nuevo->sig = NULL;
	if(tam == 0){
		cab= nuevo;
	}
	else{
		Nodo<T>*aux;
		aux = cab;
		while(aux->sig != NULL){
			aux= aux->sig;
		}
		aux->sig = nuevo;
	}
	tam ++;
};

template <class T>
void Lista <T>::insertar_inicio(T infoNueva){
	Nodo<T> *nuevo;
	nuevo = new Nodo <T>;
	nuevo->info=infoNueva;
	nuevo->sig = cab;
	cab = nuevo;
	tam++;
}

template <class T>
T Lista<T>::obtenerDato(int pos){
	Nodo <T> *aux;
	aux=cab;
	int p=1;
	while(p<pos && aux != NULL){
		aux = aux->sig;
		p++;
	}
	return aux->info;
};

template <class T>
bool Lista<T>::eliminar(int pos){
	if(tam>= pos){
		Nodo<T> *temp;
		temp = cab;
		if(pos == 1){
			cab = temp->sig;
			delete temp;
		}
		else{
			for(int i=1;i<pos-1;i++){
				temp= temp->sig;
			}
			Nodo <T> *aux;
			aux = temp->sig;
			temp->sig = aux->sig;
			delete aux;
		}
		tam--;
		return true;
	}
	else 
	return false;
};

template<class T>
bool Lista<T>::lista_vacia(){
	if(tam == 0)
		return true;
	
	else
	return false;
};

template<class T>
int Lista<T>::tamano_lista(){
	return tam;
}

template <class T>
bool Lista<T>::cambiar(int pos, T infoNueva)
{ Nodo <T> *aux=cab;
  int p = 1;
  if (pos<=tam)
   { while(p<pos && aux != NULL)
   		{aux = aux->sig;
         p++;
    	}
     aux->info = infoNueva; 
     return true;
	}
  return false;	
}	
#endif /* Listas_h */ 
