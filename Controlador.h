
#ifndef	Controlador_h
#define Controlador_h
#include "Listas.h"
#include "Hospitales.h"
#include "LeerArchivos.h"
#include "PersonalSalud.h"
#include "Pacientes.h"
#include "EscribirArchivos.h"
#include <iostream>
#include <conio.h>
#include <cstring>
#include <ctime>
using namespace std;
// Clase encargada de Leer y Escribir las listas en los archivos, tambien sera usada para añadir nuevos elementos a la lista
class Controlador{
	private :

		Hospital auxH; //Auxiliar para cecuperar datos de tipo hospital
		Personal auxPS; //Auxiliar para cecuperar datos de tipo Personal
		Paciente auxPa; //Auxiliar para cecuperar datos de tipo Paciente
		FechaCita auxFC; //Auxiliar para cecuperar datos de tipo FechaCita
		LeerArchivos leer; //Objeto  usado para llamar a la clase que modificara los archivos
		EscribirArchivos Escribir; //Objeto  usado para llamar a la clase que leera los archivos
	    Lista <Hospital> Listah; //Lista de hospitales
	    Lista <Personal> ListaPS; //Lista de hospitales
	    Lista <Paciente> ListaPa; //Lista de Pacientes
	public:
		 
		Controlador(){
			ListaPS=leer.LLenarPersonalSalud(ListaPS);
			Listah=leer.LLenarHospitales(Listah);
			ListaPa=leer.LLenarPacientes(ListaPa);
		};
		
	void AdicionarHospital(string ,string ,string ,int , int ,int , int ,int , int);
	//Metodo para adicionar hospitales
	
	void AdicionarPersonal(string,string, string, string, string, string ,long int,string,int ,int,int,int,int,string ,string,string ,string ,string ,int,int,int);
	//Metodo para adicionar Personal
	
	void AdicionarPaciente(string ,string ,long int ,string ,int ,int ,int ,string ,string ,string ,string ,string, int, string );
	//Metodo para adicionar Paciente
	
	void Hospital_Personal();
	//Metodo para asignar el personal a cada hospital
	
	void RecuperarPacientes();
	//Metodo para recuperar a que personal fue asignado cada paciente
	
	Paciente Personal_Paciente(Paciente,int,string);
	//Metodo para asginar personal al paciente
	
	void ConsultarHospitales();
	void ConsultarPersonalSalud();
	void ConsultarPacientes();
	
	Lista <Hospital> getListaHospitales();
	//Metodo para recuperar lista de hospitales
	
	Lista <Personal> getListaPersonal();
	//Metodo para recuperar lista de Personal
	
	Lista <Paciente> getListaPacientes();
	//Metodo para recuperar lista de Pacientes
	
	void setListaHospitales(Lista <Hospital> LHospitales);
	//Metodo para Modificar lista de hospitales
	
	void setListaPersonal(Lista <Personal> LPersonalDeSalud);
	//Metodo para Modificar lista de Personal
	
	void setListaPacientes(Lista <Paciente> LPacientes);
	//Metodo para Modificar lista de Pacientes

	void Finalizar();
	//Metodo para finalizar la ejecucion del programa
	
	
};

