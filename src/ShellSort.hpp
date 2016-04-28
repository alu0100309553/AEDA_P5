/*
 * ShellSort.hpp
 *
 *  Created on: 27 de abr. de 2016
 *      Author: ruben
 */

#ifndef SHELLSORT_HPP_
#define SHELLSORT_HPP_


#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

template <class T> class shellsort{
private:
	void mostrar(vector<T>& vector, int x,int y);
	int deltasort(int d, vector<T>& vect, vector<T> vectoraux, bool muestra);
public:
	int ordenar(vector<T>& vect, double alfa, bool muestra);
};

template <class T>

void shellsort<T>::mostrar(vector<T>& vector, int x,int y){
	for(int i=0;i<vector.size();i++){
		if((i==x)||(i==y))
			cout << "("<<vector[i]<<")"<<" ";
		else
			cout << vector[i] << " ";
	}
	cout << endl;
}

template <class T>

int shellsort<T>::deltasort(int d, vector<T>& vect, vector<T> vectoraux, bool muestra){
	T aux;
	int j=0, cont=0;
	for (int i= d; i<vect.size(); i++){
		aux=vect[i];
		j=i;
		while ((j>=d) && (aux < vect[j-d])){
			cont++;
			vect[j]=vect[j-d];
			if (muestra==true){
				mostrar(vectoraux, j, j-d);
			}
			j=j-d;
		}
		vectoraux=vect;
		vect[j]=aux;
	}
	return cont;
}

template <class T>
int shellsort<T>::ordenar(vector<T>& vect, double alfa, bool muestra){
		int cont=0;
		int del=vect.size();
		vector<T> vecaux=vect;
		while (del>1){
			del=(int)(del*alfa);
			if (del==0)
				del=1;
			cont+= deltasort(del, vect, vecaux, muestra);
			vecaux=vect;
		}
		return cont;
	}


#endif /* SHELLSORT_HPP_ */
