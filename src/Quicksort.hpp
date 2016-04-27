/*
 * Quicksort.hpp
 *
 *  Created on: 27 de abr. de 2016
 *      Author: ruben
 */

#ifndef QUICKSORT_HPP_
#define QUICKSORT_HPP_

#include <cstdlib>
#include <iostream>
#include <vector>
#pragma once

using namespace std;

template <class T> class quicksort_t{
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
public:

virtual ~quicksort_t()
{

}

void ord_por_quicksort(vector<T>& vector, int ini, int fin, int& cont, bool muestra)
		{
	T aux;
	int i=ini, f=fin;
	int p=vector[(i+f)/2];
	if (muestra==true)
	{
     cin.get();
		cout<<"Pivote:";
	mostrar(vector, (i+f)/2, -1);
	}
	while (i < f)
	{
		while (vector[i]<p)
		{
			i++;
		  cont++;
		}
		while (vector[f]>p)
		{
			f--;
			cont++;
		}
		if (i<=f)
		{
			if (muestra==true)
			{
				cin.get();
			mostrar(vector, i, f);
			}
			aux=vector[i];
			vector[i]=vector[f];
			vector[f]=aux;
			i++;
			f--;
			cont++;
		}
	}
	cout<<"ini: "<<ini<<" fin: "<<fin<<" i: "<<i<<" f: "<<f<<endl;
	if (ini<f)
		ord_por_quicksort(vector, ini, f, cont, muestra);
	if (i<fin)
		ord_por_quicksort(vector, i, fin, cont, muestra);



		}


};



#endif /* QUICKSORT_HPP_ */
