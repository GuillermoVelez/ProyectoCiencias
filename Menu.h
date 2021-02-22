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
		void MenuConsultas();
};
void Menu::MenuPrincipal(){
	controlar.RecuperarPacientes();
	controlar.Hospital_Personal();	

	int op=0;
	while(op<7){
		system("cls");
		cout << "\t-----------MENU PRINCIPAL-----------" << endl << endl;
		cout << "1). Menu consultas." << endl;
		cout << "2). Insertar nuevo hospital." << endl;
		cout << "3). Insertar nuevo personal." << endl;
		cout << "4). Insertar nuevo paciente." << endl;
		cout << "5). Inicio simulacion." << endl;
		cout << "6). Salir." << endl;
		cin>>op;
		if (op==1){
				MenuConsultas();
		}
		else if(op==2)
		{
				system ("cls");
				string nombre, gerente, localidad;
				int calleinicial;
				int callefinal;
				int carrerainicial;
				int carrerafinal;
				cout<<"\nPor favor ingrese el nombre del nuevo hospital: ";
				cin>>nombre;
				cout<<"\nPor favor ingrese el nombre del gerente que tendra el hospital: ";
				cin>>gerente;
				cout<<"\nPor favor ingrese la localidad en donde se encontrara el nuevo hospital: ";
				cin>>localidad;
				cout<<"\nPor favor ingrese la calle inicial que tendra cobertura por el nuevo hospital: ";
				cin>>calleinicial;
				cout<<"\nPor favor ingrese la calle final que tendra cobertura por el nuevo hospital: ";
				cin>>callefinal;
				cout<<"\nPor favor ingrese la carrera inicial que tendra cobertura por el nuevo hospital: ";
				cin>>carrerainicial;
				cout<<"Por favor ingrese la carrera final que tendra cobertura por el nuevo hospital: ";
				cin>>carrerafinal;
				controlar.AdicionarHospital(nombre,gerente,localidad,calleinicial,callefinal,carrerainicial,carrerafinal,0,0);
				cout<<"\n\nEl nuevo hospital ha sido añadido correctamente..."<<endl;
				cout<<"\n\nPresione enter para continuar...";
				system("pause");
		}
		else if (op==3)
		{
				system ("cls");
				string hospital;
				string tipo;
				string seccion;
				string nombre;
				string apellido;
				string tipoidentificacion;
				long int numeroID;
				string sexo;
				int celular;
				int fijo;
				int dia;
				int mes;
				int anio;
				string correo;
				string ciudad;
				string pais;
				string direccion;
				string localidad;
				int horainicio;
				int horafin;
				cout<<"\nPor favor digite el nombre del hospital a donde se asignara el nuevo personal: ";
				cin>>hospital;
				cout<<"\nPor favor digite si el nuevo personal sera Medico o Enfermero: ";
				cin>>tipo;
				cout<<"\nPor favor indique la seccion a la cual se dedicara el nuevo personal: ";
				cin>>seccion;
				cout<<"\nPor favor digite el nombre del nuevo personal: ";
				cin>>nombre;
				cout<<"\nPor favor digite el apellido del nuevo personal: ";
				cin>>apellido;
				cout<<"\nPor favor digite el tipo de identificacion del nuevo personal: ";
				cin>>tipoidentificacion;
				cout<<"\nPor favor digite el numero de identificacion del nuevo personal: ";
				cin>>numeroID;
				cout<<"\nPor favor digite el sexo del nuevo personal: ";
				cin>>sexo;
				cout<<"\nPor favor digite el numero celular del nuevo personal:";
				cin>>celular;
				cout<<"\nPor favor digite el numero fijo del nuevo personal: ";
				cin>>fijo;
				cout<<"\nPor favor digite el dia de nacimiento del nuevo personal: ";
				cin>>dia;
				cout<<"\nPor favor digite el mes de nacimiento del nuevo personal: ";
				cin>>mes;
				cout<<"\nPor favor digite el año de nacimiento del nuevo personal: ";
				cin>>anio;
				cout<<"\nPor favor digite el correo electronico del nuevo personal: ";
				cin>>correo;
				cout<<"\nPor favor digite la ciudad de origen del nuevo personal: ";
				cin>>ciudad;
				cout<<"\nPor favor digite el pais de origen del nuevo personal: ";
				cin>>pais;
				cout<<"\nPor favor digite la direccion del nuevo personal: ";
				cin>>direccion;
				cout<<"\nPor favor digite la localidad del nuevo personal: ";
				cin>>localidad;
				cout<<"\nPor favor digite la hora de ingreso del nuevo personal: ";
				cin>>horainicio;
				cout<<"\nPor favor digite la hora de salida del nuevo personal: ";
				cin>>horafin;
				controlar.AdicionarPersonal(hospital,tipo,seccion,nombre,apellido,tipoidentificacion,numeroID,sexo,celular,fijo,dia,mes,anio,correo,ciudad,pais,direccion,localidad,horainicio,horafin,0);
				cout<<"\n\nEl nuevo personal ha sido añadido correctamente..."<<endl;
				cout<<"\n\nPresione enter para continuar...";
				system("pause");
		}
		else if (op==4)
		{
			system ("cls");
				string nombre;
				string apellido;
				long int numeroID;
				string sexo;
				int dia;
				int mes;
				int anio;
				string enfermedades;
				string localidad;
				string estado;
				string nivelgravedad;
				string medicamentos;
				int hora;
				string hospital;
				cout<<"\nPor favor digite el nombre del paciente: ";
				cin>>nombre;
				cout<<"\nPor favor digite el apellido del paciente: ";
				cin>>apellido;
				cout<<"\nPor favor digite el numero de identificacion del paciente: ";
				cin>>numeroID;
				cout<<"\nPor favor digite el sexo del paciente: ";
				cin>>sexo;
				cout<<"\nPor favor digite el dia de nacimiento del paciente: ";
				cin>>dia;
				cout<<"\nPor favor digite el mes de nacimiento del paciente: ";
				cin>>mes;
				cout<<"\nPor favor digite el año de nacimiento del paciente: ";
				cin>>anio;
				cout<<"\nSi el paciente tiene enfermedades pre_Existentes digitelas, de lo contrario escriba Ninguna: ";
				cin>>enfermedades;
				cout<<"\nPor favor digite la localidad de residencia del paciente: ";
				cin>>localidad;
				cout<<"\nPor favor digite el estado del paciente: ";
				cin>>estado;
				cout<<"\nPor favor digite el nivel de gravedad del paciente: ";
				cin>>nivelgravedad;
				cout<<"\nPor favor digite los medicamentos recetados al paciente: ";
				cin>>medicamentos;
				cout<<"\nPor favor digite la hora que el paciente tiene disponible para citas: ";
				cin>>hora;
				cout<<"\nPor favor digite el hospital al que sera remitido el paciente: ";
				cin>>hospital;
				controlar.AdicionarPaciente(nombre,apellido,numeroID,sexo,dia,mes,anio,enfermedades,localidad,estado,nivelgravedad,medicamentos,hora,hospital);
				cout<<"\n\nEl nuevo paciente ha sido añadido correctamente..."<<endl;
				cout<<"\n\nPresione enter para continuar...";
				system("pause");
		}
		else if(op==5)
		{
			Simulacion simular(controlar);

			simular.MostrarHospitales();
			
		}
		else if (op==6)
		{
			controlar.Finalizar();
		}
   	}
   		
}

