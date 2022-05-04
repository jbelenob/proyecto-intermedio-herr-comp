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


void fill_matrix(std::vector<long> & data, int seed, double p);
void print_matrix(const std::vector <long> & data);

/*Si hay algun cluster sin clasificar retorna la posición el vector
 * del primer elemento al clasificar de ese cluster. Si no hay entonces retorna .1.
 */
long find_nonclassified_cluster(std::vector <long> & data);
//void classify_clusters(std::vector <long> & data);

int main(int argc, char** argv)
{
  //size va a ser el número de filas o de columnas.
  long size = std::atoi(argv[1]);
  const int SEED = std::atoi(argv[2]);
  const double probability = std::atof(argv[3]);

  std::vector <long> m1(size*size, 0);

  std::cout << find_nonclassified_cluster(m1) << '\n';

  fill_matrix(m1, SEED, probability);

  std::cout << find_nonclassified_cluster(m1) << '\n';

  print_matrix(m1);

  return 0;
}

void fill_matrix(std::vector<long> & data, int seed, double p)
{
  const long size = std::sqrt(data.size());

  std::mt19937 gen(seed);

  //Los sitios ocupados tendrán el numero 1, los no ocupados el 0.
  std::discrete_distribution<> dis({1-p, p});

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

long find_nonclassified_cluster(std::vector <long> & data)
{
  const long total_elements = data.size();
  
  for(long ii = 0; ii < total_elements; ++ii)
    {
      if(data[ii] == 1)
	{
	  return ii;
	}
    }
  return -1;
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
