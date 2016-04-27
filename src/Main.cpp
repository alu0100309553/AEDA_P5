/*
 * Main.cpp
 *
 *  Created on: 27 de abr. de 2016
 *      Author: ruben
 */

//Librerias basicas
#include <time.h>
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
//Implementacion
#include "Quicksort.hpp"
#include "Mergesort.hpp"
#include "ShellSort.hpp"
#include "Insersion.hpp"
#include "Burbuja.hpp"

typedef int DNI;

using namespace std;

int main() {
	srand((unsigned) time(NULL));
	typedef int DNI;
	string linea;
	int npruebas, tamvector, modo;
	bool ok = false;
	bool traza = false;
	int reduc;

	cout << "////////ORDENACIONES EXPRESS////////" << endl;

	ok = false;
	while (!ok) {
		cout
				<< "¿Desea ejecutar en modo estadistica o en modo demostracion? 0/1"
				<< endl;
		cin >> modo;
		if (modo == 0 || modo == 1)
			ok = true;
		else
			cout << "El modo solicitado es incorrecto (escriba 0 o 1)" << endl;
		cout << endl;
	}
	if (modo == 0) {
		ok = false;
		while (!ok) {
			cout << "Introduzca el tamano del vector a ordenar" << endl;
			cin >> tamvector;
			if (tamvector > 0 && tamvector <= 25)
				ok = true;
			else {
				if (tamvector < 0 || tamvector > 25)
					cout
							<< "El tamano es incorrecto (debe ser mayor a 0 y menor o igual a 25)"
							<< endl;
				cout << endl;
			}
		}
		cout << "Introduzca el numero de pruebas a realizar: ";
		cin >> npruebas;
		cout << endl;
		cout
				<< "Introduzca la constante de reduccion alfa del shellsort (denominador): ";
		cin >> reduc;
		cout << endl;
		typedef vector<DNI> ids;
		vector<ids> banco_insercion, banco_seleccion, banco_shellsort,
				banco_quicksort, banco_mergesort, banco_bubblesort,
				banco_heapsort, banco_radixsort;
		vector<int> banco_comp;
		//vector que guarda el n. de comparaciones de cada método sobre los vectores de los bancos de prueba
		insercion<DNI> A;
		shellsort_t<DNI> C;
		quicksort_t<DNI> D;
		mergesort_t<DNI> E;
		burbuja<DNI> F;

		//Se crean vectores para cada método que almacenan una misma serie de vectores de valores aleatorios
		banco_insercion.resize(npruebas);
		banco_seleccion.resize(npruebas);
		banco_shellsort.resize(npruebas);
		banco_quicksort.resize(npruebas);
		banco_mergesort.resize(npruebas);
		banco_bubblesort.resize(npruebas);
		banco_heapsort.resize(npruebas);
		banco_radixsort.resize(npruebas);
		for (int i = 0; i < banco_insercion.size(); i++)
			for (int j = 0; j < tamvector; j++) {
				DNI aux = 15000000 + 30000001 + (rand() % (80000000 - 3000001));
				banco_insercion[i].push_back(aux);
				banco_seleccion[i].push_back(aux);
				banco_shellsort[i].push_back(aux);
				banco_quicksort[i].push_back(aux);
				banco_mergesort[i].push_back(aux);
				banco_bubblesort[i].push_back(aux);
				banco_heapsort[i].push_back(aux);
				banco_radixsort[i].push_back(aux);
			}
		for (int i = 0; i < banco_insercion.size(); i++) {
			banco_comp.push_back(
					A.ordenar(banco_insercion[i], traza));
		}
		cout << "Nº de pruebas: " << npruebas << endl;
		int mincom = tamvector;
		int maxcom = 0;
		float mediacom = 0;
		for (int z = 0; z < npruebas; z++) {
			if (banco_comp[z] < mincom)
				mincom = banco_comp[z];

			if (banco_comp[z] > maxcom)
				maxcom = banco_comp[z];

			mediacom += banco_comp[z];
		}
		mediacom = mediacom / npruebas;
		cout << "                      Numero de comparaciones" << endl;
		cout << "          Minimo          Maximo        Media" << endl;
		cout << "Insercion:    " << mincom << "            " << maxcom
				<< "               " << mediacom << endl;
		banco_comp.clear();
		//for (int i = 0; i < banco_seleccion.size(); i++) {
		//	banco_comp.push_back(
		//			B.ord_por_seleccion(banco_seleccion[i], traza));
		//}
		mincom = tamvector;
		maxcom = 0;
		mediacom = 0;
		for (int z = 0; z < npruebas; z++) {
			if (banco_comp[z] < mincom)
				mincom = banco_comp[z];

			if (banco_comp[z] > maxcom)
				maxcom = banco_comp[z];

			mediacom += banco_comp[z];
		}
		mediacom = mediacom / npruebas;
		cout << "Seleccion:    " << mincom << "            " << maxcom
				<< "               " << mediacom << endl;
		banco_comp.clear();
		for (int i = 0; i < banco_shellsort.size(); i++) {
			banco_comp.push_back(
					C.ord_por_shellsort(banco_shellsort[i], reduc, traza));
		}
		mincom = tamvector;
		maxcom = 0;
		mediacom = 0;
		for (int z = 0; z < npruebas; z++) {
			if (banco_comp[z] < mincom)
				mincom = banco_comp[z];

			if (banco_comp[z] > maxcom)
				maxcom = banco_comp[z];

			mediacom += banco_comp[z];
		}
		mediacom = mediacom / npruebas;
		cout << "ShellSort:    " << mincom << "            " << maxcom
				<< "               " << mediacom << endl;
		banco_comp.clear();
		int cont = 0;
		for (int i = 0; i < banco_quicksort.size(); i++) {
			D.ord_por_quicksort(banco_quicksort[i], 0, tamvector - 1, cont,
					traza);
			banco_comp.push_back(cont);
			cont = 0;
		}
		mincom = tamvector;
		maxcom = 0;
		mediacom = 0;
		for (int z = 0; z < npruebas; z++) {
			if (banco_comp[z] < mincom)
				mincom = banco_comp[z];

			if (banco_comp[z] > maxcom)
				maxcom = banco_comp[z];

			mediacom += banco_comp[z];
		}
		mediacom = mediacom / npruebas;
		cout << "QuickSort:    " << mincom << "            " << maxcom
				<< "               " << mediacom << endl;
		banco_comp.clear();
		cont = 0;
		for (int i = 0; i < banco_mergesort.size(); i++) {
			E.ord_por_fusion(banco_mergesort[i], 0, banco_mergesort[i].size()-1, cont, traza);
			banco_comp.push_back(cont);
			cont = 0;
		}
		mincom = tamvector;
		maxcom = 0;
		mediacom = 0;
		for (int z = 0; z < npruebas; z++) {
			if (banco_comp[z] < mincom)
				mincom = banco_comp[z];

			if (banco_comp[z] > maxcom)
				maxcom = banco_comp[z];

			mediacom += banco_comp[z];
		}
		mediacom = mediacom / npruebas;
		cout << "MergeSort:    " << mincom << "            " << maxcom
				<< "               " << mediacom << endl;
		banco_comp.clear();
		for (int i = 0; i < banco_bubblesort.size(); i++) {
			banco_comp.push_back(
					F.ordenar(banco_bubblesort[i], traza));
		}
		mincom = tamvector;
		maxcom = 0;
		mediacom = 0;
		for (int z = 0; z < npruebas; z++) {
			if (banco_comp[z] < mincom)
				mincom = banco_comp[z];

			if (banco_comp[z] > maxcom)
				maxcom = banco_comp[z];

			mediacom += banco_comp[z];
		}
		mediacom = mediacom / npruebas;
		cout << "BubbleSort:    " << mincom << "            " << maxcom
				<< "               " << mediacom << endl;
		banco_comp.clear();
		//for (int i = 0; i < banco_heapsort.size(); i++) {
		//	banco_comp.push_back(G.ord_por_heapsort(banco_heapsort[i], traza));
		//}
		mincom = tamvector;
		maxcom = 0;
		mediacom = 0;
		for (int z = 0; z < npruebas; z++) {
			if (banco_comp[z] < mincom)
				mincom = banco_comp[z];

			if (banco_comp[z] > maxcom)
				maxcom = banco_comp[z];

			mediacom += banco_comp[z];
		}
		mediacom = mediacom / npruebas;
		cout << "HeapSort:    " << mincom << "            " << maxcom
				<< "               " << mediacom << endl;
		banco_comp.clear();
		//for (int i = 0; i < banco_radixsort.size(); i++) {
		//	banco_comp.push_back(H.ord_por_radixsort(banco_heapsort[i], traza));
		//}
		mincom = tamvector;
		maxcom = 0;
		mediacom = 0;
		for (int z = 0; z < npruebas; z++) {
			if (banco_comp[z] < mincom)
				mincom = banco_comp[z];

			if (banco_comp[z] > maxcom)
				maxcom = banco_comp[z];

			mediacom += banco_comp[z];
		}
		mediacom = mediacom / npruebas;
		cout << "RadixSort:    " << mincom << "            " << maxcom
				<< "               " << mediacom << endl;

	}
	else if (modo == 1)
	{
		ok = false;
		traza = true;
		while (!ok) {
			cout << "Introduzca el tamano del vector a ordenar" << endl;
			cin >> tamvector;
			if (tamvector > 0 && tamvector <= 25)
				ok = true;
			else {
				if (tamvector < 0 || tamvector > 25)
					cout
							<< "El tamano es incorrecto (debe ser mayor a 0 y menor o igual a 25)"
							<< endl;
				cout << endl;
			}
		}
		vector<DNI> vector;
		for (int i = 0; i < tamvector; i++) {
			vector.push_back(
					15000000 + 30000001 + (rand() % (80000000 - 3000001)));
		}
		cout << "Vector del usuario sin ordenar: ";
		for (int i = 0; i < vector.size(); i++) {
			cout << vector[i] << ", ";
		}
		cout << endl;
		ok = true;
		int tipo;
		cout << "Escoja un algoritmo" << endl;
		cout
				<< "1.Insercion 2.Seleccion 3.Shellsort 4.QuickSort 5.Mergesort 6.Bubblesort 7.Heapsort 8. Radixsort"
				<< endl;
		cin >> tipo;
		insercion<DNI> A;
		//seleccion_t<DNI> B;
		shellsort_t<DNI> C;
		quicksort_t<DNI> D;
		mergesort_t<DNI> E;
		burbuja<DNI> F;
		//heapsort_t<DNI> G;
		//radixsort_t<DNI> H;
		switch (tipo) {
		case 1:
			A.ordenar(vector, traza);
			break;
		case 2:
			//B.ord_por_seleccion(vector, traza);
			break;
		case 3:
			cout
					<< "Elija una constante alfa para el shellsort (denominador): ";
			cin >> reduc;
			C.ord_por_shellsort(vector, reduc, traza);
			break;
		case 4:
			int cont2;
			cont2 = 0;
			D.ord_por_quicksort(vector, 0, vector.size() - 1, cont2, traza);
			break;
		case 5:
			int cont3;
			cont3 = 0;
			E.ord_por_fusion(vector, 0, vector.size()-1, cont3, traza);
			break;
		case 6:
			F.ordenar(vector, traza);
			break;
		case 7:
			//G.ord_por_heapsort(vector, traza);
			break;
		case 8:
			//H.ord_por_radixsort(vector, traza);
			break;
		default:
			cout << "Escoja un algoritmo del 1 al 5" << endl;
			break;
		}

		cout << "Vector del usuario ordenado: ";
		for (int i = 0; i < vector.size(); i++) {
			cout << vector[i] << ", ";
		}
		cout << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}



