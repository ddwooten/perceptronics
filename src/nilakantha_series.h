/** 
  * Workhorse class of the programming challenge.
  * Handles input file reading and problem setup, problem solution, and answer
  * reporting. In respective order...
  * @see read_input(char* input_file)
  * @see find_path()
  * @see report()
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

		/** Accumulator for positive terms. */
		double positive_sum = 0;

		/** Accumulator for negative terms. */
		double neagative_sum = 0;

		/** Final accumulator. */
		double sum = 0;

		/** Standard iterator. */  
		int i = 0;   

		/** Another standard iterator. */  
		int j = 0;   

		/** Size of array chunk per thread.*/
		int block_size = 0;

		/** Maximum candy limit from input. */
		int candy_limit = 0;
	        
		/** Forward sliding window sum value. */
		int cur_candy = 0; 
	     
		/** Number of houses in input from input. */
		int num_houses = 0;
	        
		/** Number of total program threads. */
		int num_threads = 0;
	      
		/** Lagged sliding window end index. */
		int prev_end = 0;
		
		/** Lagged sliding window sum value. */
		int prev_max = 0; 
		
		/** Lagged sliding window start index. */
		int prev_start = 0;
	        
		/** Forward sliding window end value. */
		int route_end = 0; 
		
		/** Upper limit of given thread's range. */
		int thread_end = 0; 
	         
		/** Thread id number. */
		int thread_num = 0;
		
		/** Lower limit of given thread range. */
		int thread_start = 0;

		/** Optimal end house. */
		int nilakantha_series_end = 0;

		/** Optimal candy reward. */
		int nilakantha_series_haul = 0;
		
		/** Optimal beginning house. */
		int nilakantha_series_start = 0;

		/** Map of houses and candy values. */
		int *houses = NULL;
		    
		/** Answer storage for each thread. */
		int *thread_answers = NULL;

		/** Input file stream. */
		fstream in_file;

		/** 
		  * Initializer for the nilakantha_series class.
		  * @see nilakantha_series
		  * Get system thread information and allocate storage for
		  * thread answers */

		nilakantha_series();

		/** 
		  * Reads in input from file input_file.
		  * @param input_file string representing path to input file
		  * input_file is passed by main() with a default argument 
		  * './../input.txt' which can be overridden by passing the
		  * input file path as a command line argument to the calling
		  * of main. */

		void read_input(char* input_file);

		/** Finds the highest candy yield path with the lowest starting
		  * index.
		  * This function is the workhorse of the nilakantha_series class.
		  * The bulk of the function is parallelized with a scheme in 
		  * which the input array, *houses, is split up into equal 
		  * sized chunks per thread with the final thread taking any
		  * remainder. Each thread solves its own portion of the array
		  * advancing until it sees the end of the array or the
		  * arrival of its own start point at its end point - meaning
		  * the thread has successfully searched its entire domain
		  * from thread_start to thread_end where thread_start is
		  * additionally used as an iterator.
		  * @see nilakantha_series */

		void find_path();

		/** 
		  *Prints to standard out the results of find_path.
		  * @see find_path() */

		void report();

		/** 
		  * Destructor for the nilakantha_series class.
		  * @see nilakantha_series
		  * Frees memory related to *houses and *thread_answers
		  */

		~nilakantha_series();

};
