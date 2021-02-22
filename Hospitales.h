#ifndef	Hospitales_h
#define Hospitales_h
#include "Listas.h"
#include "PersonalSalud.h"
#include <cstdlib>
#include <iostream>
using namespace std;
//Estructura para crear un Hospital con sus respectivos datos
struct Hospital{
	
	string Nombre; //Nombre del hospital
	string Gerente; //Gerente del hospital
	string Localidad; //Localidad del hospital
	int calle_inicial; //calle_inicial del hospital
	int calle_final; //calle_final del hospital
	int carrera_inicial; //carrera_inicial del hospital
	int carrera_final; //carrera_final del hospital
	int Numero_Medicos; //Numero de medicos del hospital
	int Numero_Enfermeros; //Numero de Enfemeros del hospital
	Lista<Personal> Personal_Hospital; //Lista de personal del hospital
};

class Hospitales{

	public:
		Hospitales(){
			
		};
		
		void LlenarHospitales();



};


#endif /*Hospitales_h */ 

