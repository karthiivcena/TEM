C_COMPILER = gcc
CPP_COMPILER = g++
CMPLN_FLAGS = -g -Wall -fPIC -I. -c

all: shared_lib static_lib elf_exec_using_lib regular_elf_exec elf_exec_using_static_lib elf_exec_using_shared_lib

create_rel_obj: 
	$(C_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ state_trans.c -o state_trans.o
	$(C_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ array_linkedlist.c -o array_linkedlist.o
	$(C_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ utility.c -o utility.o
	$(C_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ count_words.c -o count_words.o
	$(C_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ valist_test.c -o valist_test.o
	$(C_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ fn_stack.frame_test.c -o fn_stack.o
	$(C_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ sort_bin.c -o sort_bin.o
	
regular_elf_exec: array_linkedlist.h Cpp.h utility.h
	$(C_COMPILER) -I. -g state_trans.o array_linkedlist.o utility.o count_words.o valist_test.o fn_stack.o sort_bin.o pool_test_main.c -o main_test
	
static_lib: create_rel_obj 
	ar -rc my_test_static_lib.a state_trans.o array_linkedlist.o utility.o count_words.o valist_test.o fn_stack.o sort_bin.o 

shared_lib: create_rel_obj
	$(CPP_COMPILER) -shared -o libmy_test_shared_lib.so state_trans.o array_linkedlist.o utility.o count_words.o valist_test.o fn_stack.o sort_bin.o   
	
elf_exec_using_static_lib: static_lib	
	$(CPP_COMPILER) maintest -L. -lMyTestStaticLib -o maintestwstaticlib
	$(CPP_COMPILER) #maintest my_test_static_lib.a -o maintestwstaticlib

elf_exec_using_shared_lib: shared_lib
	$(CPP_COMPILER) maintest -L. -lmy_test_shared_lib -o maintestwsharedlib
	

clean:
	rm *.o
	rm *.so
	rm *.a
