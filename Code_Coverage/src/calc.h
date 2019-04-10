/*
 * calc.h
 *
 *  Created on: 2019. 4. 5.
 *      Author: tta
 */

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#ifndef CALC_H_
#define CALC_H_

typedef struct CALC{
	int current_status;
	int saved_status;
}CALC;

CALC* CALC_INIT();

int CALC_add(CALC* calc, int num);
int CALC_sub(CALC* calc, int num);
int CALC_mul(CALC* calc, int num);
int CALC_div(CALC* calc, int num);
int CALC_save(CALC* calc);
int CALC_load(CALC* calc);
int CALC_pow(CALC* calc, int exp);

int CALC_mod(CALC* calc, int mod);
int CALC_is_over_42(CALC* calc);
void CALC_DEST(CALC* calc);

#endif /* CALC_H_ */
