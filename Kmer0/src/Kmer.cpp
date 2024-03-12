/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/** 
 * @file Kmer.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 24 October 2023, 14:00
 */

#include "../include/Kmer.h"
#include <string.h>

Kmer::Kmer(int k)
{
    if(k <= 0)
    {
        throw std::invalid_argument("Input must be a integrer greater that 0 ");
    }
    
    for(int i = 0; i < k; i++)
    {
        _text += MISSING_NUCLEOTIDE;
    }

}

Kmer::Kmer(const std::string& text)
{
    if(text.empty())
    {
        throw std::invalid_argument("Input must be a string with at least one character. ");
    }
    _text = text;
}

Kmer::getK() const
{
    return this->size();
}

Kmer::size() const
{
    return _text.size();
}

std::string Kmer::toString() const
{
    return _text;
}

const char& Kmer::at(int index) const 
{
    if(index < 0 || index >= this->size())
    {
         throw std::out_of_range ("Index out of range");
    }
    return _text.at(index);
}

char& Kmer::at(int index) 
{
    if(index < 0 || index >= this->size())
    {
         throw std::out_of_range ("Index out of range");
    }
    
    return _text.at(index);
}

void Kmer::normalize(const std::string& validNucleotides)
{
    
}

Kmer Kmer::complementary(const std::string& nucleotides, 
         const std::string& complementaryNucleotides) const
{
    Kmer solution = Kmer(this->size());  
    if(nucleotides.size() != complementaryNucleotides.size())
    {
        throw std::invalid_argument("Both strings have to be the same size ");
    }
    
    for(int i = 0; i < this->size(); i++)
    {
        int nucleotidIndex = nucleotides.find(this->at(i));
        if(nucleotidIndex != std::string::npos)
        {
            solution.at(i) = complementaryNucleotides.at(nucleotidIndex);
        }
    }
    
    return solution;
}

bool IsValidNucleotide(char nucleotide, const std::string& validNucleotides)
{
    bool solution = true;
    if(validNucleotides.find(nucleotide) != std::string::npos)
    {
        solution = false;
    }
    
    return solution;
}

void ToLower(Kmer& kmer)
{ 
    for(int i = 0; i<kmer.size(); i++)
    {
        kmer.at(i) = tolower(kmer.at(i));
    }
}

void ToUpper(Kmer& kmer)
{
    for(int i = 0; i<kmer.size(); i++)
    {
        kmer.at(i) = toupper(kmer.at(i));
    }   
}