void Controlador::ConsultarHospitales(){
	// Con esto se imprimen las listas
/*	for(int j=1;j<=Listah.tamano_lista();j++){
		     	auxH=Listah.obtenerDato(j);
		     	cout<<j<<": ";
		     	cout<<auxH.Nombre<<","<<auxH.Gerente<<","<<auxH.Localidad<<","<<auxH.calle_inicial<<","<<auxH.calle_final<<","<<auxH.carrera_inicial<<","<<auxH.carrera_final<<","<<auxH.Numero_Medicos<<","<<auxH.Numero_Enfermeros<<endl;    
	}	*/
	for(int k=1;k<=Listah.tamano_lista();k++){
		     	auxH=Listah.obtenerDato(k);
		     	
		     	cout<<k<<": ";
		     	cout<<auxH.Nombre<<","<<auxH.Gerente<<","<<auxH.Localidad<<","<<auxH.calle_inicial<<","<<auxH.calle_final<<","<<auxH.carrera_inicial<<","<<auxH.carrera_final<<","<<auxH.Numero_Medicos<<","<<auxH.Numero_Enfermeros<<endl;    
		     	for(int j=1;j<=auxH.Personal_Hospital.tamano_lista();j++){
			     	auxPS=auxH.Personal_Hospital.obtenerDato(j);
			     	cout<<j<<": ";
			     	cout<<auxPS.Nombre<<endl;  
					for(int i=1;i<=auxPS.pacientesPS.tamano_lista();i++){  
						auxPa=auxPS.pacientesPS.obtenerDato(j);
				     	cout<<"Paciente  "<<i<<": ";
				     	cout<<auxPa.Nombre<<","<<auxPa.NumeroIdentificacion<<endl; 
					}
				}			
				
	}
//	consulta.HospitalesCalleCarreras(Listah,22,28,15,17);
//	consulta.HospitalesCalleCarreras(Listah,100,100,100,100);

	//LLenarPS.calcularEdad(2020,1,25,2000,11,4);
}
void Controlador::ConsultarPersonalSalud(){
	for(int j=1;j<=ListaPS.tamano_lista();j++){
		     	auxPS=ListaPS.obtenerDato(j);
		     	cout<<j<<": ";
		     	cout<<auxPS.Nombre<<","<<auxPS.Tipo<<","<<auxPS.Hospital<<","<<auxPS.Direccion<<","<<auxPS.num_pacientes<<endl;    
		     	for(int i=1;i<=auxPS.pacientesPS.tamano_lista();i++){
		     		auxPa=auxPS.pacientesPS.obtenerDato(i);
		     		cout<<"Paciente "<<i<<": "<<auxPa.Nombre<<endl;
				 }
	}	
	cout<<endl;
}

void Controlador::ConsultarPacientes(){

	for(int j=1;j<=ListaPa.tamano_lista();j++){
		     	auxPa=ListaPa.obtenerDato(j);
		     	cout<<j<<": ";
		     	cout<<"Paciente :"<<auxPa.Nombre<<","<<auxPa.Apellido<<","<<auxPa.NumeroIdentificacion<<","<<auxPa.Medicamentos<<",";
				for(int i=1;i<=auxPa.idPersonal.tamano_lista();i++)   {
					cout<<auxPa.idPersonal.obtenerDato(i);
					if(i!=auxPa.idPersonal.tamano_lista()){
						cout<<",";
					}
				}
				cout<<endl;
				for(int k=1;k<=auxPa.FechasPacientes.tamano_lista();k++){
					auxFC=auxPa.FechasPacientes.obtenerDato(k);
					cout<<auxFC.diaCita<<"/"<<auxFC.MesCita<<"/"<<auxFC.AnioCita<<endl;
				}
				cout<<endl;
	} 
	cout<<endl;
}

