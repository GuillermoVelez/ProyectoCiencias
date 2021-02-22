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
// Estructura para crear listas de localidades al final de la simulaicon
struct Localidades{
	string	Localidad;
	Lista <Paciente> PacienteLocalidad;
};

// Estructura para crear listas segun el nivel de gravedad de los pacientes
struct Gravedad{
	string	NivelGravedad;
	Lista <Paciente> PacienteNivelGravedad;
};

// Clase encargada de realizar el proceso de la simulacion
class Simulacion{
	private:
		Hospital auxH; //Apuntador a una estructura de tipo hospital
		Personal auxPS; //Apuntador a una estructura de tipo Personal
		Paciente auxPa; //Apuntador a una estructura de tipo Paciente
		Localidades auxLc; //Apuntador a una estructura de tipo Localidades
		Gravedad auxG; //Apuntador a una estructura de tipo Gravedad
		Lista <Hospital> Listah; //Lista de hospitales obtenida desde el controlador
	    Lista <Personal> ListaPS; //Lista de Personal obtenida desde el controlador
	    Lista <Paciente> ListaPa; //Lista de Pacientes obtenida desde el controlador
	    Lista <Localidades> ListaLocalidades; //Lista de localidades creadas a partir de la simulacion
	   	Lista <Gravedad> ListaGravedad; //Lista de pacientes segun el nivel de gravedad creadas a partir de la simulacion
	   	Controlador control; // Objeto que a punta a clase controlador para realizar los cambios en las listas finalizada la simulacion
	   	

	public:
		Simulacion(Controlador Listas){
			Listah=Listas.getListaHospitales();
			ListaPS=Listas.getListaPersonal();
			ListaPa=Listas.getListaPacientes();
			control=Listas;
			auxG.NivelGravedad="Severo";
			ListaGravedad.insertar_final(auxG);
			auxG.NivelGravedad="Leve";
			ListaGravedad.insertar_final(auxG);
			auxG.NivelGravedad="Moderado";
			ListaGravedad.insertar_final(auxG);
		}// Constructor de Simulacion
		void MostrarHospitales();
		void MostrarPersonal(Hospital );
		void MostrarPaciente(Hospital ,Personal );
		void CambiarDatosPaciente(Hospital , Personal , Paciente );
		Paciente CambiarPersonal(string , Paciente ,Hospital , Personal );
		void FinalizarDia();
		void imprimirLocalidades();
		void imprimirGravedad();
};

void Simulacion::MostrarHospitales(){
	int opcionH;		
	bool auxLC2=false;
	for(int k=1;k<=Listah.tamano_lista();k++){
		     	auxH=Listah.obtenerDato(k);
		     	
		     	cout<<k<<": ";
		     	cout<<auxH.Nombre<<endl;    
				
	}
	
	cout<<Listah.tamano_lista()+1<<". "<<"Finalizar dia"<<endl;
	while(opcionH<=0 || opcionH>Listah.tamano_lista()+1){
		cin>>opcionH;
	}
	if(opcionH==Listah.tamano_lista()+1){
		FinalizarDia();
	}else{
		auxH=Listah.obtenerDato(opcionH);
		if(ListaLocalidades.lista_vacia()){
			auxLc.Localidad=auxH.Localidad;
			ListaLocalidades.insertar_final(auxLc);
		}else{
			for(int i=1;i<=ListaLocalidades.tamano_lista();i++){
				auxLc=ListaLocalidades.obtenerDato(i);
				if(auxLc.Localidad==auxH.Localidad){
					auxLC2=true;
				}	
			}
			if(auxLC2==false){
				Localidades auxLc;
				auxLc.Localidad=auxH.Localidad;
				ListaLocalidades.insertar_final(auxLc);
			}
		}
		
		
		MostrarPersonal(auxH);
	}
	
	
	
}

