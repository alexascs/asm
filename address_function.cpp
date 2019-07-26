#include <iostream>     
#include <stdlib.h>

void alexf();

int main()
{ 
    int int_output;
	
	int p=(int)&alexf;
	 std::cout<<"" <<std::hex<<p<<"    jast p         "<<std::endl;
    printf("printf(\"%%p\", pf) is %p\n", alexf);

    asm( "movl %[input], %%eax\n"                
         "movl %%eax, %[output]\n" 
         : [output] "+m" (int_output)
         : [input] "r" (&alexf)
         : "eax", "ebx"
    );

        std::cout<<"" <<std::hex<<int_output <<""<<std::endl;
    return 0;
}

void  alexf() {  }