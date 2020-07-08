#include "series_calculator.h"

/** 
  * Computes the i-th term of the nilakantha series.
  * @see step(int i)
  */
using namespace std;

class nilakantha_series: public series_calculator
{

	public:

		/** Method which returns the i-th step of the Nilakantha series. */
		double step(int i);

};
