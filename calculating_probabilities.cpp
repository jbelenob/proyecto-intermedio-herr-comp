#include "percolation_problem.h"

int main(int argc, char** argv)
{ 
  //size va a ser el número de filas o de columnas.
  const long SIZE = std::atol(argv[1]);
  int SEED = std::atoi(argv[2]);
  //const double probability = std::atof(argv[3]);

  //Se repite este número de veces para calcular 1 vez.
  const int REPS_PER_1_CALCULATION = std::atoi(argv[3]);

  //Este es el número de veces que se calcula la probabilidad.
  const int GROUPS_OF_CALCULATIONS = std::atoi(argv[4]);
  
  std::mt19937 gen(SEED);

  //Este será el generador de las probabilidades
  std::uniform_real_distribution<double> probs1(0.55, 0.65);

  int different_probabilities_to_test = 10;

  double fill_probability = 0.0;

  for(int kk = 0; kk < different_probabilities_to_test; ++kk)
    {

      fill_probability = probs1(gen);

      compute_mean_and_standard_deviation_for_percolating_probability(SIZE, fill_probability, REPS_PER_1_CALCULATION, GROUPS_OF_CALCULATIONS, SEED);
    }

  std::uniform_real_distribution<double> probs2(0.0, 1.0);

  different_probabilities_to_test = 20;

   for(int jj = 0; jj < different_probabilities_to_test; ++jj)
    {
      fill_probability = probs2(gen);

      compute_mean_and_standard_deviation_for_percolating_probability(SIZE, fill_probability, REPS_PER_1_CALCULATION, GROUPS_OF_CALCULATIONS, SEED);
    }
   
  return 0;
}

