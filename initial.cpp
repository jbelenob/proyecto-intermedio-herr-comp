#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <random>

/*Nota: Lo primero que se va a hacer ahora será mirar que funciones 
 * de la libreria estandar puedo utilizar.
 * 2. Para la nuevo función de buscar vecinos, lo primero que va 
 * a hacer es buscar el 1, es decir el nuevo cluster.
 */


void fill_matrix(std::vector<long> & data, int seed);
void print_matrix(const std::vector <long> & data);
bool find_nonclassified_cluster(std::vector <long> & data);
//void classify_clusters(std::vector <long> & data);

int main(int argc, char** argv)
{
  //Este va a ser el número de filas o de columnas.
  long size = std::atoi(argv[1]);

  const int SEED = std::atoi(argv[2]);

  std::vector <long> m1(size*size, 0);

  //std::cout << find_nonclassified_cluster(m1) << '\n';

  fill_matrix(m1, SEED);

  //std::cout << find_nonclassified_cluster(m1) << '\n';

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

bool find_nonclassified_cluster(std::vector <long> & data)
{
  long total_elements = data.size();
  
  for(long ii = 0; ii < total_elements; ++ii)
    {
      if(data[ii] == 1)
	{
	  return true;
	}
    }
  return false;
}

/*void classify_clusters(std::vector <long> & data)
{
  //Esto me va indicar si ya se identificaron todos los clusters.
  bool find_new_cluster = true;

  while(find_new_cluster == true)
    {
      
    }
}
*/
