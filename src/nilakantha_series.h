#include "series_calculator.h"

/** 
  * Computes the i-th term of the nilakantha series.
  * @see step(int i)
  */
using namespace std;

/* Inherit from the base class series_calculator */

class nilakantha_series: public series_calculator
{

	public:

		/** Calculation holder. */
		double nilakantha_term = 0;
		
		/** Constructor for the nilakantha_series. */
		nilakantha_series();

		/** Method which returns the i-th step of the Nilakantha series. */
		double step(int i);

};
