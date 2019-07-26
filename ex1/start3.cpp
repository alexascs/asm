#include <iostream>
#include <stdlib.h>
#include <string>
//http://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html#ss5.2
//https://www.opennet.ru/base/dev/gccasm.txt.html

//https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html
//using namespace std; 
 
int main()
{ 		//		
 int int_a=0x00000001; //0x60fe7c
 int int_adress=0x60fe7c;
 char char_1=0xff;
 void *p;
 char *p_char;


 


int output=0x00000000,input=0x11111111,input2=0x33333333;//0x60fe70
int *p_output,*p_input,*p_input2; 
p_output=&output;
p_input=&input;
p_input2=&input2;

std::cout<<std::hex<<input <<std::endl;
std::cout<<std::hex<<&input <<std::endl; 
std::cout<<std::hex<<&input2 <<"    input2 adress                  "<<std::endl; 
 

 
 
    asm(      
           // ".intel_syntax\n"
			//"mov ebx, 1254 \n"
			".att_syntax \n"  
            "	movl %[input], %%ebx 					\n" 			
			"	movl -4(%%ebx ), %%eax 					\n"  	
			//"addl (%%ebx ), %%eax \n"  	
			// "movl   %%ebx ,%%eax  \n"  	
		  // "movl  $0x70fe60, %%ebx \n" 	
           // "addl (%%ebx), %%eax \n" // Perform addition from input2 to eax.
			//"addl %%eax, %%eax \n"
            "movl %%eax, %[output] \n" // Move the eax value to output variable.
            : [output] "+m" (output)
            : [input] "m" (p_input)//,   [input2] "m" (input2)
            : "eax", "ebx"
        );
  
  
  std::cout<<std::hex<<output <<std::endl;
 output=0x00000000;
 int pvalue;
 char char_output;
 char_output=0x00;
 p=(void*)p_input;
	for(int count = 1; count <= 10; ++count) 
	{   
		try // try block
		{   
		 
		
		asm(      
            "	movl %[input], %%ebx 					\n" 			
			"	movl  (%%ebx ), %%eax 					\n"  			 
            "	movb %%al, %[output] 					\n" 
			
            : [output] "+m" (char_output)
            : [input] "m" (p)
            : "eax", "ebx"
        );
		
		  std::cout<<std::hex<<output <<"   hex alex   "<<std::endl;
 		}
		catch( std::string& s) // 1st catch block
		{
		  std::cout <<"execption   " <<s <<"   hex alex   "<< std::endl;
		}

		pvalue=(int)p;
		pvalue++;
		p=(void*)pvalue;	
		
		
	}

						

//std::cout<<output;
						
 
std::cin>>int_a;
return 0;
}