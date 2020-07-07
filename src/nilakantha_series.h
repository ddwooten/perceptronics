/** 
  * Workhorse class of the programming challenge.
  * Handles input reading and thread management, problem solution, and answer
  * reporting. 
  * @see calculate()
  * @see check_input(char* input)
  */
#include <fstream>
using namespace std;

class nilakantha_series
{

	public:

		/** First term of the infinite series.*/
		int term_0 = 3;

		/** Static numerator for the Nilakantha series.*/
		int numerator = 4;

		/** Denomenator holder for the Nilakantha series.*/
		int denominator = 0;

		/** First term in the denominator series.*/
		int denom_start = 2;

		/** Lenth of the simple denomintor series.*/
		int denom_depth = 2;

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
		  * Initializer for the nilakantha_series class.
		  * Gets system thread information. */
		nilakantha_series();

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


		/** Deconstructor for the class object.*/
		~nilakantha_series();

};
