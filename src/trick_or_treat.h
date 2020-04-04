class trick_or_treat
{

	public:

		int block_size = 0, candy_limit = 0, cur_candy = 0, i = 0;  

		int max_candy = 0, num_houses = 0, num_threads = 0, prev_end =0;
		
		int prev_max = 0, prev_start = 0, route_end = 0 , start = 0; 
		
		int thread_end = 0, thread_num = 0, thread_start = 0;

		int trick_or_treat_end = 0,trick_or_treat_haul = 0;
		
		int trick_or_treat_start = 0;

		int *houses, *thread_answers; 

		std::fstream in_file;

		trick_or_treat();

		void read_input(char* input_file);

		void find_path();

		void report();

		~trick_or_treat();

};
