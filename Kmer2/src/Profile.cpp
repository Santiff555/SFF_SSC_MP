/*
 * Metodología de la Programación: Kmer2
 * Curso 2023/2024
 */

/** 
 * @file Profile.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 29 January 2023, 11:00
 */


#include "../include/Profile.h"
#include "../include/ArrayKmerFreqFunctions.h"

using namespace std;

const string Profile::MAGIC_STRING_T = "MP-KMER-T-1.0";

Profile::Profile()
{
    setProfileId("unknow");
    _size = 0;
}

Profile:: Profile(const int size)
{
    if(size < 0 || size > getCapacity())
    {
        throw std::out_of_range("Input must be at least 0 and less than " + std::to_string(getCapacity()) );
    }
    
    setProfileId("unknow");
    _size = size;
    
    for(int i = 0; i < getSize(); i++)
    {
        _vectorKmerFreq[i] = KmerFreq();
    }
}

void Profile::setProfileId(const std::string id)
{
    _profileId = id;
}

const KmerFreq& Profile::at(const int index) const
{
    if(index < 0 || index >= getSize())
    {
         throw std::out_of_range ("Index out of range");
    }
    return _vectorKmerFreq[index];
}

KmerFreq& Profile::at(const int index) 
{
    if(index < 0 || index >= getSize())
    {
         throw std::out_of_range ("Index out of range");
    }
    return _vectorKmerFreq[index];
}

int Profile::getSize() const
{
    return _size;
}

int Profile::getCapacity() const
{
    return DIM_VECTOR_KMER_FREQ;
}