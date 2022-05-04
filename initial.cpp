#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <random>

void fill_matrix(std::vector<long> & data, int seed);
void print_matrix(const std::vector <long> & data);

int main(int argc, char** argv)
{
  //size debe ser un numero cuadrado.
  long size = std::atoi(argv[1]);

  const int SEED = std::atoi(argv[2]);

  std::vector <long> m1(size*size, 0);

  fill_matrix(m1, SEED);

  print_matrix(m1);

  return 0;
}

void fill_matrix(std::vector<long> & data, int seed)
{
  const long size = std::sqrt(data.size());

  std::mt19937 gen(seed);

  std::uniform_int_distribution<> dis(0, 1);

for(long ii = 0; ii < size; ii++)
  {
    for(long jj = 0; jj < size; jj++)
    {
      data[ii*size + jj] = dis(gen);
    }
  } 
}

void print_matrix(const std::vector <long> & data)
{
   const long size = std::sqrt(data.size());

for(long ii = 0; ii < size; ii++)
  {
    for(long jj = 0; jj < size; jj++)
    {
      std::cout << data[ii*size + jj] << " ";
    }
    std::cout << '\n';
  } 
}
