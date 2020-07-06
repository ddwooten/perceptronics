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

		void calculate(int user_input);

		~nilakantha_series();

};
