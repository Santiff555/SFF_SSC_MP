/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/* 
 * File:   main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 *
 * Created on 24 October 2023, 13:58
 */

#include <iostream>
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
 * > kmer0 < data/easyDNA5_missing.k0in
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
    string nucleotidesList = std::string.empty();
    const char EOF = '0';
    
    string fileName = "";
    std::cin >> fileName;
    ifstream file(fileName.c_str());    
    
    if (!file.is_open())
    {
        cout << "Error trying to open the file: "<<fileName<<std::endl;
        exit(EXIT_FAILURE);
    }
    
    file>>k;
    
    char aCharToAdd;
    while (file>>aCharToAdd && aCharToAdd!=EOF)
    {
        nucleotidesList += aCharToAdd;
    }
    
    // Obtain the kmers: find the kmers in the input string and put them in an array of Kmers
    
    for(int i = 0; i < DIM_ARRAY_KMERS; i++)
    {
        string nucleotidesForKmer = std::string.empty();
        for(int j = i ; j < i+k; j++)
        {
            nucleotidesForKmer += nucleotidesList[j];
        }
     
        kmers[i] = Kmer(nucleotidesForKmer);
    }
    // Normalize each Kmer in the array
    
    //FALTA HACER ESTA PARTE (asignado a: sff)
    
    // Obtain the complementary kmers and turn them into lowercase
    for(int i = 0; i < DIM_ARRAY_KMERS; i++)
    {
        complementaryKmers[i] = kmers[i].complementary(VALID_NUCLEOTIDES, COMPLEMENTARY_NUCLEOTIDES); 
    }

    // Show the list of kmers and complementary kmers as in the example
    
    for(int i = 0; i < DIM_ARRAY_KMERS; i++)
    {
        std::cout<<kmers[i].toString()<<"<->"<<complementaryKmers[i].toString()<<std::endl;
    }
    

}