void Controlador::AdicionarHospital(string Nombre,string Gerente,string Localidad,int calle_inicial, int calle_final,int carrera_inicial, int carrera_final,int Numero_Medicos, int Numero_Enfermeros){
	Hospital auxH;
	auxH.Nombre=Nombre;
	auxH.Gerente=Gerente;
	auxH.Localidad=Localidad;
	auxH.calle_inicial=calle_inicial;
	auxH.calle_final=calle_final;
	auxH.carrera_inicial=carrera_inicial;
	auxH.carrera_final=carrera_final;
	auxH.Numero_Medicos=0;
	auxH.Numero_Enfermeros=0;
	Listah.insertar_final(auxH);
}
void Controlador::AdicionarPersonal(string Hospital,string Tipo,string Seccion,string Nombre,string Apellido,string TipoIdentificacion,long int NumeroIdentificacion,string Sexo,int TelefonoCel,int Telefonofij,int dia,int mes,int anio,string Correo,string Ciudad,string Pais,string Direccion,string Barrio,int hora_inicial,int hora_final,int num_pacientes){
	PersonalSalud VerificarEdad;
	Personal auxPS;
	Personal auxPS2;
	bool auxHospital=false;
	bool auxId=false;
	auxPS.Hospital=Hospital;
	for(int i=1;i<=Listah.tamano_lista();i++){
		auxH=Listah.obtenerDato(i);
		if(auxPS.Hospital==auxH.Nombre){
			auxHospital=true;
			break;
		}
	}
	if(auxHospital==true){
		auxPS.Tipo=Tipo;
		auxPS.Seccion=Seccion;
		auxPS.Nombre=Nombre;
		auxPS.Apellido=Apellido;
		auxPS.TipoIdentificacion=TipoIdentificacion;
		auxPS.NumeroIdentificacion=NumeroIdentificacion;
		for(int j=1;j<=ListaPS.tamano_lista();j++){
			auxPS2=ListaPS.obtenerDato(j);
			if(auxPS2.NumeroIdentificacion==auxPS.NumeroIdentificacion){
				auxId=true;
				break;
			}
		}
		if(auxId==false){
			auxPS.Sexo=Sexo;
			auxPS.TelefonoCel=TelefonoCel;
			auxPS.Telefonofij=Telefonofij;
			auxPS.dia=dia;
			auxPS.mes=mes;
			auxPS.anio=anio;
			if(VerificarEdad.calcularEdad(2021,2,22,auxPS.anio,auxPS.mes,auxPS.anio)){
				auxPS.Correo=Correo;
				auxPS.Ciudad=Ciudad;
				auxPS.Pais=Pais;
				auxPS.Direccion=Direccion;
				auxPS.Barrio=Barrio;
				auxPS.hora_inicial=hora_inicial;
				auxPS.hora_final=hora_final;
				auxPS.num_pacientes=num_pacientes;
				ListaPS.insertar_final(auxPS);
				for(int k=1;k<=Listah.tamano_lista();k++){
					auxH=Listah.obtenerDato(k);
					if(auxH.Nombre==auxPS.Hospital){
						auxH.Personal_Hospital.insertar_final(auxPS);
						Listah.cambiar(k,auxH);
						break;
					}
				}
				Escribir.ModificarArchivoPersonal(ListaPS);	
			}else{
				cout<<"El personal ingresado no es mayor de edad"<<endl;
			}
		}else{
			cout<<"El id ya esta en la lista"<<endl;
		}
	}else{
		cout<<"El hospital no esta en la lista"<<endl;
	}
	
	
}

