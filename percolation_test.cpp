#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch2/catch.hpp"

#include "percolation_problem.h"

TEST_CASE( "Se prueban las funciónes que detectan clusters y que calcula el tamaño del cluster percolante más grande", "[clusters]" ) {

  SECTION("detectar clusters percolantes") {

    long size1 = 4;
    long size2 = 5;
    long size3 = 10;
    long size4 = 17;
    long size5 = 8;

    std::vector<long> m1 (size1*size1, 0);
    std::vector<long> m2 (size2*size2, 0);
    std::vector<long> m3 (size3*size3, 0);
    std::vector<long> m4 (size4*size4, 0);
    std::vector<long> m5 (size5*size5, 0);

    std::vector<long> m6 {1,0,0,0,1,0,0,0,1};
    std::vector<long> m7 {0,1,1,0};

    const long rows_columns_filled_m3 = 1;
    const long rows_columns_filled_m4 = 3;
    const long rows_columns_filled_m5 = 2;
    

    //Llena matriz de 1's.
    std::fill(m1.begin(), m1.end(), 1);


     //Llena matriz de 0's.
    std::fill(m2.begin(), m2.end(), 0);

    //Llena solo la primera fila de 1's.
    for(int ii = 0; ii < rows_columns_filled_m3*size3; ++ii)
      {
	m3[ii] = 1;
      }

    //Llena las 3 primeras filas con 1's
    for(int ii = 0; ii < rows_columns_filled_m4*size4; ++ii)
      {
	m4[ii] = 1;
      }

    //Llena la 2 primeras columnas con 1's
    for(int ii = 0; ii < size5; ++ii)
      {
	for(int jj = 0; jj < rows_columns_filled_m5; ++jj)
	  {
	    m5[ii*size5 + jj] = 1;
	  }
	  //m5[ii*size5] = 1;
	  //m5[ii*size5 + 1] = 1;
      }
    
        REQUIRE(is_there_a_percolating(m1) == true);
	REQUIRE(is_there_a_percolating(m2) == false);
	REQUIRE(is_there_a_percolating(m3) == true);
	REQUIRE(is_there_a_percolating(m4) == true);
	REQUIRE(is_there_a_percolating(m5) == true);
	REQUIRE(is_there_a_percolating(m6) == false);
	REQUIRE(is_there_a_percolating(m7) == false);
    }
    SECTION( "Se prueba la función que calcula el tamaño del cluster percolante más grande" ) {

      REQUIRE( largest_percolating_cluster_size(m1) == size1*size1);
      REQUIRE( largest_percolating_cluster_size(m2) == 0);
      REQUIRE( largest_percolating_cluster_size(m3) == rows_columns_filled_m3*size3);
      REQUIRE( largest_percolating_cluster_size(m4) == rows_columns_filled_m4*size4);
      REQUIRE( largest_percolating_cluster_size(m5) == rows_columns_filled_m5*size5);
      REQUIRE( largest_percolating_cluster_size(m6) == 0);
      REQUIRE( largest_percolating_cluster_size(m7) == 0);
      
    }
}

