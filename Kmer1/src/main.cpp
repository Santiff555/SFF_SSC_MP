/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/* 
 * File:   main.cpp
 * @author Santiago Fernández Fernández <santiff55@correo.ugr.es>
 * @author Santiago Salazar Cano <santyns17@correo.ugr.es>
 *
 * Created on 28 March 2024, 13:58
 */

#include <iostream>
#include <string>

#include "../include/KmerFreq.h"
#include "../include/ArrayKmerFreqFunctions.h"

using namespace std;

/**
 * This program reads from the stardard input, an integer n (number of 
 * elements in the list of pairs kmer-frequency) and a list of n pairs 
 * kmer-frequency. The pairs should be stored in an array (local variable 
 * in main() ), and then each one of the Kmers in the array must be 
 * normalized (all its characters are converted to uppercase
 * and invalid characters are replaced by the MISSING_NUCLEOTIDE character)
 * and zipped (those pairs with a missing nucleotide or with a 
 * frequency less or equals to zero must be deleted from the array). Next, 
 * the array should be sorted in decreasing 
 * order of frequency (if two pairs have the same frequency, the pair with a 
 * minor Kmer should appear first in the array). Finally, the program shows the 
 * array in the standard output. 
 * 
 * Running example:
 * > kmer1 < data/6pairsDNA_missing.k1in
2
CC 3
GC 2
 */
int main(int argc, char* argv[]) {
    // This string contains the list of nucleotides that are considered as
    // valid within a genetic sequence. The rest of characters are considered as
    // unknown nucleotides 
    const string VALID_NUCLEOTIDES = "ACGT";
    
    // This is a constant with the dimension of the array kmers
    const int DIM_ARRAY_KMERS=100;
    
    // This is the array where the kmers read from the standard input 
    // will be stored
    KmerFreq kmers[DIM_ARRAY_KMERS];
    
    int nKmers; // Number of elements in the array kmers

    // Read an integer n (number of pairs to read)
    // Ya lo hace el metodo ReadArrayKmerFreq
    // Read the n pairs kmers-frequency from the standard input and put them 
    //      in the array kmers
    ReadArrayKmerFreq(kmers, DIM_ARRAY_KMERS, nKmers);
    // Normalizes each kmer in the array kmers
    NormalizeArrayKmerFreq(kmers, nKmers, VALID_NUCLEOTIDES);
    // Zip the kmers in the array kmers
    ZipArrayKmerFreq(kmers,nKmers,true);
    // Sort the array kmers
    SortArrayKmerFreq(kmers,nKmers);
    // Print the array kmers in the standard output
    PrintArrayKmerFreq(kmers, nKmers);
    return 0;
}

