#ifndef	PersonalSalud_h
#define PersonalSalud_h
#include <iostream>
#include <cstdlib>
#include "Pacientes.h"
using namespace std;
//Estructura utilizada Para crear el personal con sus respectivos datos
struct Personal{
	string Hospital; //Nombre del hospital al que pertenece
	string Tipo; //Indica si es medico o enfermero
	string Seccion; //Indica la seccion en el hospital al que pertenece
	string Nombre; //Indica el nombre del Personal
	string Apellido; //Indica el Apellido del Personal
	string TipoIdentificacion; //Indica el Tipo de id del Personal
	long int NumeroIdentificacion; //Indica el id del Personal
	string Sexo; //Indica el sexo del Personal
	int TelefonoCel; //Indica el telefono celular del Personal
	int Telefonofij; //Indica el telefono fijo del Personal
	int dia; //Indica el dia de nacimiento del Personal
	int mes; //Indica el mes de nacimiento del Personal
	int anio; //Indica el año de nai del Personal
	string Correo; //Indica el Correo del Personal
	string Ciudad; //Indica la ciudad del Personal
	string Pais; //Indica el pais del Personal
	string Direccion; //Indica la direccion del Personal
	string Barrio; //Indica el nombre del Personal
	int hora_inicial; //Indica la hora de inicio del turno del Personal
	int hora_final; //Indica la hora final del turno del Personal
	int num_pacientes; //Indica el numero de pacientes del Personal
	Lista <Paciente> pacientesPS; //Lista con el numero de pacientes del personal
	
	
};
//Clase de personal de la salud
class PersonalSalud{
	int num_pacientes;
	public:
		PersonalSalud(){
		};
	void llenar();
	bool calcularEdad( int anioAct , int mesAct, int fechAct, int anioNac, int mesNac, int fechNac);
	//Metodo utilizado para verificar que un personal ingresado sea mayor de edad o no
	
};
void PersonalSalud::llenar(){
	
}
bool PersonalSalud::calcularEdad( int anioAct , int mesAct, int fechAct, int anioNac, int mesNac, int fechNac)
{
    int respFech , respMes;

    if ( fechAct < fechNac  )
    {   
        fechAct = fechAct + 30; 
        mesAct = mesAct - 1; 
        respFech =  fechAct - fechNac; 
    }
    else 
        respFech =  fechAct - fechNac;  

    if( mesAct < mesNac )
    {   
        mesAct = mesAct + 12; 
        anioAct = anioAct - 1 ;
        respMes = mesAct - mesNac; 
    }
    else 
        respMes = mesAct - mesNac; 
 
    if(anioAct - anioNac>=18)
    	return true;
	else
		return false;
	
}
#endif /*PersonalSalud */ 
