/*
 * DNI.cpp
 * Autor: Rubén Labrador Páez
 * EMail: alu0100309553@ull.edu.es
 * Grado en Ingeniería informática, 2ºCurso, Universidad de La Laguna.
 * Algoritmos y estructuras de datos avanzadas, Práctica 4, Tabla Hash.
 */

#include "DNI.hpp"

//Constructor por defecto
DNI::DNI() :
		dniN(0) {
}

//Constructor con parámetros
DNI::DNI(int N) :
		dniN(N) {
}

//Destructor
DNI::~DNI() {
}

//Operador de igualdad con otro DNI
bool DNI::operator ==(DNI b) {
	return dniN == b.dniN;
}

//Operador de igualdad con un entero
bool DNI::operator ==(int b) {
	return dniN == b;
}

//Operador módulo
int DNI::operator %(int n) {
	return dniN % n;
}

//Operador de asignación del número de DNI
void DNI::operator =(int n) {
	dniN = n;
}

bool DNI::operator <(DNI b){
	return dniN < b.dniN;
}
bool DNI::operator >(DNI b){
	return dniN > b.dniN;
}

