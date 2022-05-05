#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <random>
#include <algorithm>

/*Nota: Lo primero que se va a hacer ahora será mirar que funciones 
 * de la libreria estandar puedo utilizar.
 * 2. Para la nuevo función de buscar vecinos, lo primero que va 
 * a hacer es buscar el 1, es decir el nuevo cluster.
 */


void fill_matrix(std::vector<long> & data, int seed, double p);
void print_matrix(const std::vector <long> & data);
long find_nonclassified_cluster(std::vector <long> & data);
long cluster_size(const std::vector <long> & data, const long cluster_num);
void classify_clusters(std::vector <long> & data);
void attach_neighbours(std::vector <long> & data, const long N);

int main(int argc, char** argv)
{
  //size va a ser el número de filas o de columnas.
  const long size = std::atol(argv[1]);
  const int SEED = std::atoi(argv[2]);
  const double probability = std::atof(argv[3]);
  //const long N1 = std::atol(argv[4]);

  std::vector <long> m1(size*size, 0);

  fill_matrix(m1, SEED, probability);

  print_matrix(m1);

  classify_clusters(m1);

  print_matrix(m1);

  return 0;
}

void fill_matrix(std::vector<long> & data, int seed, double p)
{
  const long size = std::sqrt(data.size());

  std::mt19937 gen(seed);

  //Los sitios ocupados tendrán el numero 1, los no ocupados el 0.
  std::discrete_distribution<> dis({1-p, p});

  for(long ii = 0; ii < size; ++ii)
    {
      for(long jj = 0; jj < size; ++jj)
      {
	data[ii*size + jj] = dis(gen);
      }
    } 
}

void print_matrix(const std::vector <long> & data)
{
   const long size = std::sqrt(data.size());

   std::cout << '\n';

   for(long ii = 0; ii < size; ++ii)
     {
       for(long jj = 0; jj < size; ++jj)
	 {
	   std::cout << data[ii*size + jj] << " ";
	 }
       std::cout << '\n';
     } 
}

/*Si hay algun cluster sin clasificar retorna la posición el vector
 * del primer elemento al clasificar de ese cluster. Si no hay entonces retorna -1.
 */
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

long cluster_size(const std::vector <long> & data, const long cluster_num)
{
  return std::count_if(data.begin(), data.end(), [cluster_num](long i){return i == cluster_num;});
}

void classify_clusters(std::vector <long> & data)
{
  /*Esta variable me va indicar si ya se identificaron todos los clusters.
   *Si la variable es mayor que 0 es porque se encontró un nuevo cluster.*/
  long new_cluster_position = find_nonclassified_cluster(data);

  //Esta variable va enumerando los clusters
  long cluster_num = 2; 

  //Esta variable me dirá cuantos pasos he dado para clasificar cierto cluster.
  long step = 0;
  
  while(new_cluster_position >= 0)
    {
      data[new_cluster_position] = cluster_num;

      step = 0;

      //Esta variable me dirá si puedo seguir encontrar nuevos 1's vecinos.
      bool find_new_adjacents = true;

      while(find_new_adjacents == true)
	{ 
	  for(long ii = 0; ii < data.size(); ++ii)
	    {
	      if(data[ii] == (cluster_num + step))
		{
		  attach_neighbours(data, ii);
		}
	    }

	  step = step + 1;
	  
	  if(std::none_of(data.begin(), data.end(), [ &cluster_num,  & step](int i){ return i  == cluster_num + step;}))
	    {
	      find_new_adjacents = false;

	      //Reemplazar todos los números mayores que el número del cluster por el número del cluster.
	      for(long jj = 0; jj < data.size(); ++jj)
		{
		  if(data[jj] > cluster_num)
		    {
		      data[jj] = cluster_num;
		    }
		}
	    }

	  //step = step + 1;	  
	}

      //Se aumenta el número del cluster.
      cluster_num = cluster_num + 1;
      
      //Se busca el nuevo cluster.
      new_cluster_position = find_nonclassified_cluster(data);
      
    }
}


void attach_neighbours(std::vector <long> & data, const long N)
{
  const long size = std::sqrt(data.size());

  //Indica la fila. Note que se trunca.
  const long ii = N/size;

  //Indica la columna. Note que se trunca
  const long jj = N % size;

  auto attach_if_full = [&N, &data](long& a) {
    if(data[a] == 1)
      {
	data[a] = data[N] + 1;
      }
    };

  //Estas variablaes almaceneran las posiciones adjacentes a la posicion N.
  long adj1 = 0;
  long adj2 = 0;
  long adj3 = 0;
  long adj4 = 0;

  //Primero chequearemos si son esquinas
  if(N == 0)
    {
      adj1 = N + 1;
      adj2 = N + size;

      attach_if_full(adj1);
      attach_if_full(adj2);
	
      return;
    }

  if(N == size - 1)
    {
      adj1 = N - 1;
      adj2 = N + size;

      attach_if_full(adj1);
      attach_if_full(adj2);
	
      return;
    }

  if(N == (size)*(size - 1))
    {
      adj1 = N + 1;
      adj2 = N - size;

      attach_if_full(adj1);
      attach_if_full(adj2);
	
      return;
    }

  if(N == (size)*(size) - 1)
    {
      adj1 = N - 1;
      adj2 = N - size;

      attach_if_full(adj1);
      attach_if_full(adj2);
	
      return;
    }

  //Ahora se chequea si esta en la primera o ultima fila;
  if((ii == 0) && (jj != 0) && (jj != (size - 1)))
    {
      adj1 = N - 1;
      adj2 = N + 1;
      adj3 = N + size;

      attach_if_full(adj1);
      attach_if_full(adj2);
      attach_if_full(adj3);
	
      return;
    }

  if((ii == size - 1) && (jj != 0) && (jj != (size - 1)))
    {
      adj1 = N - 1;
      adj2 = N + 1;
      adj3 = N - size;

      attach_if_full(adj1);
      attach_if_full(adj2);
      attach_if_full(adj3);
	
      return;
    }

  //Ahora se chequea si está en la primera o ultima columna

  if((jj == 0) && (ii != 0) && (ii != (size - 1)))
    {
      adj1 = N - size;
      adj2 = N + 1;
      adj3 = N + size;

      attach_if_full(adj1);
      attach_if_full(adj2);
      attach_if_full(adj3);
	
      return;
    }

  if((jj == (size - 1)) && (ii != 0) && (ii != (size - 1)))
    {
      adj1 = N - size;
      adj2 = N - 1;
      adj3 = N + size;

      attach_if_full(adj1);
      attach_if_full(adj2);
      attach_if_full(adj3);
	
      return;
    }

  //Finalmente si no se tiene ninguno de los anteriores casos.
  adj1 = N - size;
  adj2 = N - 1;
  adj3 = N + 1;
  adj4 = N + size;

   attach_if_full(adj1);
   attach_if_full(adj2);
   attach_if_full(adj3);
   attach_if_full(adj4);
}

