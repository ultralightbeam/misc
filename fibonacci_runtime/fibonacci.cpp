
#include <iostream>
#include <ctime>


int fibonacci_recursive (int n) {

	if (n == 0) return 0;
	else if (n == 1) return 1;
	else return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);

}


int fibonacci_loop (int n) {

	int f_n_2 = 0;
	int f_n_1 = 1;
	int f_n;
	
	if (n == 0) return 0;

	while (n > 1) {
		f_n = f_n_1 + f_n_2;
		f_n_2 = f_n_1;
		f_n_1 = f_n;
		n -= 1;
	}
	return f_n;

}


int main (int argc, char *argv[]) {
	
 	int n = atoi(argv[1]);

	int t_recursive[n];
	int t_loop[n];

    std::cout << "testing run times.." << "\n";
	for (int i = 0; i < n; i++) {
		
		clock_t start = clock();
		fibonacci_recursive(i);
		t_recursive[i] = clock() - start;	

		start = clock();
		fibonacci_loop(i);
		t_loop[i] = clock() - start;

		std::cout << "recursive" << "," << "loop" << "\n";
		std::cout << t_recursive[i] << "," << t_loop[i] << "\n";	
	}

}

