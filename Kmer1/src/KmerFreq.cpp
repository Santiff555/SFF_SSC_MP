/*
 * Metodología de la Programación: Kmer0
 * Curso 2023/2024
 */

/* 
 * File:   KmerFreq.cpp
 * @author Santiago Fernández Fernández <santiff55@correo.ugr.es>
 * @author Santiago Salazar Cano <santyns17@correo.ugr.es>
 *
 * Created on 28 March 2024, 13:58
 */

#include "../include/KmerFreq.h"

KmerFreq::KmerFreq()
{
    _frequency = 0;
    _kmer = Kmer();
}

const Kmer& KmerFreq::getKmer() const
{
    return _kmer;
}

int KmerFreq::getFrequency() const
{
    return _frequency;
}

void KmerFreq::setKmer(const Kmer kmer)
{
    _kmer = kmer;
}

void KmerFreq::setFrequency(const int frequency)
{
    if(frequency < 0)
    {
        throw std::out_of_range ("Frequency out of range");
    }
    
    _frequency = frequency;
}

std::string KmerFreq::toString() const
{
    std::string kmerFreqToString = "";
    kmerFreqToString = _kmer.toString()+ " " + std::to_string(_frequency);
    
    return kmerFreqToString;
}
    