void Menu::MenuConsultas(){
	int op;
	Consultas consultar(controlar);
	while (op<10){
		system("cls");
		cout << "\t-----------MENU CONSULTAS-----------" << endl << endl;
		cout << "1). Dada un área (definida por calles y carreras) determinar qué hospitales y centros de salud podrían hacerse cargo de pacientes en esa área."<<endl;
		cout << "2). Dado un horario y una localidad, mostrar la lista del personal de la salud que podría estar disponible."<<endl;
		cout << "3). Dado un paciente y un horario, lista de los médicos y enfermeras que podrían hacerse cargo de él (teniendo en cuenta las limitaciones de número de pacientes por cada persona de la salud)."<<endl;
		cout << "4). Dada una localidad, mostrar todos los pacientes que poseen una enfermedad pre-Existente dada."<<endl;
		cout << "5). Dada una persona de la salud, mostrar la lista de pacientes con fecha de cita."<< endl;
		cout << "6). Dado un paciente, mostrar la lista de personas de la salud, con fecha de las citas programadas"<< endl;
		cout << "7). Dada una localidad, mostrar la lista de los pacientes de con una edad dentro de un rasgo específico atendidos en la misma localidad"<<endl;
		cout << "8). Dado un rango de edad, listar todos los pacientes que están en dicho rango haciendo explicita la edad, el estado. El nivel de gravedad, el lugar donde se encuentra y la localidad a la que pertenece. Cabe aclarar que la precisión de la edad estará dada solamente en términos de años y meses."<<endl;
		cout << "9). volver al menu principal"<<endl;	
		cin>>op;
		if (op==1)
		{
			system ("cls");
				cout<<"\nPor favor digite la calle inicial y la calle final "<<endl;
				int calleinicial;
				int callefinal;
				cin>>calleinicial>>callefinal;
				cout<<"\nPor favor digite la carrera inicial y la carrera final "<<endl;
				int carrerainicial;
				int carrerafinal;
				cin>>carrerainicial>>carrerafinal;
				consultar.HospitalesCalleCarreras(calleinicial,callefinal,carrerainicial,carrerafinal);
				system("pause");
		}
		if (op==2)
		{
			system ("cls");
				cout<<"\nPor favor digite el nombre de la localidad: ";
				string localidad;
				cin>>localidad;
				cout<<"\nPor favor digite la hora inicial y la hora final a consultar:"<<endl;
				int horainicial, horafinal;
				cin>>horainicial>>horafinal;
				consultar.PersonalHorarioLocalidad(localidad,horainicial,horafinal);
				system("pause");
		}
		if (op==3)
		{
			system("cls");
				cout<<"\nPor favor digite el nombre y apellido del paciente:"<<endl;
				string nombre, apellido;
				cout<<"\nPor favor digite el horario a consultar: ";
				int horario;
				cin>>horario;
				consultar.PersonalPacienteHorario(nombre,apellido,horario);
				system("pause");
		}
		
		if (op==4)
		{
			system("cls");
				cout<<"\nPor favor digite la localidad a consultar: ";
				string localidad;
				cin>>localidad;
				consultar.LocalidadPacientesEnfermosAntes(localidad);
				system("pause");
		}
		if (op==5)
		{
				system("cls");
				cout<<"\nPor favor digite el nombre y apellido del personal de la salud a consultar;"<<endl;
				string nombre, apellido;
				cin>>nombre,apellido;
				consultar.PersonalMostrarPacientesEnTiempo(nombre,apellido);
				system("pause");
		}
		if (op==6)
		{
				system("cls");
				cout<<"\nPor favor digite el nombre y apellido del paciente a consultar;"<<endl;
				string nombre, apellido;
				cin>>nombre,apellido;
				consultar.PacientePSConRangoDAtencion(nombre,apellido);
				system("pause");
		}
		if (op==7)
		{
			system("cls");
				cout<<"\nPor favor digitar la localidad a consultar: ";
				string localidad;
				cin>>localidad;
				cout<<"\nPor favor digite la edad minima que desea conocer: ";
				int edadminima;
				cin>>edadminima;
				cout<<"\nPor favor digite la edad maxima que desea conocer: ";
				int edadmaxima;
				cin>>edadmaxima;
				consultar.PacientesLocalidadEdad(localidad,edadminima,edadmaxima);
				system("pause");
		}
		if(op==8)
		{
			system("cls");
				cout<<"\nPor favor digite la edad minima que desea conocer: ";
				int edadminima;
				cin>>edadminima;
				cout<<"\nPor favor digite la edad maxima que desea conocer: ";
				int edadmaxima;
				cin>>edadmaxima;
				consultar.PacientesEdad(edadminima,edadmaxima);
				system("pause");
				
		}
		if(op==9)
		{
			MenuPrincipal();
				
		}
				
		}
	}
#endif /*Menu */
