#include <stdio.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <omp.h>
#include "nilakantha_series.h"

using namespace std;

void nilakantha_series::step(int i)
{

	/* The first term is unique, return if needed */

	if(i == 0)
	{

		return(3.0);

	}

	/* Otherwise, begin calculating the return value */

	double nilakantha_term = 4.0 / (double)((i * 2) * (i * 2 + 1) * (i * 2 + 2));

	/* If the term is a negative term in the series, make it so */

	if(i % 2 == 0)
	{

		nilakantha_term = nilakantha_term * -1.0;

	}

	return(nilakantha_term);

}