void Simulacion::MostrarPersonal(Hospital H){
	int opcionidPS;
	
	for(int i=1;i<=auxH.Personal_Hospital.tamano_lista();i++){
		     	auxPS=auxH.Personal_Hospital.obtenerDato(i);
		     	cout<<i<<": ";
		     	cout<<auxPS.Nombre<<endl;    
				
	}
	cout<<auxH.Personal_Hospital.tamano_lista()+1<<". "<<"Volver a hospitales"<<endl;
	cout<<"Seleccione el numero que corresponde a su posicion en la lista"<<endl;
	do{
		cin>>opcionidPS;
	}while(opcionidPS<=0 || opcionidPS>auxH.Personal_Hospital.tamano_lista()+1);
		
	
	if(opcionidPS==auxH.Personal_Hospital.tamano_lista()+1)
		MostrarHospitales();
	else{
		auxPS=auxH.Personal_Hospital.obtenerDato(opcionidPS);
		cout<<auxPS.Nombre<<endl;
		MostrarPaciente(H,auxPS);
	}
	
	
}

void Simulacion::MostrarPaciente(Hospital H,Personal PS){
	int opcionidPa;
	string LocalidadPa;
	bool auxGL=false;
	for(int j=1;j<=PS.pacientesPS.tamano_lista();j++){
		     	auxPa=auxPS.pacientesPS.obtenerDato(j);
		     	cout<<j<<": ";
		     	cout<<auxPa.Nombre<<endl;    
	}
	
	cout<<"Seleccione el paciente que va a atender "<<endl;
	
	do{
		cin>>opcionidPa;
	}while(opcionidPa<=0 || opcionidPa>auxPS.pacientesPS.tamano_lista()+1);
		
	
	if(opcionidPa==auxPS.pacientesPS.tamano_lista()+1)
		MostrarHospitales();
	else{
			auxPa=auxPS.pacientesPS.obtenerDato(opcionidPa);
			for(int j=1;j<=ListaGravedad.tamano_lista();j++){
				auxG=ListaGravedad.obtenerDato(j);
				if(auxG.NivelGravedad==auxPa.NivelGravedad){
					auxG.PacienteNivelGravedad.insertar_final(auxPa);
					ListaGravedad.cambiar(j,auxG);
					break;
				}	
			}

		
		for(int i=1;i<=ListaLocalidades.tamano_lista(); i++){
			auxLc=ListaLocalidades.obtenerDato(i);
			if(H.Localidad==auxLc.Localidad){
				auxLc.PacienteLocalidad.insertar_final(auxPa);
				ListaLocalidades.cambiar(i,auxLc);
				break;
			}
		}
		LocalidadPa=auxPa.Localidad;
		CambiarDatosPaciente(H, PS, auxPa);
		opcionidPa=0;
	}
	
}

