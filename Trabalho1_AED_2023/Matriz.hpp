#include <iostream>
#include <vector>
#ifndef MATRIZ_HPP
#define MATRIZ_HPP
using namespace std;

class Matriz{
	private:
		int ordem,*inicio,*final,total=0;
		vector<int> v;

	public:
	
		Matriz(int ordem, vector<int> v);
		
		void setMatriz(int ordem, vector<int> v);
		
        	void conta();
		
		void setOrdem(int ordem);
		
		int getTotal();
		
	
		void imprimeMatriz();
		
};
#endif
