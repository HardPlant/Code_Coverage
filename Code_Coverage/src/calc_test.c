/*
 * calc_test.c
 *
 *  Created on: 2019. 4. 8.
 *      Author: tta
 */

#include "calc_test.h"
#include "CUnit/Cunit.h"
#include "CUnit/TestDB.h"

static CALC* g_calc;

CU_InitializeFunc test_calc_startup() {
	g_calc = CALC_INIT();
	g_calc->current_status = 0;

	return 0;
}

CU_CleanupFunc test_calc_cleanup() {
	CALC_DEST(g_calc);

	return 0;
}

void test_calc_init() {

	CU_TestInfo test_calc[] = {
		{"smoketest_cutest", smoketest_cutest},
		{"smoketest_calc", smoketest_calc},
		{"test_calc_create", test_calc_create},
		{"test_calc_add", test_calc_add},
		{"test_calc_sub", test_calc_sub},
		{"test_calc_mul", test_calc_mul},
		{"test_calc_div_1", test_calc_div_1},
		{"test_calc_div_2", test_calc_div_2},
		{"test_calc_save", test_calc_save},

		CU_TEST_INFO_NULL,
	};

	CU_SuiteInfo suites[] = {
		{ "[CALC Test]", test_calc_startup, test_calc_cleanup, test_calc},
		CU_SUITE_INFO_NULL,
	};

	CU_register_suites(suites);
}

void smoketest_cutest() {
	char* str = "str";
	CU_ASSERT_STRING_EQUAL(str, "str");
}

void smoketest_calc() {
	printf("Hello!\n");

	CALC* calc = CALC_INIT();
	int success = 0;
	int fail = 0;
	printf("%d\n", CALC_add(calc, 10));
	printf("%d\n", CALC_sub(calc, 5));
	printf("%d\n", CALC_mul(calc, 5));
	printf("%d\n", CALC_div(calc, 2));

	if (CALC_div(calc, 2) == 4) {

		printf("success");
		success++;

	} else {

		printf("fail");
		fail++;
	}

	CALC_DEST(calc);
}

void test_calc_create() {
	CU_ASSERT_PTR_NOT_NULL(g_calc);

	CALC_DEST(g_calc);
	CU_ASSERT_PTR_NULL(g_calc);
}

void test_calc_add() {

	CU_ASSERT_EQUAL(g_calc->current_status, 0);

	CALC_add(g_calc, 10);

	CU_ASSERT_EQUAL(g_calc->current_status, 10);

}

void test_calc_sub() {
	g_calc->current_status = 0;

	CALC_sub(g_calc, 5);

	CU_ASSERT_EQUAL(g_calc->current_status, -5);

}

void test_calc_mul() {

	g_calc->current_status = 5;

	CALC_mul(g_calc, 5);

	CU_ASSERT_EQUAL(g_calc->current_status, 25);

}

void test_calc_div_1() {
	g_calc->current_status = 10;

	CALC_div(g_calc, 2);

	CU_ASSERT_EQUAL(g_calc->current_status, 5);

}

void test_calc_div_2() {
	g_calc->current_status = 10;

	CALC_div(g_calc, 0);

	CU_ASSERT_EQUAL(g_calc->current_status, 10);

}


void test_calc_save() {
	g_calc->current_status = 10;

	CALC_save(g_calc);

	CU_ASSERT_EQUAL(g_calc->saved_status, 10);

	g_calc->current_status = 20;

	CALC_load(g_calc);

	CU_ASSERT_EQUAL(g_calc->current_status, 10);

}

void test_calc_pow() {

	g_calc->current_status = 10;

	CALC_pow(g_calc, 2);

	CU_ASSERT_EQUAL(g_calc->current_status, 100);
}

void test_calc_mod() {
	g_calc->current_status = 10;

	CALC_mod(g_calc, 5);

	CU_ASSERT_EQUAL(g_calc->current_status, 0);

	g_calc->current_status = 11;

	CALC_mod(g_calc, 5);

	CU_ASSERT_EQUAL(g_calc->current_status, 1);
}

void test_calc_is_over_42_1() {
	int i;

	for (i = 0 ; i < 21 ; i++) {
		CALC_add(g_calc, 2);

		if (i != 20 ) {
			CU_ASSERT_FALSE(CALC_is_over_42(g_calc));
		}
	}

	CU_ASSERT_TRUE(CALC_is_over_42(g_calc));
}
