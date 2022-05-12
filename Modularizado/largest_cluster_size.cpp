#include "percolation_problem.h"

int main(int argc, char** argv)
{
  std::cout.precision(16);
  
  //size va a ser el número de filas o de columnas.
  const long SIZE = std::atol(argv[1]);

  //Número de veces que se va a calcular el tamaño maximo.
  const int REPS = std::atoi(argv[2]);

  int seed = std::atoi(argv[3]);
  //const double probability = std::atof(argv[3]);

  std::mt19937 gen(seed);

  //Este será el generador de las probabilidades.
  std::uniform_real_distribution<double> probs1(0.55, 0.65);

  int different_probabilities_to_test = 10;

  double fill_probability = 0.0;

  std::vector <long> m (SIZE*SIZE, 0.0);
  
  std::vector<double> sizes (REPS, 0.0);
  
  for(int kk = 0; kk < different_probabilities_to_test; ++kk)
    {

      fill_probability = probs1(gen);
      
      for(int jj = 0; jj < REPS; ++jj)
	{

	  fill_matrix(m, seed, fill_probability);

	  classify_clusters(m);

	  sizes[jj] = largest_percolating_cluster_size(m)/(1.0*SIZE*SIZE);

	  ++seed;
	}

      double mean_size = compute_mean(sizes);
      double std_dev_size = standard_deviation(sizes, mean_size);

      std::cout << SIZE << '\t' << fill_probability << '\t' <<  mean_size
		<< '\t' << std_dev_size << '\n';
    }

  std::uniform_real_distribution<double> probs2(0.0, 1.0);

  different_probabilities_to_test = 20;

    
  for(int kk = 0; kk < different_probabilities_to_test; ++kk)
    {

      fill_probability = probs2(gen);
      
      for(int jj = 0; jj < REPS; ++jj)
	{

	  fill_matrix(m, seed, fill_probability);

	  classify_clusters(m);

	  sizes[jj] = largest_percolating_cluster_size(m)/(1.0*SIZE*SIZE);

	  ++seed;
	}

      double mean_size = compute_mean(sizes);
      double std_dev_size = standard_deviation(sizes, mean_size);

      std::cout << SIZE << '\t' << fill_probability << '\t' <<  mean_size
		<< '\t' << std_dev_size << '\n';
    }
  
  return 0;
}