void Controlador::AdicionarPaciente(string Nombre,string Apellido,long int NumeroIdentificacion,string sexo,int dia,int mes,int anio,string Enfermedades,string Localidad,string Estado,string NivelGravedad,string Medicamentos, int hora, string Hospital){
	Paciente auxPa2;
	Paciente auxPa;
	bool auxId=false;
	srand(time(NULL));
	auxPa.Nombre=Nombre;
	auxPa.Apellido=Apellido;
	auxPa.NumeroIdentificacion=NumeroIdentificacion;
	for(int i=1;i<=ListaPa.tamano_lista();i++){
			auxPa2=ListaPa.obtenerDato(i);
			if(auxPa2.NumeroIdentificacion==auxPa.NumeroIdentificacion){
				auxId=true;
				break;
			}
	}
	if(auxId!=true){
		auxPa.sexo=sexo;
		auxPa.dia=dia;
		auxPa.mes=mes;
		auxPa.anio=anio;
		auxPa.Enfermedades=Enfermedades;
		auxPa.Localidad=Localidad;
		auxPa.Estado=Estado;
		auxPa.NivelGravedad=NivelGravedad;
		auxPa.Medicamentos=Medicamentos;
		for(int x=1;x<=2;x++){
			auxFC.diaCita=rand()%31+1;
			auxFC.MesCita=rand()%13+1;
			auxFC.AnioCita=2020;
			auxPa.FechasPacientes.insertar_final(auxFC);
		}
		auxPa=Personal_Paciente(auxPa,hora,Hospital);
		if((auxPa.NivelGravedad=="Leve" && auxPa.idPersonal.tamano_lista()==2) || (auxPa.NivelGravedad=="Moderado" && auxPa.idPersonal.tamano_lista()==3) || (auxPa.NivelGravedad=="Severo" && auxPa.idPersonal.tamano_lista()==4)){
			ListaPa.insertar_final(auxPa);
		}else{
			cout<<"Lo siento no tenemos personal suficiente para atenderlo. Debe esperar a que se desocupe personal"<<endl;
			for(int i=1;i<=ListaPS.tamano_lista(); i++){
				auxPS=ListaPS.obtenerDato(i);
				for(int j=1; j<=auxPS.pacientesPS.tamano_lista(); j++){
					auxPa2=auxPS.pacientesPS.obtenerDato(j);
					if(auxPa.NumeroIdentificacion==auxPa2.NumeroIdentificacion){
						auxPS.pacientesPS.eliminar(j);
						ListaPS.cambiar(i,auxPS);
						break;
					}		
				}
				
			}
			
		}
	}else{
		cout<<"El numero de id ya esta en el sistema"<<endl;
	}
	Escribir.ModificarArchivoPaciente(ListaPa);



}
void Controlador::Hospital_Personal(){
	int contM=0;
	int contE=0;
	for(int j=1;j<=Listah.tamano_lista();j++){
		auxH=Listah.obtenerDato(j); 
		for(int i=1;i<=ListaPS.tamano_lista();i++){	
		    auxPS=ListaPS.obtenerDato(i);
		    if(auxPS.Hospital==auxH.Nombre){
		     	auxH.Personal_Hospital.insertar_final(auxPS);
		     	if(auxPS.Tipo=="Medico"){
		     		contM++;
				}
				if(auxPS.Tipo=="Enfermero"){
		     		contE++;
				} 
			}
		}
		auxH.Numero_Medicos=contM;
		auxH.Numero_Enfermeros=contE;
		Listah.cambiar(j,auxH);
		contM=0;
		contE=0;
	}
/*	for(int k=1;k<=Listah.tamano_lista();k++){
		     	auxH=Listah.obtenerDato(k);
		     	
		     	cout<<k<<": ";
		     	cout<<auxH.Nombre<<","<<auxH.Numero_Medicos<<","<<auxH.Numero_Enfermeros<<endl;    
		     	
				
	}*/
cout<<endl;
}
Paciente Controlador::Personal_Paciente(Paciente nuevo_paciente,int hora, string Hospital){
	
	int num_medicos=0;
	int num_enfermeros=0;
	for(int j=1;j<=ListaPS.tamano_lista();j++){
		auxPS=ListaPS.obtenerDato(j);
		if(nuevo_paciente.NivelGravedad=="Leve"){
				if(auxPS.Tipo=="Medico" && auxPS.num_pacientes<10 && num_medicos<1 && (hora>=auxPS.hora_inicial && hora<=auxPS.hora_final) && Hospital==auxPS.Hospital ){
					num_medicos++;
					auxPS.num_pacientes++;
					auxPS.pacientesPS.insertar_final(nuevo_paciente);
					nuevo_paciente.idPersonal.insertar_final(auxPS.NumeroIdentificacion);
				}
				if(auxPS.Tipo=="Enfermero" && auxPS.num_pacientes<10 && num_enfermeros<1 && (hora>=auxPS.hora_inicial && hora<=auxPS.hora_final) && Hospital==auxPS.Hospital){
					num_enfermeros++;
					auxPS.num_pacientes++;
					auxPS.pacientesPS.insertar_final(nuevo_paciente);
					nuevo_paciente.idPersonal.insertar_final(auxPS.NumeroIdentificacion);
				}
				if(num_medicos==1 && num_enfermeros==1)
					break;
			ListaPS.cambiar(j,auxPS);
		}
		if(nuevo_paciente.NivelGravedad=="Moderado"){
				if(auxPS.Tipo=="Medico" && auxPS.num_pacientes<10 && num_medicos<1 && (hora>=auxPS.hora_inicial && hora<=auxPS.hora_final) && Hospital==auxPS.Hospital){
					num_medicos++;
					auxPS.num_pacientes++;
					auxPS.pacientesPS.insertar_final(nuevo_paciente);
					nuevo_paciente.idPersonal.insertar_final(auxPS.NumeroIdentificacion);
				}
				if(auxPS.Tipo=="Enfermero" && auxPS.num_pacientes<10 && num_enfermeros<2 && (hora>=auxPS.hora_inicial && hora<=auxPS.hora_final) && Hospital==auxPS.Hospital){
					num_enfermeros++;
					auxPS.num_pacientes++;
					auxPS.pacientesPS.insertar_final(nuevo_paciente);
					nuevo_paciente.idPersonal.insertar_final(auxPS.NumeroIdentificacion);
				}
				if(num_medicos==1 && num_enfermeros==2)
					break;
			ListaPS.cambiar(j,auxPS);
		}
		if(nuevo_paciente.NivelGravedad=="Severo"){
				if(auxPS.Tipo=="Medico" && auxPS.num_pacientes<10 && num_medicos<1 && (hora>=auxPS.hora_inicial && hora<=auxPS.hora_final) && Hospital==auxPS.Hospital){
					num_medicos++;
					auxPS.num_pacientes++;
					auxPS.pacientesPS.insertar_final(nuevo_paciente);
					nuevo_paciente.idPersonal.insertar_final(auxPS.NumeroIdentificacion);
					
				}
				if(auxPS.Tipo=="Enfermero" && auxPS.num_pacientes<10 && num_enfermeros<3 && (hora>=auxPS.hora_inicial && hora<=auxPS.hora_final) && Hospital==auxPS.Hospital){
					num_enfermeros++;
					auxPS.num_pacientes++;
					auxPS.pacientesPS.insertar_final(nuevo_paciente);
					nuevo_paciente.idPersonal.insertar_final(auxPS.NumeroIdentificacion);
	
				}
				if(num_medicos==1 && num_enfermeros==3)
					break;
			ListaPS.cambiar(j,auxPS);
		}
		
	}
	cout<<endl;
	return nuevo_paciente;
}
void Controlador::RecuperarPacientes(){
	for(int i=1;i<=ListaPS.tamano_lista();i++){
		auxPS=ListaPS.obtenerDato(i);
		for(int j=1;j<=ListaPa.tamano_lista();j++){
			auxPa=ListaPa.obtenerDato(j);
			for(int k=1;k<=auxPa.idPersonal.tamano_lista();k++){
				if(auxPa.idPersonal.obtenerDato(k)==auxPS.NumeroIdentificacion){
					auxPS.pacientesPS.insertar_final(auxPa);			
				}
			}
		}
		auxPS.num_pacientes=auxPS.pacientesPS.tamano_lista();
		ListaPS.cambiar(i,auxPS);
	}
}
void Controlador::Finalizar(){
	Escribir.ModificarArchivoHospital(Listah);
	Escribir.ModificarArchivoPersonal(ListaPS);
	Escribir.ModificarArchivoPaciente(ListaPa);
	exit(3);
}
Lista <Hospital> Controlador::getListaHospitales(){
	return  Listah;
}
Lista <Personal> Controlador::getListaPersonal(){
	return  ListaPS;
}
Lista <Paciente> Controlador::getListaPacientes(){
	return  ListaPa;
}
void Controlador::setListaHospitales(Lista <Hospital> LHospitales){
	Listah=LHospitales;
}
void Controlador::setListaPersonal(Lista <Personal> LPersonalDeSalud){
	ListaPS=LPersonalDeSalud;
	
}
void Controlador::setListaPacientes(Lista <Paciente> LPacientes){
	ListaPa=LPacientes;
}
#endif /*Controlador */ 
