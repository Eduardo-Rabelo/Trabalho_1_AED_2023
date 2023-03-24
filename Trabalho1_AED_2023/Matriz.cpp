#include <iostream>
#include <time.h>
#include "Matriz.hpp"
using namespace std;

Matriz::Matriz( int ordem, vector<int> v){
	this->ordem=ordem;
	
	for (int i=0 ; i < v.size();i++){
	    this->v.push_back(v[i]);
	}

	this->inicio=&this->v[0];
	this->final=&this->v[(ordem*ordem)-1];
}


void Matriz::setMatriz(int ordem, vector<int> v){
	
	this->ordem=ordem;
	this->v.clear();
	
	for (int i=0 ; i < v.size();i++){
	    this->v.push_back(v[i]);
	}

	this->inicio=&this->v[0];
	this->final=&this->v[(ordem*ordem)-1];
}

void Matriz::setOrdem(int ordem){
	this->ordem=ordem;
}

int Matriz::getTotal(){
	return this->total;
}

void Matriz::imprimeMatriz(){
    int contl=1,*p=this->inicio,*p2=this->final;
    
	while(p<=p2){
	    if(*p>=0 && *p<10 ){
	        cout << "0";
	    }
	    cout << *p << " ";
	    
	    if(contl%ordem==0){
	        cout << "\n";
	    }
	    
	    contl++;
	    p++;
	}
}



