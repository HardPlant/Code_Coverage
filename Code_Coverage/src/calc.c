#include "calc.h"

CALC* CALC_INIT() {
	CALC* new_calc = malloc(sizeof(CALC));
	memset(new_calc, 0, sizeof(CALC));

	return new_calc;
}

int CALC_add(CALC* calc, int num) {
	calc->current_status += num;

	return calc->current_status;
}

int CALC_sub(CALC* calc, int num) {
	calc->current_status -= num;

	return calc->current_status;
}

int CALC_mul(CALC* calc, int num) {
	calc->current_status *= num;

	return calc->current_status;
}

int CALC_div(CALC* calc, int num) {
	if (num != 0) {
		calc->current_status /= num;
	} else {
		printf("[CALC_div] Div 0 Error\n");
	}

	return calc->current_status;
}

int CALC_save(CALC* calc) {
	calc->saved_status = calc->current_status;

	return calc->saved_status;
}

int CALC_load(CALC* calc) {
	calc->current_status = calc->saved_status;

	return calc->saved_status;
}

int CALC_pow(CALC* calc, int exp) {
	int temp = calc->current_status;

	for (int i = 1; i < exp; i++) {
		calc->current_status *= temp;
	}

	return calc->current_status;
}

int CALC_mod(CALC* calc, int mod) {
	calc->current_status = calc->current_status % mod;

	return calc->current_status;
}

int CALC_is_over_42(CALC* calc) {
	if (calc->current_status > 42) {
		return 1;
	} else {
		return 0;
	}
}

void CALC_DEST(CALC* calc){

	CALC** calc_addr = &calc;

	memset(calc, 0, sizeof(CALC));

	free(calc);

	*calc_addr = NULL;
}
