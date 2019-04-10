/*
 * main.c
 *
 *  Created on: 2019. 4. 5.
 *      Author: tta
 */

#include <stdio.h>
#include "calc_test.h"
#include "CUnit/Cunit.h"
#include "CUnit/Console.h"

void register_tests() {
	test_calc_init();
}

int main() {

	CU_initialize_registry();

	register_tests();

	CU_console_run_tests();

	CU_cleanup_registry();

	return 0;
}


