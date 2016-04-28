/*
 * Insersion.hpp
 *
 *  Created on: 27 de abr. de 2016
 *      Author: ruben
 */

#ifndef INSERSION_HPP_
#define INSERSION_HPP_
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template <class T>

class insercion{
private:
	void mostrar(vector<T>& vector, int x,int y);

public:
	int ordenar(vector<T>& vect, bool muestra);
};

template <class T>
void insercion<T>::mostrar(vector<T>& vector, int x,int y){
	for(int i=0;i<vector.size();i++){
		if((i==x) || i==y)
			cout << "("<<vector[i]<<")"<<" ";
		else
			cout << vector[i] << " ";
	}
	cout << endl;
}

template <class T>

int insercion<T>::ordenar(vector<T>& vect, bool muestra)
{
	T temp;
	int j;
	int cont=0;
	vector<T> vectaux=vect;

	for (int i=1; i<vect.size(); i++){
		temp = vect[i];
		j = i;
		while (j > 0 && temp < vect[j-1]){
			vect[j] = vect[j-1];
			j--;
			cont++;
		}
		if (muestra==true){
			mostrar(vectaux, i, j);
			cout<<endl;
		}
		vect[j] = temp;
		vectaux=vect;
	}
	return cont;
}
#endif /* INSERSION_HPP_ */
