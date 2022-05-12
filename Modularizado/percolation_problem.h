#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <random>
#include <algorithm>
#include <chrono>

void fill_matrix(std::vector<long> & data, int seed, double p);
void print_matrix(const std::vector <long> & data);
long find_nonclassified_cluster(std::vector <long> & data);
long cluster_size(const std::vector <long> & data, const long cluster_num);
void classify_clusters(std::vector <long> & data);
void attach_neighbours(std::vector <long> & data, const long N);
bool is_percolating(const std::vector <long> & data, const long cluster_num);
bool is_there_a_percolating(const std::vector <long> & data);
long largest_percolating_cluster_size(const std::vector <long> & data);
long number_of_last_cluster(const std::vector <long> & data);
double compute_mean(const std::vector <double> &data);
double standard_deviation(const std::vector <double> &data, double mean);
void compute_mean_and_standard_deviation_for_percolating_probability(long size, double probability, int reps_per_single_calculation, int number_of_calculations, int seed);
