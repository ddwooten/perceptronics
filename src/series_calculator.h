/** 
  * Workhorse class of the programming challenge.
  * Handles input reading and thread management, problem solution, and answer
  * reporting. 
  * @see calculate()
  * @see check_input(char* input)
  */
#include <fstream>
using namespace std;

class series_calculator
{

	public:

		/** Holder for user input.*/
		int terms = 0;

		/** Accumulator. */
		double sum = 0;

		/** Standard iterator. */  
		int i = 0;   

		/** Another standard iterator. */  
		int j = 0;   

		/** Number of threads. */
		int num_threads = 0;

		/** Storage per thread for unique value. */
		double thread_term = 0;

		/** 
		  * Initializer for the series_calculator class.
		  * Gets system thread information. */
		series_calculator();

		/** 
		  * Manages threads and computes series terms. 
		  * calculate is a thread aware method which
		  * seeks to compute the n terms of the Nilakantha
		  * series where n is gotten from user input.
		  * calculate seeks to use as many threads as the
		  * system will make available. Threads execute
		  * their calculations in parrallel and subsequently
		  * loop over themselves to return and report the
		  * value calculated by each thread. While looping
		  * for report and update takes more compute time
		  * it uses less memory, and no dynamically allocated
		  * memory, as opposed to a method in which each
		  * thread simply stored their value and the master
		  * thread dealt with the subsequent integration.
		  * Most environments are memory bound but should this
		  * algorithm be deployed in a compute bound environment
		  * thread reporting should be shifted from loops to
		  * writes.*/
		void calculate();

		/** Checks user input.
		  * Returns 1 for good input and returns 0 for bad input. */
		int check_input(char* input);

		/** Virtual function which provides i-th step of arbitrary series. 
		  * This virtual function is a place holder intended to allow
		  * polymorphic deployment of derived classes holding step
		  * functions for arbitrary sequences, such as the 
		  * Nilakantha series. */
		virtual double step(int i);

};
