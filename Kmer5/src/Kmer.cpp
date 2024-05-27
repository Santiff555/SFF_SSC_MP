/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/** 
 * @file Kmer.cpp
 * @author Santiago Fernández Fernández <santiff55@correo.ugr.es>
 * @author Santiago Salazar Cano <santyns17@correo.ugr.es>
 *
 * Created on 28 March 2024, 13:58
 */

#include "../include/Kmer.h"
#include <string.h>
#include <cctype>

Kmer::Kmer(int k)
{
    if(k <= 0)
    {
        throw std::invalid_argument("Input must be a integrer greater that 0 ");
    }
    
    this->_text = std::string(k, MISSING_NUCLEOTIDE);

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
    ToUpper(*this);
    for (int i = 0 ; i < this->size() ; i++){
        if (!IsValidNucleotide(this->at(i), validNucleotides)){
            this->at(i) = MISSING_NUCLEOTIDE;
        }
    }
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
    
    ToLower(solution); //Sale en el video
    
    return solution;
}

void Kmer::write(std::ostream& outputStream) const {
    outputStream.write(_text.c_str(), _text.size());
}

void Kmer::read(std::istream& inputStream) {
    inputStream >> _text;
}

bool IsValidNucleotide(char nucleotide, const std::string& validNucleotides)
{
    bool solution = true;
    if(validNucleotides.find(nucleotide) == std::string::npos)
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

std::ostream& operator<<(std::ostream& os, const Kmer& kmer) {
    kmer.write(os);
    return os;
}

std::istream& operator>>(std::istream& is, Kmer& kmer) {
    kmer.read(is);
    return is;
}