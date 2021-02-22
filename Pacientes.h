#ifndef	Pacientes_h
#define Pacientes_h
#include <iostream>
#include <cstdlib>
#include "Listas.h"
//Estructura para asignar fechas de la cita a los pacientes
struct FechaCita{
	int diaCita; //Dia de la cita
	int MesCita; //Mes de la cita
	int AnioCita; //Año de la cita
};
//Estructura para Crear un paciente con sus respectivos datos 
struct Paciente{
	string Nombre; //Nombre del paciente
	string Apellido; //Apellido del paciente
	long int NumeroIdentificacion; //Id del paciente
	string sexo; //Sexo del paciente
	int dia; //Dia de nacimiento del paciente
	int mes; //Mes de nacimiento del paciente
	int anio; //Año de nacimiento del paciente
	string Enfermedades; //Enfermedades del paciente
	string Localidad; //Localidad del paciente
	string Estado; //Estado del paciente
	string NivelGravedad; //NivelGravedad del paciente
	string Medicamentos; //Medicamentos del paciente
	Lista <FechaCita> FechasPacientes; //Lista con las fehcas de las citas del paciente
	Lista <long int> idPersonal; //Lista con los id del personal asigando del paciente
	
	
};
class Pacientes{
	public:
		Pacientes(){
			
		}
};
#endif /*Pacientes */ 
