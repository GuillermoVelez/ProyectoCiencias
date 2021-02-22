#ifndef	EscribirArchivos_h
#define EscribirArchivos_h
#include "Listas.h"
#include "Hospitales.h"
#include "PersonalSalud.h"
#include "Pacientes.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
//Clase encargada modificar los archivos cuando finalize el programa
class EscribirArchivos{
	public:
		
		EscribirArchivos(){		
		}
		//Contructor de la clase
		
		void ModificarArchivoHospital(Lista<Hospital> NuevaListaH );
		//Metodo utilizado para modificiar el archivo de Hospitales
		
		void ModificarArchivoPersonal(Lista<Personal> NuevaListaPS );
		//Metodo utilizado para modificiar el archivo de Personal
		
		void ModificarArchivoPaciente(Lista<Paciente> NuevaListaP);
		//Metodo utilizado para modificar el archivo de Pacientes
};
void EscribirArchivos::ModificarArchivoHospital(Lista<Hospital> NuevaListaH ){
	Hospital auxH;
	fstream file;
	//ios::app añadir informacion despues de la que ya tenga
	//ios::out reescribir todo el archivo
	file.open("Archivos//Hospitales.txt",ios::out);
	for(int i=1;i<=NuevaListaH.tamano_lista();i++){
		auxH=NuevaListaH.obtenerDato(i);
		file<<auxH.Nombre<<','<<auxH.Gerente<<','<<auxH.Localidad<<','<<auxH.calle_inicial<<','<<auxH.calle_final<<','<<auxH.carrera_inicial<<','<<auxH.carrera_final<<','<<auxH.Numero_Medicos<<','<<auxH.Numero_Enfermeros<<'.';
		if(i!=NuevaListaH.tamano_lista())
			file<<endl;
	}
	
	file.close();
}
void EscribirArchivos::ModificarArchivoPersonal(Lista<Personal> NuevaListaPS ){
	Personal auxPS;
	fstream file;
	//ios::app añadir informacion despues de la que ya tenga
	//ios::out reescribir todo el archivo
	file.open("Archivos//PersonalSalud.txt",ios::out);
	for(int i=1;i<=NuevaListaPS.tamano_lista();i++){
		auxPS=NuevaListaPS.obtenerDato(i);
		file<<auxPS.Hospital<<','<<auxPS.Tipo<<','<<auxPS.Seccion<<','<<auxPS.Nombre<<','<<auxPS.Apellido<<','<<auxPS.TipoIdentificacion<<','<<auxPS.NumeroIdentificacion<<','<<auxPS.Sexo<<','<<auxPS.TelefonoCel<<','<<auxPS.Telefonofij<<','<<auxPS.dia<<','<<auxPS.mes<<','<<auxPS.anio<<','<<auxPS.Correo<<','<<auxPS.Ciudad<<','<<auxPS.Pais<<','<<auxPS.Direccion<<','<<auxPS.Barrio<<','<<auxPS.hora_inicial<<','<<auxPS.hora_final<<','<<auxPS.num_pacientes<<'.';
		if(i!=NuevaListaPS.tamano_lista())
			file<<endl;
	}
	
	file.close();
}
void EscribirArchivos::ModificarArchivoPaciente(Lista <Paciente> NuevaListaP){
	Paciente auxP;
	FechaCita auxFC;
	fstream file;
	//ios::app añadir informacion despues de la que ya tenga
	//ios::out reescribir todo el archivo
	file.open("Archivos//Pacientes.txt",ios::out);
	for(int i=1;i<=NuevaListaP.tamano_lista();i++){
		auxP=NuevaListaP.obtenerDato(i);
		file<<auxP.Nombre<<','<<auxP.Apellido<<','<<auxP.NumeroIdentificacion<<','<<auxP.sexo<<','<<auxP.dia<<','<<auxP.mes<<','<<auxP.anio<<','<<auxP.Enfermedades<<','<<auxP.Localidad<<','<<auxP.Estado<<','<<auxP.NivelGravedad<<','<<auxP.Medicamentos;
		
		for(int k=1;k<=auxP.FechasPacientes.tamano_lista();k++){	
			auxFC=auxP.FechasPacientes.obtenerDato(k);
			file<<','<<auxFC.diaCita<<','<<auxFC.MesCita<<','<<auxFC.AnioCita;	
		}
		if(auxP.idPersonal.lista_vacia()){
			file<<'.';
		}else{
			for(int j=1;j<=auxP.idPersonal.tamano_lista(); j++){
				file<<','<<auxP.idPersonal.obtenerDato(j);
				if(j==auxP.idPersonal.tamano_lista())
					file<<'.';
			
			}
		}
		
		if(i!=NuevaListaP.tamano_lista())
			file<<endl;
	}
	
	file.close();
}
#endif /*EscribirArchivos*/ 
