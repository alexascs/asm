#include <iostream>
#include "message.h"

//http://www.ibiblio.org/gferg/ldp/GCC-Inline-Assembly-HOWTO.html#ss5.2
//https://www.opennet.ru/base/dev/gccasm.txt.html
using namespace std; 
int c;
int main()
{//int a;

//int *b;

// int d; 
 
 

 
 
  // cout<<&a   <<" &a "<<endl;
   // cout<<a   <<" a "<<endl;
  // cout<<sizeof(a)   <<" sizeof(a) "<<endl;
  
   // cout <<endl; 
      // cout <<endl; 
   
 // cout<<b   <<" b "<<endl;           
 // cout<<*b<<" *b  "<<endl;
 // cout<<&b<<" &b "<<endl<<endl;
//b=&a; 
 // cout<<b   <<" b "<<endl;           
 // cout<<*b<<" *b  "<<endl;
 // cout<<&b<<" &b "<<endl<<endl;

//*b=message();

// cout<<&a   <<" &a "<<endl;
// cout<<a   <<" a "<<endl<<endl<<endl;
// cout<<&main  <<" &main "<<endl;

/* cout<<&main;
 */
 //c=10;
 
 // cout<<&c   <<" &с "<<endl;
 // cout<<c   <<" с "<<endl;
  
   // cout <<endl; 
      // cout <<endl; 
 
 
// __asm__ __volatile__ (
                        // ".intel_syntax\n"
						 "mov eax, 0 \n"
                        // "mov eax, %1 \n"
						
						// "add eax,12 \n"
						// "mov eax, %0 \n"
						// ".att_syntax \n"
                        // :"=r"(c)
                        // :"r"(c))
						// :;

 
   // cout<<&c   <<" &с "<<endl;
   // cout<<c   <<" с "<<endl;
  
   // cout <<endl; 
   //   cout <<endl; 
/* __asm__ __volatile__ (
                        ".intel_syntax\n"
                        "add %0, %1 \n"
                        ".att_syntax \n"
                        :"+r"(a)
                        :"r"(c)); */
						
// __asm__ __volatile__ (
                        // ".intel_syntax\n"
                        // "mov eax, %1 \n"
						// "add eax,1 \n"
						// "mov eax, %0 \n"
						// ".att_syntax \n"
                        // :"=r"(c)
                        // :"r"(c));


   // cout<<&c   <<" &с "<<endl;
   // cout<<c   <<" с "<<endl;
  
   // cout <<endl; 
      // cout <<endl;						
   int output;						
 int input, input2;
 input=10;
 input2=20;
 
   // cin>>input;
    //cin>>input2;
    
    // Initialize output variable
 

  asm(
            "movl %[input], %%eax \n"  // Move the input value to eax.
            "addl %[input2], %%eax \n" // Perform addition from input2 to eax.
            "movl %%eax, %[output] \n" // Move the eax value to output variable.
            : [output] "=m" (output)
            : [input] "m" (input),
              [input2] "m" (input2)
            : "eax"
        );
	
						
						
						
 
cin>>a;
return 0;
}