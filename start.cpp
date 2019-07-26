#include <iostream>
#include <stdlib.h>
#include <string>
//http://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html#ss5.2
//https://www.opennet.ru/base/dev/gccasm.txt.html

//https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html
//using namespace std; 
 void alexf();
 
int main()
{ 		//		
int int_a=0x00000001; //0x60fe7c
int int_adress=0x60fe7c;

void *p;
char *p_char;
int output=0x00000000,input=0x11111111,input2=0x33333333;//0x60fe70
int *p_output,*p_input,*p_input2; 

void (*p_function)();

	p_output=&output;
	p_input=&input;
	p_input2=&input2;

 
 alexf();
 std::cout<<std::hex<<&alexf<<"   alexf adress"<<std::endl;
 
 
 int pvalue=0;
 char char_output;
 char_output=0x00;
 p=(void*)p_input;
	for(int count = 1; count <= 100; ++count) 
	{   
	 
		asm(      
            "	movl %[input], %%ebx 					\n" 			
			"	movl  (%%ebx ), %%eax 					\n"  			 
            "	movb %%al, %[output] 					\n" 
			
            : [output] "+m" (char_output)
            : [input] "m" (p)
            : "eax", "ebx"
        );
		
		  std::cout<<count <<"      " <<std::hex<<(int)char_output <<"   hex alex   "<<std::endl;
 		 
	 

		pvalue=(int)p;
		pvalue++;
		p=(void*)pvalue;	
		
		
	}

						

//std::cout<<output;
						
 
std::cin>>int_a;
return 0;
}

 void  alexf(){
	 std::cout<<" function alexf calling answer "<<std::endl;
	 
 }