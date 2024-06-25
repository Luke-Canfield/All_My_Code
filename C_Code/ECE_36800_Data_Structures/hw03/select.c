#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "select.h"

void swap(int* a_n1, int* a_n2) {
	int tmp = *a_n1;
	*a_n1 = *a_n2;
	*a_n2 = tmp;
}

bool is_partition_correct(int const* numbers, size_t num_numbers, size_t new_numbers_0) {
	int pivot_value = numbers[new_numbers_0 - 1];

	for(size_t j = 0; j < new_numbers_0 - 1; j++) {
		if(numbers[j] > pivot_value) {
			return false;
		}
	}
	for(size_t k = new_numbers_0; k < num_numbers; k++) {
		if(numbers[k] <= pivot_value) {
			return false;
		}
	}

	return true;
}

size_t partition(int* numbers, size_t num_numbers) {
	if(num_numbers == 0) {
		return 0; 
	}

	int max_val_low_partition = numbers[num_numbers - 1]; //pivot_value
	size_t num_numbers_0 = 0; //iniital number of values in lower partition

	for(size_t i = 0; i < num_numbers; i++) {
		if(numbers[i] <= max_val_low_partition) {
			swap(&numbers[i],&numbers[num_numbers_0]);
			num_numbers_0++;
		}
	}	

	return num_numbers_0; 
}

int get_kth_smallest(size_t k_0_based, int* numbers, size_t num_numbers) {

	assert(k_0_based < num_numbers);

	if(num_numbers == 1) {
		return numbers[0];
	}

	size_t num_numbers_0 = partition(numbers, num_numbers);

	if(k_0_based == num_numbers_0 - 1) {
		return numbers[k_0_based];
	}
	else if(k_0_based < num_numbers_0 - 1) {
		return get_kth_smallest(k_0_based, numbers, num_numbers_0 - 1);
	}
	else {
		return get_kth_smallest(k_0_based, numbers + num_numbers_0 + 1, num_numbers - num_numbers_0 - 1);
	}

}

#define SELECT_C_V2  // Do not delete or modify this line.  It helps us track any updates.
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
