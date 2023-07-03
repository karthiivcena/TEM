#include "utility.h"


int main()
{
    int no;
   
    do{
        printf(" \n Enter the function to be executed : \n \n 0 --> Exit \n 1 --> State Trnasition Function \n 2 --> Array Linked List Function \n 3 --> Utility Function \n 4 --> Count Words Function \n 5 --> SUM OF DIGITS USING VARIABLE LENGTH ARGUMENTS \n 6 --> Call the VIBGYOR Function \n 7 --> Call the Sort and Binary Function \n");
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
        	    /* Sum of digits specified using VRAIABLE LENGTH ARGUMENTS */
        	    valist_test_main();
        	    break;
        	case 6:
        	    printf("\n Executing the VIBGYOR function \n");
        	    fn_stack_main();
        	    break;
        	case 7:
        	    printf("\n Executing Sorting an array and Binary Search Function \n");
        	    bin_sort_main();
        	    break;
        	case 8:
        	    printf("\n Executing the C++ File \n");
        	    //cpp_main();
        	    break; 
        	default :
        	    printf("\n Invalid Input \n\n");
        	    exit(0);
    	}
    }while(no != 0);
}