void Simulacion::CambiarDatosPaciente(Hospital H , Personal PS,Paciente Pa){
	int opcionM=0;
	Personal auxPS4;
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
			if(Pa.NivelGravedad!="Leve"){
				Pa=CambiarPersonal("Leve",Pa,H,PS);	
				
			}
			for(int i=1; i<=PS.pacientesPS.tamano_lista();i++){
				auxPa=PS.pacientesPS.obtenerDato(i);
				if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
					PS.pacientesPS.cambiar(i,Pa);
				}
			}
			for(int j=1; j<=ListaPS.tamano_lista();j++){
				auxPS=ListaPS.obtenerDato(j);
				for(int k=1; k<=auxPS.pacientesPS.tamano_lista();k++){
					auxPa=auxPS.pacientesPS.obtenerDato(k);
					if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
						auxPS.pacientesPS.cambiar(k,Pa);
						for(int b=1;b<=H.Personal_Hospital.tamano_lista();b++){
							auxPS4=H.Personal_Hospital.obtenerDato(b);
							if(auxPS4.NumeroIdentificacion==auxPS.NumeroIdentificacion){
								H.Personal_Hospital.cambiar(b,auxPS);
							}
							break;
						}
						break;
					}
				}
			}
			break;
		case 2:
			if(Pa.NivelGravedad!="Moderado"){
				Pa=CambiarPersonal("Moderado",Pa,H,PS);
				
			}
			for(int i=1; i<=PS.pacientesPS.tamano_lista();i++){
					auxPa=PS.pacientesPS.obtenerDato(i);
					if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
						PS.pacientesPS.cambiar(i,Pa);
					}
			}
			for(int j=1; j<=ListaPS.tamano_lista();j++){
				auxPS=ListaPS.obtenerDato(j);
				for(int k=1; k<=auxPS.pacientesPS.tamano_lista();k++){
					auxPa=auxPS.pacientesPS.obtenerDato(k);
					if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
						auxPS.pacientesPS.cambiar(k,Pa);
						for(int b=1;b<=H.Personal_Hospital.tamano_lista();b++){
							auxPS4=H.Personal_Hospital.obtenerDato(b);
							if(auxPS4.NumeroIdentificacion==auxPS.NumeroIdentificacion){
								H.Personal_Hospital.cambiar(b,auxPS);
							}
							break;
						}
						break;
					}
				}
			}
			break;
		case 3:
			if(Pa.NivelGravedad!="Severo"){
				Pa=CambiarPersonal("Severo",Pa,H,PS);
				
			}
			for(int i=1; i<=PS.pacientesPS.tamano_lista();i++){
					auxPa=PS.pacientesPS.obtenerDato(i);
					if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
						PS.pacientesPS.cambiar(i,Pa);
					}
			}
			for(int j=1; j<=ListaPS.tamano_lista();j++){
				auxPS=ListaPS.obtenerDato(j);
				for(int k=1; k<=auxPS.pacientesPS.tamano_lista();k++){
					auxPa=auxPS.pacientesPS.obtenerDato(k);
					if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
						auxPS.pacientesPS.cambiar(k,Pa);
						for(int b=1;b<=H.Personal_Hospital.tamano_lista();b++){
							auxPS4=H.Personal_Hospital.obtenerDato(b);
							if(auxPS4.NumeroIdentificacion==auxPS.NumeroIdentificacion){
								H.Personal_Hospital.cambiar(b,auxPS);
							}
							break;
						}
						break;
					}
				}
			}
			break;
		case 4:
			Pa=CambiarPersonal("Recuperado",Pa,H,PS);
		/*	for(int i=1; i<=PS.pacientesPS.tamano_lista();i++){
				auxPa=PS.pacientesPS.obtenerDato(i);
				if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
					PS.pacientesPS.eliminar(i);
				}
			}
			for(int j=1; j<=ListaPS.tamano_lista();j++){
				auxPS=ListaPS.obtenerDato(j);
				for(int k=1; k<=auxPS.pacientesPS.tamano_lista();k++){
					auxPa=auxPS.pacientesPS.obtenerDato(k);
					if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
						auxPS.pacientesPS.cambiar(k,Pa);
						for(int b=1;b<=H.Personal_Hospital.tamano_lista();b++){
							auxPS4=H.Personal_Hospital.obtenerDato(b);
							if(auxPS4.NumeroIdentificacion==auxPS.NumeroIdentificacion){
								H.Personal_Hospital.cambiar(b,auxPS);
							}
							break;
						}
						break;
					}
				}
			}*/
			break;
		case 5:
			for(int i=1;i<=PS.pacientesPS.tamano_lista();i++){
				auxPa=PS.pacientesPS.obtenerDato(i);
				if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
					auxPS.pacientesPS.eliminar(i);
					break;
				}
			}
		/*	for(int j=1; j<=ListaPS.tamano_lista();j++){
				auxPS=ListaPS.obtenerDato(j);
				for(int k=1; k<=auxPS.pacientesPS.tamano_lista();k++){
					auxPa=auxPS.pacientesPS.obtenerDato(k);
					if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
						auxPS.pacientesPS.cambiar(k,Pa);
						for(int b=1;b<=H.Personal_Hospital.tamano_lista();b++){
							auxPS4=H.Personal_Hospital.obtenerDato(b);
							if(auxPS4.NumeroIdentificacion==auxPS.NumeroIdentificacion){
								H.Personal_Hospital.cambiar(b,auxPS);
							}
							break;
						}
						break;
					}
				}
			}*/
			Pa=CambiarPersonal("Muerto",Pa,H,PS);
			
			break;	
	}
	
	
	for(int j=1;j<=H.Personal_Hospital.tamano_lista();j++){
		auxPS=H.Personal_Hospital.obtenerDato(j);
		if(auxPS.NumeroIdentificacion==PS.NumeroIdentificacion){
		    H.Personal_Hospital.cambiar(j,PS);
		    break;
		}
	}
	for(int j=1;j<=Listah.tamano_lista();j++){
		auxH=Listah.obtenerDato(j);
		if(auxH.Nombre==H.Nombre){
			Listah.cambiar(j,H);
		}
	}
	
	opcionM=0;
	cout<<"Desea modificar otro paciente? 1.Si 2.No"<<endl;
	while(opcionM!=1 && opcionM!=2){
		cin>>opcionM;
		if(opcionM!=1 && opcionM!=2){
			cout<<"La opcion no es correcta"<<endl;
		}
	}
	if(opcionM==1){
		for(int i=1;i<=Listah.tamano_lista();i++){
			auxH=Listah.obtenerDato(i);
			if(auxH.Nombre==H.Nombre){
				Listah.cambiar(i,H);
				break;
			}
		}
		MostrarPaciente(H,PS);
	}
	if(opcionM==2){
		for(int i=1;i<=Listah.tamano_lista();i++){
			auxH=Listah.obtenerDato(i);
			if(auxH.Nombre==H.Nombre){
				Listah.cambiar(i,H);
				break;
			}
		}
		MostrarPersonal(H);
		
	}
		
}

