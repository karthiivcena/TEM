#include "utility.h"

extern "C"
{

int test_main()
{
    int no;
   
    do{
        printf(" \n Enter the function to be executed : \n \n 0 --> Exit \n 1 --> State Trnasition Function \n 2 --> Array Linked List Function \n 3 --> Utility Function \n 4 --> Count Words Function \n 5 --> SUM OF DIGITS USING VARIABLE LENGTH ARGUMENTS \n 6 --> Call the VIBGYOR Function \n 7 --> Call the Sort and Binary Function \n 8 --> C++ OOPs CONCEPTS \n 9 --> Bit Set for a specified position \n 10 --> SET LSB OR MSB OR K BITS \n 11 --> BIG ENDIAN OR LITTLE ENDIAN FUNCTION \n 12 --> Function Overloading, Operator Overloading along with Friend Function in C++ \n ");
        scanf("%d", &no);
    	switch(no)
    	{
    	        case 0: 
        	    printf("\n EXITED FROM THE MAIN FUNCTION \n\n");
        	    exit(0);
        	    
        	case 1:
        	    printf("\n Executing STATE TRANSITION FUNCTION \n\n");
        	    /* Main function for state transition */
        	    state_trans_main();
     		    break;
     		    
        	case 2:
        	    printf("\n Executing ARRAY- LINKED LIST IMPLEMENTATION FUNCTION \n\n");
    		    /* Array List Main Function */
        	    array_list_main();
        	    break;
        	    
        	case 3:
        	    printf("\n Executing UTILITY FUNCTION \n\n");
    		    /* Utility Mail Function */
        	     utility_main();
        	     break;
        	     
     		case 4:
     		    printf("\n Executing WORD COUNT FUNCTION \n\n");
    		    /* Count Words Main Function*/
        	    count_words_main();
        	    break;
        	
        	case 5:
        	    printf("\n Executing sum of specified digits using VARIABLE LENGTH ARUMENTS \n");
        	    /* Sum of digits specified using VARIABLE LENGTH ARGUMENTS */
        	    valist_test_main();
        	    break;
        	    
        	case 6:
        	    printf("\n Executing the VIBGYOR function \n");
        	    /* Functions calling another functions till the end of the las function Call VIBGYOR */
        	    fn_stack_main();
        	    break;
        	    
        	case 7:
        	    printf("\n Executing Sorting an array and Binary Search Function \n");
        	    sort_bin_main();
        	    break;
        	    
        	case 8:
        	    printf("\n Executing the C++ OOPS CONCEPTS File \n");
        	    oop_concept_main(); 
        	    break; 
        	    
        	case 9:
        	    printf("\n Executing the Bit Setting in the Byte Class \n");
        	    Byte_set_main();
        	    break;
        	
        	case 10:
        	    printf("\n Executing the SET BIT Function for LSB, MSB and K elements \n");
        	    set_bit_main();
        	    break;
        	    
        	case 11:
        	    printf("\n BIG-ENDIAN or LITTLE-ENDIAN \n");
        	    big_little_endian_main();
        	    break;
        	    
        	case 12:
        	    printf("\n Function Overloading and Operator Overloading in C++ \n");
        	    function_overloading_main();
        	    break;
        	    
        	case 13:
        	    printf("\n STACK IMPLEMENTATION \n");
        	    
        	    break;
        	    
        	default :
        	    printf("\n Invalid Input \n\n");
        	    exit(0);
        	    
    	}
    }while(no != 0);
    return 0;
}


#ifndef RELOCATABLE_OBJ
int main()
{
    test_main();
}
#endif   /* Ending the Relocatable OBJECTS*/

}
