#include "utility.h"


int main()
{
    int no;
   
    do{
        printf(" \n Enter the function to be executed : \n \n 0 --> Exit \n 1 --> State Trnasition Function \n 2 --> Array Linked List Function \n 3 --> Utility Function \n 4 --> Count Words Function \n ");
        scanf("%d", &no);
    	switch(no)
    	{
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
        	    printf("\n EXITED FROM THE MAIN FUNCTION \n\n");
        	    exit(0);
        	default :
        	    printf("\n Invalid Input \n\n");
        	    exit(0);
    	}
    }while(no != 0);
}


