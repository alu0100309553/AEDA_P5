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
#pragma once

using namespace std;

template <class T> class shellsort_t{
private:

	void mostrar(vector<T>& vector, int x,int y){
		for(int i=0;i<vector.size();i++){
			if((i==x)||(i==y))
				cout << "("<<vector[i]<<")"<<" ";
			else
				cout << vector[i] << " ";
		}
		cout << endl;
	}

	int deltasort(int d, vector<T>& vect, vector<T> vectoraux, bool muestra)
	{
		T aux;
		int j=0, cont=0;
		for (int i= d; i<vect.size(); i++)
		{
			aux=vect[i];
			j=i;
			while ((j>=d) && (aux < vect[j-d]))
			{
				cont++;
				vect[j]=vect[j-d];
				if (muestra==true)
				{
					cin.get();
					mostrar(vectoraux, j, j-d);
				}
				j=j-d;
			}
			vectoraux=vect;
			vect[j]=aux;

		}
		return cont;

	}
public:

	virtual ~shellsort_t()
	{

	}

	int ord_por_shellsort(vector<T>& vect, int alfa, bool muestra)
	{
		int cont=0;
		int del=vect.size();
		vector<T> vecaux=vect;
		while (del>1)
		{
			del=del/alfa;
			if (del==0)
				del=1;
			cont+= deltasort(del, vect, vecaux, muestra);
			vecaux=vect;
		}
		return cont;

	}


};


#endif /* SHELLSORT_HPP_ */