void Matriz::conta(){
    
    int contl=1,contc=1,cont=1,*p=this->inicio,*p2=this->final,total=*p;
    
    
    while(p < p2){
		
		if(contl==ordem && p!=p2){
			*p=-1;
			total= total + *(p+1);
			p = (p + 1);
		}
		else if(contc%ordem==0){
			
			if(*(p - 1) > *(p + ordem) && *(p - 1) > *(p + ordem - 1) ){
				total = total + *(p - 1);
				*p=-1;
				p = (p - 1);	
				contc = contc - 1;	
			}
			
			else if(*(p + ordem - 1) > *(p - 1) && *(p + ordem - 1) > *(p + ordem) ){
			    total = total + *(p + ordem - 1);
				*p=-1;
				p = (p + ordem - 1);
				contl++;
				contc = contc - 1;	
			}
			
			else if(*(p + ordem - 1) > *(p + ordem) && *(p + ordem - 1) == *(p - 1)){
			    total = total + *(p + ordem - 1);
				*p=-1;
				p = (p + ordem - 1);
				contl++;
				contc = contc - 1;	
			}
			
			else{
				total = total + *(p + ordem);
				*p=-1;
				p = (p + ordem);
				contl++;		
			} 
		}

		else if(contc == 1){
			if(*(p + 1) > *(p + ordem) && *(p + 1) > *(p + ordem + 1) ){
				total = total + *(p + 1);
				*p=-1;
				p = (p + 1);	
				contc++;	
			}
			
			else if(*(p + ordem + 1) > *(p + ordem) && *(p + ordem + 1) > *(p + 1)){
			    total = total + *(p + ordem + 1);
				*p=-1;
				p = (p + ordem + 1);
				contl++;
				contc = contc + 1;	
			}
			
			else if( *(p + ordem + 1) > *(p + ordem) && *(p + ordem + 1) == *(p + 1)){
			    total = total + *(p + ordem + 1);
				*p=-1;
				p = (p + ordem + 1);
				contl++;
				contc = contc + 1;	
			    
			}
			
			else{
				total = total + *(p + ordem);
				*p=-1;
				p = (p + ordem);
				contl++;		
			} 
			
		}
		
		
		else{
			if(*(p + 1) > *(p + ordem) && *(p + 1) > *(p - 1) && *(p + 1) > *(p + ordem + 1) && *(p + 1) > *(p + ordem - 1) ){
				total = total + *(p + 1);
				*p=-1;
				p = (p + 1);	
				contc++;	
			}
			
			else if(*(p - 1) > *(p + ordem) && *(p - 1) > *(p + 1) && *(p - 1) > *(p + ordem + 1) && *(p - 1) > *(p + ordem - 1) ){
				total = total + *(p - 1);
				*p=-1;
				p = (p - 1);	
				contc = contc - 1;	
			}
			
			else if(*(p + ordem + 1) > *(p + ordem) && *(p + ordem + 1) > *(p - 1) && *(p + ordem + 1) > *(p + 1) && *(p + ordem + 1) > *(p + ordem - 1)){
			    total = total + *(p + ordem + 1);
			    *p=-1;
			    p = (p + ordem + 1);
			    contc = contc + 1;
			    contl = contl + 1;
			}
			
    		else if(*(p + ordem - 1) > *(p + ordem) && *(p + ordem - 1) > *(p - 1) && *(p + ordem - 1) > *(p + 1) && *(p + ordem - 1) > *(p + ordem + 1 )){              
    		    total = total + *(p + ordem - 1);
    		    *p=-1;
    		    p = (p + ordem - 1);
    		    contc = contc - 1;
			    contl = contl + 1;
    		}
    		
    		else if( *(p - 1) == *(p + 1) && *(p - 1) == *(p + ordem + 1) && *(p - 1) == *(p + ordem - 1) && *(p - 1) > *(p + ordem )){
    		    total = total + *(p + ordem + 1);
			    *p=-1;
			    p = (p + ordem + 1);
			    contc = contc + 1;
			    contl = contl + 1;
    		}
    		

    		else if( *(p - 1) == *(p + 1) && *(p - 1) == *(p + ordem + 1) && *(p - 1) > *(p + ordem )){
    		    total = total + *(p + ordem + 1);
			    *p=-1;
			    p = (p + ordem + 1);
			    contc = contc + 1;
			    contl = contl + 1;
    		}
    		
    		else if( *(p + 1) == *(p + ordem - 1) && *(p + 1) == *(p + ordem + 1) && *(p + 1) > *(p + ordem ) ){
			    total = total + *(p + ordem + 1);
			    *p=-1;
			    p = (p + ordem + 1);
			    contc = contc + 1;
			    contl = contl + 1;
    		}
    		
    		else if(*(p - 1) == *(p + ordem - 1) && *(p - 1) == *(p + ordem + 1) && *(p - 1) > *(p + ordem )){
    		    total = total + *(p + ordem + 1);
			    *p=-1;
			    p = (p + ordem + 1);
			    contc = contc + 1;
			    contl = contl + 1;
    		}
			    
			else if( *(p - 1) == *(p + 1) && *(p - 1) == *(p + ordem - 1) && *(p - 1) > *(p + ordem )){
			    total = total + *(p + ordem - 1);
    		    *p=-1;
    		    p = (p + ordem - 1);
    		    contc = contc - 1;
			    contl = contl + 1;
			}
			    
           else if(*(p + ordem) < *(p + ordem + 1) || *(p + ordem) < *(p + ordem - 1) || *(p + ordem) < *(p - 1) || *(p + ordem) < *(p + 1) ){
               
            
                if(*(p - 1) == *(p + 1) && *(p + ordem + 1) == *(p + ordem - 1) ){
                    
                    if(*(p - 1) > *(p + ordem + 1)){
                        total = total + *(p + 1);
        				*p=-1;
        				p = (p + 1);	
        				contc++;
                    }
                    else{
                        total = total + *(p + ordem + 1);
        			    *p=-1;
        			    p = (p + ordem + 1);
        			    contc = contc + 1;
        			    contl = contl + 1;
                    }
                    
                }
                
                else if(*(p - 1) == *(p + ordem + 1) && *(p + 1) == *(p + ordem - 1)){
                    if(*( p - 1) > *(p + 1)){
                        total = total + *(p + ordem + 1);
        			    *p=-1;
        			    p = (p + ordem + 1);
        			    contc = contc + 1;
        			    contl = contl + 1;
                    }
                    
                    else{
                        total = total + *(p + ordem - 1);
            		    *p=-1;
            		    p = (p + ordem - 1);
            		    contc = contc - 1;
        			    contl = contl + 1;
                    }
                }
                
                else if(*(p - 1) == *(p + ordem - 1) && *(p + 1) == *(p + ordem + 1)){
                    if(*(p - 1) > *(p + 1)){
                        total = total + *(p + ordem - 1);
            		    *p=-1;
            		    p = (p + ordem - 1);
            		    contc = contc - 1;
        			    contl = contl + 1;
                    }
                    else{
                        total = total + *(p + ordem + 1);
        			    *p=-1;
        			    p = (p + ordem + 1);
        			    contc = contc + 1;
        			    contl = contl + 1;
                        
                    }
                    
                }

           }

			else{
				total = total + *(p + ordem);
				*p=-1;
				p = (p + ordem);
				contl++;		
			} 
		}
		
	}
	*p=-1;
	this->total=total;
}
