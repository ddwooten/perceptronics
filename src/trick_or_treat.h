/** 
  * Workhorse class of the programming challenge.
  * Handles input file reading and problem setup, problem solution, and answer
  * reporting. In respective order...
  * @see read_input(char* input_file)
  * @see find_path()
  * @see report()
  */

class trick_or_treat
{

	private:

		int block_size = 0;/** Size of array chunk per thread.*/

		int candy_limit = 0; /** Maximum candy limit from input. */
	        
		int cur_candy = 0; /** Forward sliding window sum value. */
	     
		int i = 0; /** Standard iterator. */  

		int num_houses=0;/** Number of houses in input from input. */
	        
		int num_threads = 0; /** Number of total program threads. */
	      
		int prev_end =0; /** Lagged sliding window end index. */
		
		int prev_max = 0; /** Lagged sliding window sum value. */
		
		int prev_start = 0; /** Lagged sliding window start index. */
	        
		int route_end = 0; /** Forward sliding window end value. */
		
		int thread_end = 0; /** Upper limit of given thread's range. */
	         
		int thread_num = 0; /** Thread id number. */
		
		int thread_start = 0; /** Lower limit of given thread range. */

		int trick_or_treat_end = 0; /** Optimal end house. */

		int trick_or_treat_haul = 0; /** Optimal candy reward. */
		
		int trick_or_treat_start = 0; /** Optimal beginning house. */

		int *houses; /** Map of houses and candy values. */
		    
		int *thread_answers; /** Answer storage for each thread. */

		std::fstream in_file; /** Input file stream. */

	public:

		/** 
		  * Initializer for the trick_or_treat class.
		  * @see trick_or_treat
		  * Get system thread information and allocate storage for
		  * thread answers */

		trick_or_treat();

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
		  * This function is the workhorse of the trick_or_treat class.
		  * The bulk of the function is parallelized with a scheme in 
		  * which the input array, *houses, is split up into equal 
		  * sized chunks per thread with the final thread taking any
		  * remainder. Each thread solves its own portion of the array
		  * advancing until it sees the end of the array or the
		  * arrival of its own start point at its end point - meaning
		  * the thread has successfully searched its entire domain
		  * from thread_start to thread_end where thread_start is
		  * additionally used as an iterator.
		  * @see trick_or_treat */

		void find_path();

		/** 
		  *Prints to standard out the results of find_path.
		  * @see find_path() */

		void report();

		/** 
		  * Destructor for the trick_or_treat class.
		  * @see trick_or_treat
		  * Frees memory related to *houses and *thread_answers
		  */

		~trick_or_treat();

};
