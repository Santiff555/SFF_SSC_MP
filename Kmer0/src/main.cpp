/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/* 
 * File:   main.cpp
 * @author Santiago Fernández Fernández <santiff55@correo.ugr.es>
 * @author Santiago Salazar Cano <santyns17@correo.ugr.es>
 *
 * Created on 8 March 2024, 13:58
 */

#include <iostream>
#include <fstream>
#include <string>

#include "../include/Kmer.h"

using namespace std;

/**
 * This program first reads from the standard input an integer k (length of Kmer)
 * and a string with a genetic sequence. Then, it obtains from the genetic 
 * sequence, the list of kmers (of length k) and saves them in the array kmers. 
 * Then, the kmers are normalized. After that, the complementary kmers, 
 * converted to lowercase, are saved in the array complementaryKmers. Finally 
 * the kmers in the arrays kmers and complementaryKmers are shown in the 
 * standard output.
 * See the next example:
 * 
 * Running example:
 * > kmer0 < data/easyDNA2_missing.k0in
 * > kmer0 < data/easyDNA3.k0in
 * > kmer0 < data/easyDNA5.k0in
 * > kmer0 < data/easyDNA5_missing.k0in
 * > kmer0 < data/simpleDNA5.k0in
6
GCGCC<-->cgcgg
CGCCC<-->gcggg
GCCC_<-->cggg_
CCC_G<-->ggg_c
CC_G_<-->gg_c_
C_G_G<-->g_c_c
 */


int main() {
    // This string contains the list of nucleotides that are considered as
    // valid within a genetic sequence. The rest of characters are considered as
    // unknown nucleotides 
    const string VALID_NUCLEOTIDES = "ACGT";
    
    // This string contains the list of complementary nucleotides for each
    // nucleotide in validNucleotides
    const string COMPLEMENTARY_NUCLEOTIDES = "TGCA";

    // This is a constant with the dimension of the array kmers
    const int DIM_ARRAY_KMERS = 100;
    
    // This is the array where the kmers of the input genetic sequence will be
    // saved
    Kmer kmers[DIM_ARRAY_KMERS];
    
    // This is the array where the complementary kmers will be
    // saved
    Kmer complementaryKmers[DIM_ARRAY_KMERS];
    
    // Read K (integer) and a string with the input nucleotides list
    int k = 0;
    string genome = string();
    
    string inputFileName = "";
    std::cin >> inputFileName;
    ifstream inputFile(inputFileName.c_str(), ios::in);    
    
    if (!inputFile.is_open())
    {
        cout << "Error trying to open the file: "<<inputFileName<<std::endl;
        exit(EXIT_FAILURE);
    }
    
    inputFile>>k;
    
    char aCharToAdd;
    while (inputFile>>aCharToAdd)
    {
        genome.push_back(aCharToAdd);
    }
    // Obtain the kmers: find the kmers in the input string and put them in an array of Kmers
    
    int utils = 0;
    for(int i = 0; (i <= genome.length()-k) && (i < DIM_ARRAY_KMERS); i++)
    {
        string kmer_str = genome.substr(i, k);
        
        Kmer kmer(kmer_str);
        
        kmers[i] = kmer;
        utils++;
        
    }
    // Normalize each Kmer in the array
    for(int i = 0; i < utils; i++)
    {
        kmers[i].normalize(VALID_NUCLEOTIDES); 
    }
    
    // Obtain the complementary kmers and turn them into lowercase
    for(int i = 0; i < utils; i++)
    {
        complementaryKmers[i] = kmers[i].complementary(VALID_NUCLEOTIDES, COMPLEMENTARY_NUCLEOTIDES); 
    }

    // Show the list of kmers and complementary kmers as in the example
    cout << utils << endl;
    for(int i = 0; i < utils; i++)
    {
        cout<<kmers[i].toString()<<"<->"<<complementaryKmers[i].toString()<<endl;
    }
    
    
}

