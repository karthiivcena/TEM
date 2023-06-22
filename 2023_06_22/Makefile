main_test: utility.h array_linkedlist.h
	gcc -g -DRELOCATABLE_OBJ -I. -c count_words.c -o count_words.out
	gcc -g -DRELOCATABLE_OBJ -I. -c utility.c -o utility.out
	gcc -g -DRELOCATABLE_OBJ -I. -c array_linkedlist.c -o array_ll.out
	gcc -g -DRELOCATABLE_OBJ -I. -c state_trans.c -o state_trans.out
	gcc -I. -g count_words.out utility.out array_ll.out state_trans.out pool_test_main.c -o main_test

clean:
	rm main_test count_words.out utility.out array_ll.out state_trans.out
