/*
 * Burbuja.hpp
 *
 *  Created on: 27 de abr. de 2016
 *      Author: ruben
 */

#ifndef BURBUJA_HPP_
#define BURBUJA_HPP_

#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template <class T> class burbuja{
private:
	void mostrar(vector<T>& vector, int x,int y);
public:
	int ordenar(vector<T>& vect, bool muestra);
};

template <class T>
void burbuja<T>::mostrar(vector<T>& vector, int x,int y){
	for(int i=0;i<vector.size();i++){
		if((i==x) || i==y)
			cout << "("<<vector[i]<<")"<<" ";
		else
			cout << vector[i] << " ";
	}
	cout << endl;
}


template <class T>
int burbuja<T>::ordenar(vector<T>& vect, bool muestra){
	T aux;
	//int ini=1, fin=vect.size()-1, cam=vect.size()
	int contador=0;
	bool cambio = false;



	for (int i = 1; i < vect.size(); i++){
		cambio = false;
		for (int j = vect.size()-1; j >= i; j--){

			contador ++;
			if (vect[j] < vect[j-1]){
				if (muestra==true){
					mostrar(vect, j, j-1);
				}
				T aux = vect[j-1];
				vect[j-1] = vect[j];
				vect[j] = aux;
				cambio = true;
			}
		}
		if (!cambio){
			break;
		}
	}
	return contador;
}

#endif /* BURBUJA_HPP_ */
