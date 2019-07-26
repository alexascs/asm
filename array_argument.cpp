#include <stdlib.h>
#include <iostream>  

void alexf();
int int_output1=0;
int int_output2=0;
int int_output3=0;


int int_input1=20;
int int_input2=0;
int int_input3=0;

int main()
{  
   
	
	void * p=NULL;
	
  //  alexf();
	
	std::cout<<" pointer p " <<std::hex<<p <<"  befor calloc    "<<std::endl; 	
	p=calloc(100, sizeof(int));
	int size_alocation=100* sizeof(int);
	std::cout<<" pointer p " <<std::hex<<p <<" after calloc      "<<std::endl; 
	std::cout<<" pointer to int_output1 " <<std::hex<<&int_output1 <<"   "<<std::endl; 
	
 // for(int cout = 1; cout <= size_alocation; ++cout)
	//  for(int cout = 1; cout <= 10; ++cout)
 //{
	 
	 
	asm volatile( 	"movl $0x00000000, %%ebx     		 	\n"   //zero ebx
					"movl  %[pointer_function],%%eax        \n"    //pointer to function
					
					"movl %[input1],%%ecx 				\n"   //loop counter
					"lo:        						 	\n"    //label
					
				    
					"movl  %%ecx, %[output2]             	\n"
					//"movl  lo, %[output1]             	\n"
					
					"pushl %%eax								\n"
					"call *%%eax        						 	\n" 
					"popl %%eax   									 \n"
					
					
					"loop  lo             	\n"
         : [output1] "+m" (int_output1),[output2] "+m" (int_output2)
         : [pointer_mem] "r" (p),[pointer_function] "r" (&alexf),[input1] "m" (int_input1)
         : "eax", "ebx", "ebx"
    );

        std::cout<<"int_output1=    " <<std::hex<<int_output1 <<""<<std::endl; 
	    std::cout<<"int_output2=    " <<std::hex<<int_output2 <<""<<std::endl; 
	 
// };
 

    
    return 0;
}

void  alexf() { 
  std::cout<<"int_output2=    " <<std::hex<<int_output2 <<"    function call"<<std::endl; 


 return;}