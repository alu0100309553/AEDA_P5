/*
 * Mergesort.hpp
 *
 *  Created on: 27 de abr. de 2016
 *      Author: ruben
 */

#ifndef MERGESORT_HPP_
#define MERGESORT_HPP_

#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
class mergesort{

private:
	void mostrardiv(vector<T>& vector, int ini,int cen, int fin);
	void mostrarfus(vector<T>& vector, int x,int y);
public:
	void fusionar(vector<T> &vect, int ini, int cen, int fin, int& cont, bool muestra);
	void ordenar(vector<T>& vect, int ini, int fin, int& cont, bool muestra);
};

template <class T>
void mergesort<T>::mostrardiv(vector<T>& vector, int ini,int cen, int fin){
	for(int i=ini;i<fin;i++){
		if(i==cen)
			cout <<"|"<< " "<<vector[i]<<" ";
		else
			cout << vector[i] << " ";
	}
	cout << endl;
}

template <class T>
void mergesort<T>::mostrarfus(vector<T>& vector, int x,int y){
	for(int i=x;i<y;i++){
		if(i==x)
			cout <<"|"<< " "<<vector[i]<<" ";
		else
			cout << vector[i] << " ";
	}
	cout << endl;
}

template <class T>
void mergesort<T>::fusionar(vector<T> &vect, int ini, int cen, int fin, int& cont, bool muestra){
	int i=ini, j=cen+1, k=ini;
	vector<T> aux;
	aux.resize(vect.size()*2);
	while ((i<=cen) && (j<=fin)){
		cont++;
		if (vect[i] < vect[j]){
			aux[k]=vect[i];
			i++;
			if (muestra){
			}
		}
		else{
			aux[k]=vect[j];
			j++;
		}
		k++;
	}
	if (i>cen)
		while (j<=fin){
			aux[k]=vect[j];
			j++;
			k++;
		}
	else
		while (i<=cen){
			aux[k]=vect[i];
			i++;
			k++;
		}
	for (int i=ini; i<=fin; i++){
		vect[i]=aux[i];
	}

}

template <class T>
void mergesort<T>::ordenar(vector<T>& vect, int ini, int fin, int& cont, bool muestra){
	if (ini < fin){
		int cen= (ini+fin)/2;
		ordenar(vect, ini, cen, cont, muestra);
		ordenar(vect, cen+1, fin, cont, muestra);
		fusionar(vect, ini, cen, fin, cont, muestra);
	}
}

#endif /* MERGESORT_HPP_ */
