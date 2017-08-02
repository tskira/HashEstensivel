#ifndef HASHING_H_
#define HASHING_H_

	#include <stdio.h>
	#include <stdlib.h>
	#include <math.h>
	#include "bucket.h"

	int make_address(int, int);
	int op_find(int, ptr_bucket*);
	int op_add(int);
	void bk_split(ptr_bucket);
	void find_new_range(ptr_bucket, int*, int*);
	void dir_inst_bucket(ptr_bucket, int, int);
	void dir_double(void);
	void dir_inst_bucket(bucket*, int, int);
	void abrearq(char*);
	void bk_add_key(bucket*, int);
	void print_directory(void);

#endif
