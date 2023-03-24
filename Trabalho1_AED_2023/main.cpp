#include <stdio.h>
#include <iostream>
#include <time.h>
#include "Matriz.hpp"
#include <fstream>
#include <typeinfo>
#include <vector>
using namespace std;


int main(){
    int o;
	string str,line;
	vector<string> vecs;
	
	ifstream File("input.data");
	

		
		
		while(getline(File,str)){
			vecs.push_back(str);
		}
		
		vector<int> veci;
		
		
		string aux;
		
		
		o=stoi(vecs[0]);		
		
		for(int j = 1; j < vecs.size(); j++ ){
			
			for(int i=0;i < vecs[j].size(); i++){
				
				if(vecs[j][i]==' '){
					veci.push_back(stoi(aux));
					aux="";
				}
				
				aux.push_back(vecs[j][i]);
			}
			
		}

		vector<int> vaux;
		int totalMatrizes=0;
		Matriz maux(o,vaux);

		for(int i=0;i<(veci.size()+1);i++){
				
			if(i%(o*o)==0 && i!=0){
					
				maux.setMatriz(o,vaux);
				
				cout << "Matriz:\n\n";
				maux.imprimeMatriz();
				maux.conta();
				cout << "\n\nCaminho da Matriz:\n\n";
				maux.imprimeMatriz();
				cout << "\nTotal do caminho da matriz: " << maux.getTotal();
				totalMatrizes = totalMatrizes + maux.getTotal(); 
				vaux.clear();
				cout << "\n\n\n";
			}

			vaux.push_back(veci[i]);

		}
		cout << "\n\n\nSoma dos caminhos de todas as matrizes: " << totalMatrizes;
				
	
	return 0;
}








