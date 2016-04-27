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
#pragma once

using namespace std;

template <class T> class mergesort_t{

private:
	int subvec;
	void mostrar(vector<T>& vector, int x,int y){
			   for(int i=0;i<vector.size();i++){
			      if((i==x)||(i==y))
			         cout << "("<<vector[i]<<")"<<" ";
			      else
			      cout << vector[i] << " ";
			   }
			   cout << endl;
			}
public:
	mergesort_t():
	subvec(0)
	{}

	void fusionar(vector<T> &vect, int ini, int cen, int fin, int& cont, bool muestra)
	{
		int i=ini, j=cen+1, k=ini;
		vector<T> aux;
		aux.resize(50);
		while ((i<=cen) && (j<=fin))
		{
			if (vect[i] < vect[j])
			{
				aux[k]=vect[i];
				i++;
			}
			else
			{
				aux[k]=vect[j];
				j++;
			}
			k++;
		}
		if (i>cen)
			while (j<=fin)
			{
				aux[k]=vect[j];
				j++;
				k++;
			}
		else
			while (i<=cen)
			{
				aux[k]=vect[i];
							i++;
							k++;
			}
		for (int i=ini; i<=fin; i++)
		{
			vect[i]=aux[i];
		}

	}

virtual ~mergesort_t()
{
}

void ord_por_fusion(vector<T>& vect, int ini, int fin, int& cont, bool muestra)
		{
	if (ini < fin)
	{
		int cen= (ini+fin)/2;
			ord_por_fusion(vect, ini, cen, cont, muestra);
			ord_por_fusion(vect, cen+1, fin, cont, muestra);
			fusionar(vect, ini, cen, fin, cont, muestra);
	}

		}

};



#endif /* MERGESORT_HPP_ */
