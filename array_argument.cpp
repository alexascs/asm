#include <stdlib.h>
#include <iostream>  

void alexf();

int main()
{ 
    int int_output;
	void * p;
    	
	std::cout<<" pointer p " <<std::hex<<p <<"  befor calloc    "<<std::endl; 	
	p=calloc(100, sizeof(int));
	int size_alocation=100* sizeof(int);
	std::cout<<" pointer p " <<std::hex<<p <<" after calloc      "<<std::endl; 
	std::cout<<" pointer to int_output " <<std::hex<<&int_output <<"   "<<std::endl; 
	
 // for(int cout = 1; cout <= size_alocation; ++cout)
	  for(int cout = 1; cout <= 10; ++cout)
 {
	 
	 
	asm( "movl %[input], %%ebx            \n" 

	    "movl $0x11223344, (%%ebx)            \n"
		 "movl (%%ebx) , %%eax           \n"
         "movl %%eax, %[output]            \n" 
         : [output] "+m" (int_output)
         : [input] "r" (p)
         : "eax", "ebx"
    );

        std::cout<<"" <<std::hex<<int_output <<""<<std::endl; 
	 
	 
 };
 

    
    return 0;
}

void  alexf() {  }