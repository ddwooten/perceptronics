class trick_or_treat
{

	public:

		int block_size, candy_limit, cur_candy, i, max_candy; 

		int num_houses, num_threads, prev_end, prev_max, prev_start; 
		
		int route_end, start, thread_end, thread_num, thread_start;

		int trick_or_treat_end,trick_or_treat_haul,trick_or_treat_start;

		int *houses, *thread_answers, *thread_block_sizes;

		std::fstream in_file;

		trick_or_treat();

		void read_input(char* input_file);

		void find_path();

		void report();

		~trick_or_treat();

};
