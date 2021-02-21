#ifndef	Simulacion_h
#define Simulacion_h
#include <iostream>
#include <cstdlib>
#include "Listas.h"
#include "Hospitales.h"
#include "PersonalSalud.h"
#include "Pacientes.h"
#include "Controlador.h"


using namespace std;
struct Localidades{
	string	Localidad;
	Lista <Paciente> PacienteLocalidad;
};
struct Gravedad{
	string	NivelGravedad;
	Lista <Paciente> PacienteNivelGravedad;
};
class Simulacion{
	private:
		Hospital auxH;
		Personal auxPS;
		Paciente auxPa;
		Lista <Hospital> Listah;
	    Lista <Personal> ListaPS;
	    Lista <Paciente> ListaPa;
	    Lista <Localidades> ListaLocalidades;
	   	Lista <Gravedad> ListaGravedad;
	   	

	public:
		Simulacion(Controlador Listas){
			Listah=Listas.getListaHospitales();
			ListaPS=Listas.getListaPersonal();
			ListaPa=Listas.getListaPacientes();
			
		}
		void MostrarHospitales();
		void MostrarPersonal(Hospital );
		void MostrarPaciente(Hospital ,Personal );
		void CambiarDatosPaciente(Hospital , Personal , Paciente );
		Paciente CambiarPersonal(string , Paciente ,Hospital , Personal );
};

void Simulacion::MostrarHospitales(){
	int opcionH;	
	string LocalidadH;	
	cout<<"A que Hospital pertenece"<<endl;
	for(int k=1;k<=Listah.tamano_lista();k++){
		     	auxH=Listah.obtenerDato(k);
		     	
		     	cout<<k<<": ";
		     	cout<<auxH.Nombre<<endl;    
				
	}
	
	while(opcionH<=0 || opcionH>=Listah.tamano_lista()){
		cin>>opcionH;
	}
	
	
	auxH=Listah.obtenerDato(opcionH);
	LocalidadH=auxH.Localidad;
	MostrarPersonal(auxH);
	
}

void Simulacion::MostrarPersonal(Hospital H){
	int opcionidPS;
	
	for(int i=1;i<=auxH.Personal_Hospital.tamano_lista();i++){
		     	auxPS=auxH.Personal_Hospital.obtenerDato(i);
		     	cout<<i<<": ";
		     	cout<<auxPS.Nombre<<endl;    
				
	}
	cout<<"Seleccione el numero que corresponde a su posicion en la lista"<<endl;
	
	while(opcionidPS<=0 || opcionidPS>=auxH.Personal_Hospital.tamano_lista()){
		cin>>opcionidPS;
	}
	
	auxPS=auxH.Personal_Hospital.obtenerDato(opcionidPS);
	cout<<auxPS.Nombre<<endl;
	MostrarPaciente(H,auxPS);
	
}

void Simulacion::MostrarPaciente(Hospital H,Personal PS){
	int opcionidPa;
	string LocalidadPa;
	for(int j=1;j<=auxH.Personal_Hospital.tamano_lista();j++){
		     	auxPa=auxPS.pacientesPS.obtenerDato(j);
		     	cout<<j<<": ";
		     	cout<<auxPa.Nombre<<endl;    
				
	}
	
	cout<<"Seleccione el paciente que va a atender"<<endl;
	while(opcionidPa<=0 || opcionidPa>=auxPS.pacientesPS.tamano_lista()){
		cin>>opcionidPa;
	}
	
	auxPa=auxPS.pacientesPS.obtenerDato(opcionidPa);
	LocalidadPa=auxPa.Localidad;
	CambiarDatosPaciente(H, PS, auxPa);
}

void Simulacion::CambiarDatosPaciente(Hospital H , Personal PS,Paciente Pa){
	int opcionM=0;
	
	cout<<"Nombre Paciente : "<<Pa.Nombre<<endl;
	cout<<"Numero de identificacion : "<<Pa.NumeroIdentificacion<<endl;
	cout<<"Enferemedades del paciente : "<<Pa.Enfermedades<<endl;
	cout<<"Estado del paciente : "<<Pa.NivelGravedad<<endl;
	cout<<"Medicamentos del paciente: "<<Pa.Medicamentos<<endl;
	cout<<"Desea adicionar medicamentos"<<endl;
	cout<<"1. Si"<<endl;
	cout<<"2. No"<<endl;

	while(opcionM!=1 && opcionM!=2){
		cin>>opcionM;
		if(opcionM!=1 && opcionM!=2){
			cout<<"La opcion no es correcta"<<endl;
		}
	}
	
	if(opcionM==1){
		cout<<"Digite los medicamentos (Si son mas de 1 separelos con un -)"<<endl;
		cin>>Pa.Medicamentos;
	}
	cout<<"Cual es el estado del Paciente"<<endl;
	cout<<"1. Leve"<<endl;
	cout<<"2. Moderado"<<endl;
	cout<<"3. Severo"<<endl;
	cout<<"4. Recuperado"<<endl;
	cout<<"5. Muerto"<<endl;
	opcionM=0;
	while(opcionM<1 || opcionM>5){
		cin>>opcionM;
		if(opcionM<1 || opcionM>5){
			cout<<"La opcion no es correcta "<<endl;
		}
	}
	switch(opcionM){
		case 1:
			if(Pa.NivelGravedad=="Leve"){
				
			}
			if(Pa.NivelGravedad=="Moderado"){
				Pa=CambiarPersonal("Moderado",Pa,H,PS);
			}
			if(Pa.NivelGravedad=="Severo"){
				
			}
			break;
		case 2:
			if(Pa.NivelGravedad=="Leve"){
				
			}
			if(Pa.NivelGravedad=="Moderado"){
				
			}
			if(Pa.NivelGravedad=="Severo"){
				
			}
		case 3:
			if(Pa.NivelGravedad=="Leve"){
				
			}
			if(Pa.NivelGravedad=="Moderado"){
				
			}
			if(Pa.NivelGravedad=="Severo"){
				
			}	
	}
	
	
}
Paciente Simulacion::CambiarPersonal(string NuevoEstado, Paciente Pa, Hospital auxH2, Personal PS2){
	int num_enfermeros=0;
	if(Pa.NivelGravedad=="Leve" && NuevoEstado=="Moderado"){
		for(int i=1;i<=auxH2.Personal_Hospital.tamano_lista();i++){
			auxPS=auxH2.Personal_Hospital.obtenerDato(i);
			if(auxPS.Tipo=="Enfermero" && auxPS.num_pacientes<10 && num_enfermeros<1  && auxH2.Nombre==auxPS.Hospital){
					num_enfermeros++;
					auxPS.num_pacientes++;
					auxPS.pacientesPS.insertar_final(Pa);
					Pa.idPersonal.insertar_final(auxPS.NumeroIdentificacion);
			}
			auxPS.num_pacientes=auxPS.pacientesPS.tamano_lista();
			ListaPS.cambiar(i,auxPS);
		}
	}
	
	
}
#endif /*Simulacion*/


