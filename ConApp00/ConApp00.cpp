// ConApp00.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>

using namespace std;

bool turnoDeX = false;

char tablero[][3] = { {'_','_','_'},
					  {'_','_','_'},
					  {'_','_','_'}
};


char hayGanador(){
	
	//VALIDACIONES DE GANADOR

	//validacion horizontal
	for (int i = 0; i < 3; i++){

		if (tablero[i][0] != '_' && tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2]){

			return tablero[i][0];
		}

	} //for close [Horizontal]

	//validacion Vertical  
	for (int i = 0; i < 3; i++){

		if (tablero[0][i] != '_' && tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i]){

			return tablero[0][i];
		}

	} //for close [Verical]

	//validacion diagonal  izq dere 

		if (tablero[0][0] != '_' && tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2]){
			
			
			return tablero[0][0];
		}

		//validacion diagonal  der izq 

		if (tablero[0][2] != '_' && tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0]){


			return tablero[0][2];
		}



}

//
bool hayempate(){
	
	//Mostrar tablero
	for (int i = 0; i < 3; i++){

		for (int j = 0; j < 3; j++){

			if (tablero[i][j] == '_'){

				return false;
			}
		}
	}
	
	return true;
}

void mostrarTablero(){

	//Variables
	char jugador = turnoDeX ? 'x' : 'o';
	int fila = 0;
	int columna = 0;

	for (int i = 0; i < 3; i++){
			
		for (int j = 0; j < 3; j++){
			
			cout << tablero[i][j] << "\t";
		}

		cout << endl;
	}

	//IPEU
	cout << endl << "Turno de " << jugador << endl;

	cout << endl << "En que fila desea jugar ? " << endl;
	
	cin >> fila;
	
	
	
	cin >> columna;
	
	tablero[fila][columna] = jugador;
	
	turnoDeX = !turnoDeX; //negacion del valor 
	
	char ganador = hayGanador();

	if (ganador != '_'){
		
		cout << "Hay ganador " << ganador << endl;
		system("PAUSE");
		
		
	}

	if (hayempate()){

		cout << " Hay un empate " << endl;
	}

}

int main(){	
	
	while (true){

		mostrarTablero(); //Mostrar el tablero /[x Update]

	} //

	mostrarTablero();
	system("Pause");
	return 0;
	
}

