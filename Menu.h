#ifndef	Menu_h
#define Menu_h
#include "Consultas.h"
#include "Controlador.h"
#include "Simulacion.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
using namespace std;
class Menu{
	    Controlador controlar;
	    
	public:
		Menu(){
			 
		};
		void MenuPrincipal();
};
void Menu::MenuPrincipal(){
	int op;
		system("cls");
		cout << "\t-----------MENU PRINCIPAL-----------" << endl << endl;
		cout << "\1. Consultar hospitales y centros medicos segun Calles y Carreras." << endl;
		
		controlar.RecuperarPacientes();
        controlar.Hospital_Personal();
    //	Consultas consultar(controlar);
   	//	consultar.HospitalesCalleCarreras(22,28,15,17);
   	//	consultar.HospitalesCalleCarreras(100,100,100,100);
   		//controlar.AdicionarHospital("hcd","jsa","sady",32,23,15,13,21,20);
   	/*	controlar.AdicionarPersonal("Hospital San Ignacio","Medico","Piso","Leon","Parada","CC",5467348,"M",31213213,4745854
		   ,15,2,1999,"leon@gmail.com","Bogota","Colombia","Carrera 24c #25-34 sur","Candelaria",14,22,0);
		controlar.AdicionarPersonal("Hospital Fontibon","UCI","Piso","Gabriela","Vanegas","CC",32673427,"F",5487548,78349340
		   ,11,5,2001,"Gabriela@gmail.com","Medellin","Colombia","Calle 20 #25-43 ","Engativa",6,14,0);*/
   	//	controlar.AdicionarPaciente("Guillermo","Velez",1234,"M",21,10,2001,"Ninguna","Olaya","Asintomatico","Leve","acetaminofen",10,"Hospital Fontibon");
   	//	controlar.AdicionarPaciente("Juan","Bautista",12345,"M",21,10,2001,"Ninguna","Olaya","Asintomatico","Moderado","acetaminofen",9,"Hospital San Blas");
	//	controlar.AdicionarPaciente("Daniel","Vargas",467342,"M",15,11,2004,"Ninguna","Restrepo","Asintomatico","Moderado","acetaminofen",8, "Hospital San Blas");
	//	controlar.AdicionarPaciente("Sofia","Munoz",432112,"F",15,11,1999,"Dermatitis","Restrepo","Asintomatico","Leve","Gengibre",7, "Hospital San Blas");
	//	controlar.AdicionarPaciente("Daniel","Segura",578481,"M",15,11,2001,"Dermatitis","Quiroga","Asintomatico","Leve","Gengibre",9, "Hospital San Blas");
	//	controlar.AdicionarPaciente("Luisa","Espitia",621721,"F",12,12,1998,"Ninguna","Suba","Asintomatico","Leve","Gengibre",8, "Hospital Fontibon");
   	//	controlar.ConsultarPacientes();
   	//	controlar.ConsultarPersonalSalud();
   	
   		Simulacion simular(controlar);
   		simular.MostrarHospitales();
   		
   		
}
#endif /*Menu */ 
