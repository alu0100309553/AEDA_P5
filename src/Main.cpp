/*
 * Main.cpp
 *
 *  Created on: 27 de abr. de 2016
 *      Author: ruben
 */

//Librerias basicas
//#include <time.h>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <random>
//Implementacion
#include "Quicksort.hpp"
#include "Mergesort.hpp"
#include "ShellSort.hpp"
#include "Insersion.hpp"
#include "Burbuja.hpp"
#include "DNI.hpp"

//typedef int DNI;

using namespace std;

int main() {
	int modo = 0;
	int algoritmo;
	int pruebas;
	int tamVector;
	bool demo;
	double alpha;

	cout<< "***ORDENACION***"<< endl;
	cout<< "-Modo \n (1)Estadístico\n (2)Demostracion"<< endl;
	cin >> modo;

	switch (modo){
	case 1:
	{
		cout<< "Inidique el número de pruebas para cada método:"<< endl;
		cin >> pruebas;
		cout<< "Inidique tamaño de los vectores:"<< endl;
		cin >> tamVector;
		cout<< "Inidique factor alpha para shelsort:"<< endl;
		cin >> alpha;

		cout << "Resultados: \n                Min      Max      Media" << endl;
		int min = 1000000000;
		int max = 0;
		double media = 0;
		int aux = 0;

		for (int i = 0; i < pruebas; i++){
			aux = 0;
			vector<DNI> vect;
			vect.resize(tamVector);
			insercion<DNI> alg;
			for (int j = 0; j<tamVector; j++){
				int aux = (rand() % 50000000) + 30000000;
				vect[j]= aux;
			}
			aux = alg.ordenar(vect,false);

			media += (double)aux;
			if (min > aux){
				min = aux;
			}
			if (max < aux){
				max = aux;
			}
		}

		cout << "Insersion:" <<"      "<< min<<"      " << max<<"      " << (media/(double)pruebas) << endl;
		min = 1000000000;
		max = 0;
		media = 0;
		aux = 0;

		for (int i = 0; i < pruebas; i++){
			aux = 0;
			vector<DNI> vect;
			vect.resize(tamVector);
			burbuja<DNI> alg;
			for (int j = 0; j<tamVector; j++){
				int aux = (rand() % 50000000) + 30000000;
				vect[j]= aux;
			}
			aux = alg.ordenar(vect,false);

			media += (double)aux;
			if (min > aux){
				min = aux;
			}
			if (max < aux){
				max = aux;
			}
		}


		cout << "Burbuja:" <<"        "<< min<<"      " << max<<"      " << (media/(double)pruebas) << endl;
		min = 1000000000;
		max = 0;
		media = 0;
		aux = 0;


		for (int i = 0; i < pruebas; i++){
			aux = 0;
			vector<DNI> vect;
			vect.resize(tamVector);
			shellsort<DNI> alg;
			for (int j = 0; j<tamVector; j++){
				int aux = (rand() % 50000000) + 30000000;
				vect[j]= aux;
			}
			aux = alg.ordenar(vect, alpha ,false);

			media += (double)aux;
			if (min > aux){
				min = aux;
			}
			if (max < aux){
				max = aux;
			}
		}

		cout << "Shellsort:" <<"      "<< min<<"      " << max<<"      " << (media/(double)pruebas) << endl;
		min = 1000000000;
		max = 0;
		media = 0;
		aux = 0;

		for (int i = 0; i < pruebas; i++){
			aux = 0;
			vector<DNI> vect;
			vect.resize(tamVector);
			quicksort<DNI> alg;
			for (int j = 0; j<tamVector; j++){
				int aux = (rand() % 50000000) + 30000000;
				vect[j]= aux;
			}
			alg.ordenar(vect, 0, tamVector-1, aux ,false);

			media += (double)aux;
			if (min > aux){
				min = aux;
			}
			if (max < aux){
				max = aux;
			}
		}
		cout << "Quicksort:" <<"      "<< min<<"      " << max<<"      " << (media/(double)pruebas) << endl;
		min = 1000000000;
		max = 0;
		media = 0;
		aux = 0;
		for (int i = 0; i < pruebas; i++){
			aux = 0;
			vector<DNI> vect;
			vect.resize(tamVector);
			mergesort<DNI> alg;
			for (int j = 0; j<tamVector; j++){
				int aux = (rand() % 50000000) + 30000000;
				vect[j]= aux;
			}
			alg.ordenar(vect, 0, tamVector-1, aux ,false);

			media += (double)aux;
			if (min > aux){
				min = aux;
			}
			if (max < aux){
				max = aux;
			}
		}
		cout << "Mergesort:" <<"      "<< min<<"      " << max<<"      " << (media/(double)pruebas) << endl;
	}
	break;
	case 2:{
		int algoritmo = 0;
		cout<< "Indique el algoritmo que desea probar: \n (1)Insersion \n (2)Burbuja \n (3)Shellsort \n (4)Quickort \n (5)Mergesort"<< endl;
		cin >> algoritmo;
		cout<< "Inidique tamaño del vector:"<< endl;
		cin >> tamVector;
		vector<DNI> vect;
		vect.resize(tamVector);
		quicksort<DNI> alg;
		for (int j = 0; j<tamVector; j++){
			int aux = (rand() % 50000000) + 30000000;
			vect[j]= aux;
		}
		cout << "Vector original: ";
		for (int i = 0; i< tamVector; i++){
			cout << vect[i].dniN << "  " ;
		}
		cout << endl;

		switch (algoritmo){
		case (1):{
			insercion<DNI> alg;
			alg.ordenar(vect, true);
		}
		break;
		case (2):{
			burbuja<DNI> alg;
			alg.ordenar(vect, true);
		}
		break;
		case (3):{
			cout<< "Inidique factor alpha para shelsort:"<< endl;
			cin >> alpha;
			shellsort<DNI> alg;
			alg.ordenar(vect,alpha, true);
		}
		break;
		case (4):{
			quicksort<DNI> alg;
			int aux;
			alg.ordenar(vect, 0, tamVector-1, aux,true);
		}
		break;
		case (5):{
			mergesort<DNI> alg;
			int aux;
			alg.ordenar(vect, 0, tamVector-1, aux,true);
		}
		break;
		default:
			cout << "Algoritmo incorrecto" << endl;
		}
		cout << "Vector ordenado: ";
		for (int i = 0; i< tamVector; i++){
			cout << vect[i].dniN << "  " ;
		}
		cout << endl;
	}
	break;
	default:
		cout << "Modo no válido" << endl;

	}
}




