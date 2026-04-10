#include <iostream>
#include <bitset>
#include <stdlib.h>
#include <string>

/*
* Este programa simula una casa domótica donde puedes moverte a distintas habitaciones y administrar
* diferentes dispositivos electronicos
*/

using namespace std;

// Enums
enum Dispositivos {
	LUZ_SALA,
	LUZ_CUARTO,
	LUZ_SANITARIO,
	TOSTADORA,
	RADIO,
	VENTANAS,
	TELEVISION,
	AIRE_ACONDICIONADO,
	CANTIDAD_DISPOSITIVOS // Este elemento me ayudará con la cantidad de dispotivos (8)
};


// Funciones
int menu();
void administrar();
void mostrarDispositivos();
void cambiarHabitacion();
void encenderTodo();
void apagarTodo();
string habitacion();

// Variables globales
int op;
int sala {0};
bitset<CANTIDAD_DISPOSITIVOS> casa {0b0000001}; //El usuario empezará en la sala con la luz encendida

int main(){
	
	do{
		op = menu();
		
		system("cls");
		
		switch(op){
			case 1: administrar(); break;
			case 2: cambiarHabitacion(); break;
			case 3: encenderTodo(); break;
			case 4: apagarTodo(); break;
			case 5: cout<<"\nHasta pronto :D"<<endl; break;
			default: cout<<"Ingreso un valor incorrecto "<<endl;
		}
		
		system("cls");
	} while(op != 5);
	
	return 0;
}

int menu(){
	
	cout<<"==================================================="<<endl;
	cout<<"\t.:BIENVENIDO A LA CASA DOMOTICA:."<<endl;
	cout<<"==================================================="<<endl;
	cout<<"Estado General: ["<<habitacion()<<"] "<<casa.count()<<" dispositivo(s) encendido(s)"<<endl;
	cout<<"\n[1] Administrar dispositivos"<<endl;
	cout<<"[2] Cambiar de habitacion"<<endl;
	cout<<"[3] Encender todos los dispositivos"<<endl;
	cout<<"[4] Apagar todos los los dispositivos"<<endl;
	cout<<"[5] Salir"<<endl;
	
	cout<<"\nIngrese una opcion: "; cin>>op;
	
	return op;

}

string habitacion(){
	string hab;
	
	switch(sala){
		case 0: hab = "Sala"; break;
		case 1: hab = "Cuarto"; break;
		case 2: hab = "Sanitario"; break;
	}
	
	return hab;
}

void mostrarDispositivos(){
	cout<<"==================================================="<<endl;
	cout<<"\t.:LISTA DE TODOS LOS DISPOSITIVOS:."<<endl;
	cout<<"==================================================="<<endl;
	cout<<"(1) Encendido / (0) Apagado"<<endl;
	
	cout<<"\n[1] Luz de la Sala: "<<casa.test(LUZ_SALA)<<endl;
	cout<<"[2] Luz del Cuarto: "<<casa.test(LUZ_CUARTO)<<endl;
	cout<<"[3] Luz del Sanitario: "<<casa.test(LUZ_SANITARIO)<<endl;
	cout<<"[4] Tostadora: "<<casa.test(TOSTADORA)<<endl;
	cout<<"[5] Radio: "<<casa.test(RADIO)<<endl;
	cout<<"[6] Ventanas: "<<casa.test(VENTANAS)<<endl;
	cout<<"[7] Television: "<<casa.test(TELEVISION)<<endl;
	cout<<"[8] Aire Acondicionado: "<<casa.test(AIRE_ACONDICIONADO)<<endl;
	cout<<"(9) Volver al menu"<<endl;
}

void administrar(){
	int pos;
	
	do{
		mostrarDispositivos();
		cout<<"\nIngrese el dispositivo que desee cambiar su estado: "; cin>>pos;
		if(pos > 9 || pos < 1){
			cout<<"Ingreso un valor incorrecto "<<endl;
			system("pause");
		} else if (pos < 9){
			casa.flip(pos-1);
		}
		system("cls");
	}while(pos != 9);
	
	
}

void cambiarHabitacion(){
	
	cout<<"============================================="<<endl;
	cout<<"\t.:HABITACIONES DISPONIBLES:."<<endl;
	cout<<"============================================="<<endl;
	cout<<"\n[1] Sala"<<endl;
	cout<<"[2] Cuarto"<<endl;
	cout<<"[3] Sanitario"<<endl;
	cout<<"\nSeleccione una habitacion: "; cin>>sala; sala--;
	
	casa.set(sala);
	
	switch(sala){
		case 0: cout<<"Las luces de la Sala se encendieron automaticamente\n"<<endl; break;
		case 1: cout<<"Las luces del Cuarto se encendieron automaticamente\n"<<endl; break;
		case 2: cout<<"Las luces del Sanitario se encendieron automaticamente\n"<<endl; break;
	}
	
	system("pause");
}

void encenderTodo(){
	casa.set();
	cout<<"\nSe encendieron todos los dispositivos exitosamente\n"<<endl;
	system("pause");
}

void apagarTodo(){
	casa.reset();
	cout<<"\nSe apagaron todos los dispositivos exitosamente\n"<<endl;
	system("pause");
}