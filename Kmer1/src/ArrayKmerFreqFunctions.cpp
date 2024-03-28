/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/* 
 * File:   ArrayKmerFreqFunctions.cpp
 * @author Santiago Fernández Fernández <santiff55@correo.ugr.es>
 * @author Santiago Salazar Cano <santyns17@correo.ugr.es>
 *
 * Created on 28 March 2024, 13:58
 */


#include "../include/ArrayKmerFreqFunctions.h"

void ReadArrayKmerFreq(KmerFreq array[], const int dim, int &nElements)
{
    std::string inputFileName = "";
    std::cin >> inputFileName;
    std::ifstream inputFile(inputFileName.c_str());    
    
    if (!inputFile.is_open())
    {
        std::cout << "Error trying to open the file: "<<inputFileName<<std::endl;
        exit(EXIT_FAILURE);
    }
    
    inputFile>>nElements;
    
    if(nElements > dim)
    {
        nElements = dim;
    }
    else if(nElements < 0)
    {
        nElements = 0;
    }
    
    
    std::string aKmerToAdd;
    int aFreqToAdd;
    int i = 0;

    while (inputFile >> aFreqToAdd && inputFile >> aKmerToAdd && i<nElements)
    {
        array[i].setKmer(Kmer(aKmerToAdd));
        array[i].setFrequency(aFreqToAdd);
        i++;
    }
    
    
   
    
}

void SortArrayKmerFreq(KmerFreq array[], const int nElements)
{
   //Bubble sort
    for (int i = 0; i < nElements - 1; i++){
        for (int j = 0; j < nElements - i - 1; j++) { 
            if(array[i].getFrequency() > array[j].getFrequency()){
                  SwapElementsArrayKmerFreq(array,nElements,i,j);
            }
        }
    }
}

void DeletePosArrayKmerFreq(KmerFreq array[], int &nElements, const int pos)
{
    if(pos<0||pos>(nElements-1))
    {
        throw std::out_of_range ("Pos out of range");
    }
    
    for (int i = pos; i < nElements; ++i)
        array[i] = array[i + 1];
    
    nElements--;
}


void ZipArrayKmerFreq(KmerFreq array[], int &nElements, 
        const bool deleteMissing, const int lowerBound)
{
    for(int i = 0; i<nElements; i++)
    {
        if(array[i].getFrequency() <= lowerBound)
        {
            DeletePosArrayKmerFreq(array,nElements,i);
        }
        
        else if(deleteMissing)
        {
            Kmer kmer = array[i].getKmer();
            bool kmerHasMissing = false;
            
            for(int j = 0; j<kmer.size() || kmerHasMissing; j++)
            {
                if(kmer.at(j) == kmer.MISSING_NUCLEOTIDE){
                    kmerHasMissing == true;
                }
            }
            
            if(kmerHasMissing)
            {
                DeletePosArrayKmerFreq(array,nElements,i);
            }
        }
    }
}

void NormalizeArrayKmerFreq(KmerFreq array[], const int nElements, 
        const std::string validNucleotides){ 
    
    // Loop to traverse and normalize each one of the kmers in array
          // Normalize kmer i
    
    
    // Loop to traverse the kmers in array from position 1 to position nElements-1
          // index = Position of array[i].getKmer() in the subarray that begins
          //         at position 0 and ends at position i-1
          // If array[i].getKmer() was found in the the subarray from 0 to i-1 
               // Accumulate the frequencies of the kmers at positions 
               //    index and i in the kmer at position index
               // Delete from the array, the kmer at position i 
}

void PrintArrayKmerFreq(KmerFreq array[], int nElements)
{
    
}

int FindKmerInArrayKmerFreq(KmerFreq array[], Kmer kmer,
        int initialPos, int finalPos)
{
    return 0;
}

void SwapElementsArrayKmerFreq(KmerFreq array[], int nElements, int first,
                int second)
{
    
}
