C_COMPILER = gcc
CPP_COMPILER = g++
CMPLN_FLAGS = -g -Wall -fPIC -I. -c

all: create_rel_obj regular_elf_exec shared_lib static_lib  elf_exec_using_static_lib elf_exec_using_shared_lib

create_rel_obj: 
	$(CPP_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ state_trans.c -o state_trans.o
	$(CPP_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ array_linkedlist.c -o array_linkedlist.o
	$(CPP_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ utility.c -o utility.o
	$(CPP_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ count_words.c -o count_words.o
	$(CPP_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ valist_test.c -o valist_test.o
	$(CPP_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ fn_stack.frame_test.c -o fn_stack.o
	$(CPP_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ sort_bin.c -o sort_bin.o
	$(CPP_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ set_bit.c -o set_bit.o
	$(C_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ bigendian_littleendian.c -o endian.o
	$(CPP_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ opp_concept_test_main.cpp -o oops.o
	$(CPP_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ Byte.cpp -o byte.o
	$(CPP_COMPILER) $(CMPLN_FLAGS) -DRELOCATABLE_OBJ fn_opt_ovld.cpp -o fn_ovl.o
	$(CPP_COMPILER) $(CMPLN_FLAGS) pool_test_main.c -o main.o
	
regular_elf_exec: array_linkedlist.h Cpp.h utility.h
	$(CPP_COMPILER) -I. -g state_trans.o array_linkedlist.o utility.o count_words.o valist_test.o fn_stack.o sort_bin.o set_bit.o endian.o oops.o byte.o fn_ovl.o main.o -o main_test
	
static_lib: create_rel_obj 
	ar -rc libMyTestStatic.a state_trans.o array_linkedlist.o utility.o count_words.o valist_test.o fn_stack.o sort_bin.o set_bit.o endian.o oops.o byte.o fn_ovl.o

shared_lib: create_rel_obj
	$(CPP_COMPILER) -shared -o libMyTestShared.so state_trans.o array_linkedlist.o utility.o count_words.o valist_test.o fn_stack.o sort_bin.o set_bit.o endian.o oops.o byte.o fn_ovl.o
	
elf_exec_using_static_lib: static_lib	
	$(CPP_COMPILER) main.o -L. -lMyTestStatic -o maintestwstaticlib
	#$(CPP_COMPILER)  libMyTestStatic.a -o maintestwstaticlib

elf_exec_using_shared_lib: shared_lib
	$(CPP_COMPILER) main.o -L. -lMyTestShared -o maintestwsharedlib
	
clean:
	rm *.o
	rm *.so
	rm *.a