Paciente Simulacion::CambiarPersonal(string NuevoEstado, Paciente Pa, Hospital auxH2, Personal PS2){
	Personal auxPS3;
	int num_enfermeros=0;	
	if(Pa.NivelGravedad=="Leve" && NuevoEstado=="Moderado"){
		bool auxL=false;
		Pa.NivelGravedad=NuevoEstado;
		for(int i=1;i<=auxH2.Personal_Hospital.tamano_lista();i++){
			auxPS=auxH2.Personal_Hospital.obtenerDato(i);
			for(int j=1;j<=auxPS.pacientesPS.tamano_lista();j++){
				auxPa=auxPS.pacientesPS.obtenerDato(j);
				if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
					auxL=true;
					break;
				}						
			}
			if(auxPS.Tipo=="Enfermero" && auxPS.num_pacientes<10 && num_enfermeros<1  && auxH2.Nombre==auxPS.Hospital  && auxL==false){
					cout<<"Entre "<<auxPS.NumeroIdentificacion<<endl;
					num_enfermeros++;
					auxPS.num_pacientes++;
					Pa.idPersonal.insertar_final(auxPS.NumeroIdentificacion);
					auxPS.pacientesPS.insertar_final(Pa);
					auxPS.num_pacientes=auxPS.pacientesPS.tamano_lista();					
					auxH2.Personal_Hospital.cambiar(i,auxPS);
					for(int i=1;i<=ListaPS.tamano_lista();i++){
						auxPS3=ListaPS.obtenerDato(i);
						if(auxPS3.NumeroIdentificacion==auxPS.NumeroIdentificacion){
							ListaPS.cambiar(i,auxPS);
							break;
						}
					}	
			}
			auxL=false;			
		}
		
		for(int k=1;k<=ListaPa.tamano_lista();k++){
			auxPa=ListaPa.obtenerDato(k);
			if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
				ListaPa.cambiar(k,Pa);
				break;
			}
		}	
	}
	
	if(Pa.NivelGravedad=="Leve" && NuevoEstado=="Severo"){
		bool auxL=false;
		int cont =0;
		Pa.NivelGravedad=NuevoEstado;
		for(int i=1;i<=auxH2.Personal_Hospital.tamano_lista();i++){
			auxPS=auxH2.Personal_Hospital.obtenerDato(i);
			for(int j=1;j<=auxPS.pacientesPS.tamano_lista();j++){
				auxPa=auxPS.pacientesPS.obtenerDato(j);
				if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
					auxL=true;
					break;
				}						
			}
			if(auxPS.Tipo=="Enfermero" && auxPS.num_pacientes<10 && num_enfermeros<2  && auxH2.Nombre==auxPS.Hospital && auxL==false ){
				num_enfermeros++;
				auxPS.num_pacientes++;
				Pa.idPersonal.insertar_final(auxPS.NumeroIdentificacion);
				auxPS.pacientesPS.insertar_final(Pa);
				auxPS.num_pacientes=auxPS.pacientesPS.tamano_lista();					
				auxH2.Personal_Hospital.cambiar(i,auxPS);	
				for(int i=1;i<=ListaPS.tamano_lista();i++){
					auxPS3=ListaPS.obtenerDato(i);
					if(auxPS3.NumeroIdentificacion==auxPS.NumeroIdentificacion){ 
						cont++;
						ListaPS.cambiar(i,auxPS);		
					}
					if(cont==2)
						break;
				}
			}
			auxL=false;
			if(num_enfermeros==2)			
				break;	
		}
		
		for(int k=1;k<=ListaPa.tamano_lista();k++){
			auxPa=ListaPa.obtenerDato(k);
			if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
				ListaPa.cambiar(k,Pa);
				break;
			}
		}
	}
	
	if(Pa.NivelGravedad=="Moderado" && NuevoEstado=="Leve"){
		int cont=0;
		Pa.NivelGravedad=NuevoEstado;
		for(int i=1;i<=auxH2.Personal_Hospital.tamano_lista();i++){
			auxPS=auxH2.Personal_Hospital.obtenerDato(i);
			if(auxPS.Tipo=="Enfermero" && auxPS.NumeroIdentificacion!=PS2.NumeroIdentificacion && cont<1){
				cout<<cont<<endl;
				cout<<auxPS.Nombre<<endl;
				for(int j=1;j<=auxPS.pacientesPS.tamano_lista();j++){
					auxPa=auxPS.pacientesPS.obtenerDato(j);
					if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion ){
						for(int z=1;z<=Pa.idPersonal.tamano_lista();z++){
							if(Pa.idPersonal.obtenerDato(z)==auxPS.NumeroIdentificacion){
								cont++;
								Pa.idPersonal.eliminar(z);
								auxPS.pacientesPS.eliminar(j);
								auxPS.num_pacientes--;
								break;
								break;
								break;
							}	
						}
					}
				}
				for(int k=1;k<=ListaPS.tamano_lista();k++){
					auxPS3=ListaPS.obtenerDato(k);
					if(auxPS3.NumeroIdentificacion==auxPS.NumeroIdentificacion){
						ListaPS.cambiar(k,auxPS);
						break;
					}
				}
				auxH2.Personal_Hospital.cambiar(i,auxPS);
			}
		}	
		for(int k=1;k<=ListaPa.tamano_lista();k++){
			auxPa=ListaPa.obtenerDato(k);
			if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
				ListaPa.cambiar(k,Pa);
				break;
			}
		}	
	
	}
	
	if(Pa.NivelGravedad=="Moderado" && NuevoEstado=="Severo"){
		bool aux=false;
		bool auxL=false;
		Pa.NivelGravedad=NuevoEstado;
		for(int i=1;i<=auxH2.Personal_Hospital.tamano_lista();i++){
			auxPS=auxH2.Personal_Hospital.obtenerDato(i);
			if(auxPS.Tipo=="Enfermero" && auxPS.num_pacientes<10 && num_enfermeros<1  && auxH2.Nombre==auxPS.Hospital ){
				for(int j=1;j<=auxPS.pacientesPS.tamano_lista();j++){
					auxPa=auxPS.pacientesPS.obtenerDato(j);	
					if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
						cout<<auxPS.Nombre<<" "<<auxPa.Nombre<<endl;
						aux=true;
						break;
					}
				}
				cout<<aux<<" Para "<<auxPS.NumeroIdentificacion<<endl;
				if(aux==false){
						cout<<auxPa.NumeroIdentificacion<<endl;
						num_enfermeros++;
						auxPS.num_pacientes++;
						Pa.idPersonal.insertar_final(auxPS.NumeroIdentificacion);
						auxPS.pacientesPS.insertar_final(Pa);
						auxPS.num_pacientes=auxPS.pacientesPS.tamano_lista();					
						auxH2.Personal_Hospital.cambiar(i,auxPS);
				}
				
				aux=false;
				auxL=false;
			}
			if(num_enfermeros==1)			
				break;	
		}
		for(int i=1;i<=ListaPS.tamano_lista();i++){
			auxPS3=ListaPS.obtenerDato(i);
			if(auxPS3.NumeroIdentificacion==auxPS.NumeroIdentificacion){
				ListaPS.cambiar(i,auxPS);
				break;
			}
		}
		for(int k=1;k<=ListaPa.tamano_lista();k++){
			auxPa=ListaPa.obtenerDato(k);
			if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
				ListaPa.cambiar(k,Pa);
				break;
			}
		}	
	}
	if(Pa.NivelGravedad=="Severo" && NuevoEstado=="Leve"){
		int cont =0;
		Pa.NivelGravedad=NuevoEstado;
		for(int i=1;i<=auxH2.Personal_Hospital.tamano_lista();i++){
			auxPS=auxH2.Personal_Hospital.obtenerDato(i);
			if(auxPS.Tipo=="Enfermero" && auxPS.NumeroIdentificacion!=PS2.NumeroIdentificacion && cont<2){
				for(int j=1;j<=auxPS.pacientesPS.tamano_lista();j++){
					auxPa=auxPS.pacientesPS.obtenerDato(j);
					if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion ){
						for(int z=1;z<=Pa.idPersonal.tamano_lista();z++){
							if(Pa.idPersonal.obtenerDato(z)==auxPS.NumeroIdentificacion){
								cont++;
								Pa.idPersonal.eliminar(z);
								auxPS.pacientesPS.eliminar(j);
								auxPS.num_pacientes--;
								for(int k=1;k<=ListaPS.tamano_lista();k++){
								auxPS3=ListaPS.obtenerDato(k);
									if(auxPS3.NumeroIdentificacion==auxPS.NumeroIdentificacion){
										ListaPS.cambiar(k,auxPS);
										break;
									}
								}
								break;
							}	
						}
					}
				}
				
				auxH2.Personal_Hospital.cambiar(i,auxPS);
			}
		}	
		for(int k=1;k<=ListaPa.tamano_lista();k++){
			auxPa=ListaPa.obtenerDato(k);
			if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
				ListaPa.cambiar(k,Pa);
				break;
			}
		}	
	
	}
	if(Pa.NivelGravedad=="Severo" && NuevoEstado=="Moderado"){
		int auxS=0;
		Pa.NivelGravedad=NuevoEstado;
		for(int i=1;i<=auxH2.Personal_Hospital.tamano_lista();i++){
			auxPS=auxH2.Personal_Hospital.obtenerDato(i);
			if(auxPS.Tipo=="Enfermero" && auxPS.NumeroIdentificacion!=PS2.NumeroIdentificacion){
				for(int j=1;j<=auxPS.pacientesPS.tamano_lista();j++){
					auxPa=auxPS.pacientesPS.obtenerDato(j);
					if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion ){
						for(int z=1;z<=Pa.idPersonal.tamano_lista();z++){
							if(Pa.idPersonal.obtenerDato(z)==auxPS.NumeroIdentificacion){
								if(auxS<1){
									Pa.idPersonal.eliminar(z);
									auxPS.pacientesPS.eliminar(j);
									auxPS.num_pacientes--;
									auxS++;
									break;
									break;
									break;
								}else{
									break;
									break;
									break;
								}
								
							}	
						}
					}
				}
				for(int k=1;k<=ListaPS.tamano_lista();k++){
					auxPS3=ListaPS.obtenerDato(k);
					if(auxPS3.NumeroIdentificacion==auxPS.NumeroIdentificacion){
						ListaPS.cambiar(k,auxPS);
						break;
					}
				}
				auxH2.Personal_Hospital.cambiar(i,auxPS);
			}
		}	
		for(int k=1;k<=ListaPa.tamano_lista();k++){
			auxPa=ListaPa.obtenerDato(k);
			if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
				ListaPa.cambiar(k,Pa);
				break;
			}
		}	
	
	}
	if(NuevoEstado=="Recuperado"||NuevoEstado=="Muerto"){
		Pa.Estado=NuevoEstado;
		for(int i=1;i<=auxH2.Personal_Hospital.tamano_lista();i++){
			auxPS=auxH2.Personal_Hospital.obtenerDato(i);
			for(int j=1;j<=auxPS.pacientesPS.tamano_lista();j++){
				auxPa=auxPS.pacientesPS.obtenerDato(j);
				cout<<auxPS.Nombre<<endl;
				cout<<auxPa.Nombre<<endl;
				if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion && auxPS.NumeroIdentificacion!=PS2.NumeroIdentificacion){
					for(int k=1;k<=auxPa.idPersonal.tamano_lista();k++){
						Pa.idPersonal.eliminar(k);	 
					}
					auxPS.num_pacientes--;
					auxPS.pacientesPS.eliminar(j);
					auxPS.num_pacientes=auxPS.pacientesPS.tamano_lista();
					auxH2.Personal_Hospital.cambiar(i,auxPS);
					for(int z=1;z<=ListaPS.tamano_lista();z++){
						auxPS3=ListaPS.obtenerDato(z);
						if(auxPS3.NumeroIdentificacion==auxPS.NumeroIdentificacion){
							ListaPS.cambiar(z,auxPS);
							break;
						}
					}
					break;
				}
									
			}
			cout<<auxPS.pacientesPS.tamano_lista()<<" Para "<<auxPS.Nombre<<endl;
			
		}
		
		for(int k=1;k<=ListaPa.tamano_lista();k++){
			auxPa=ListaPa.obtenerDato(k);
			if(auxPa.NumeroIdentificacion==Pa.NumeroIdentificacion){
				ListaPa.cambiar(k,Pa);
				break;
			}
		}
		
	}
	for(int i=1;i<=ListaPa.tamano_lista();i++){
		auxPa=ListaPa.obtenerDato(i);
		if(auxPa.Nombre==Pa.Nombre){
			cout<<"Paciente lol:"<<auxPa.Nombre<<endl;
			for(int j=1;j<=auxPa.idPersonal.tamano_lista();j++){
				cout<<"Num "<<j<<" "<<auxPa.idPersonal.obtenerDato(j)<<endl;
			}
		}
	
	}
	
	for(int i=1;i<=ListaPS.tamano_lista();i++){
		auxPS=ListaPS.obtenerDato(i);
			if(auxPS.Hospital==PS2.Hospital){
				cout<<"Personal:"<<auxPS.Nombre<<endl;
				for(int j=1;j<=auxPS.pacientesPS.tamano_lista();j++){
					auxPa=auxPS.pacientesPS.obtenerDato(j);
					cout<<"Paciente :"<<j<<" "<<auxPa.Nombre<<endl;
				}
			}

	}
	

	return Pa;
	
	
}
void Simulacion::FinalizarDia(){
	cout<<"Hospitales"<<endl;
	for(int i=1;i<=Listah.tamano_lista();i++){
		auxH=Listah.obtenerDato(i);
		cout<<auxH.Nombre<<endl;
	}
	cout<<"Personal"<<endl;
	cout<<endl;
	for(int i=1;i<=ListaPS.tamano_lista();i++){
		auxPS=ListaPS.obtenerDato(i);
		cout<<auxPS.Nombre<<" numero personal "<<auxPS.num_pacientes<<endl;
	}
	cout<<"Pacientes"<<endl;
	cout<<endl;
	for(int i=1;i<=ListaPa.tamano_lista();i++){
		auxPa=ListaPa.obtenerDato(i);
			cout<<auxPa.Nombre<<" gravedad "<<auxPa.NivelGravedad;
			for(int k=1;k<=auxPa.idPersonal.tamano_lista();k++){
				cout<<auxPa.idPersonal.obtenerDato(k)<<",";
			}
			cout<<endl;
	}
	imprimirLocalidades();
	control.setListaHospitales(Listah);
	control.setListaPersonal(ListaPS);
	control.setListaPacientes(ListaPa);
	control.Finalizar();
}
void Simulacion::imprimirLocalidades(){
	for(int i=1;i<=ListaLocalidades.tamano_lista(); i++){
		auxLc=ListaLocalidades.obtenerDato(i);
		cout<<"Localidad "<<auxLc.Localidad<<" Atendidos "<< auxLc.PacienteLocalidad.tamano_lista()<<endl;
			
	}
	for(int i=1;i<=ListaGravedad.tamano_lista(); i++){
		auxG=ListaGravedad.obtenerDato(i);
		cout<<"Gravedad "<<auxG.NivelGravedad<<" Gravedad "<< auxLc.PacienteLocalidad.tamano_lista()<<endl;
			
	}
}
#endif /*Simulacion*/


