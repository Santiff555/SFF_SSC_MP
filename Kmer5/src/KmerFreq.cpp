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

void KmerFreq::setKmer(const Kmer& kmer) {
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

void KmerFreq::write(std::ostream& outputStream) const {
    _kmer.write(outputStream);
    outputStream << " " << _frequency << " ";
}

void KmerFreq::read(std::istream& inputStream) {
    _kmer.read(inputStream);
    inputStream >> _frequency;
}

std::ostream& operator<<(std::ostream& os, const KmerFreq& kmerFreq) {
    kmerFreq.write(os);
    return os;
}

std::istream& operator>>(std::istream& is, KmerFreq& kmerFreq) {
    kmerFreq.read(is);
    return is;
}

bool operator>(const KmerFreq& kmerFreq1, const KmerFreq& kmerFreq2) {
    if (kmerFreq1.getFrequency() > kmerFreq2.getFrequency()) {
        return true;
    } else if (kmerFreq1.getFrequency() == kmerFreq2.getFrequency()) {
        return kmerFreq1.getKmer().toString() < kmerFreq2.getKmer().toString();
    }
    return false;
}

bool operator<(const KmerFreq& kmerFreq1, const KmerFreq& kmerFreq2) {
    return kmerFreq2 > kmerFreq1;
}

bool operator==(const KmerFreq& kmerFreq1, const KmerFreq& kmerFreq2) {
    return kmerFreq1.getFrequency() == kmerFreq2.getFrequency() &&
           kmerFreq1.getKmer().toString() == kmerFreq2.getKmer().toString();
}

bool operator!=(const KmerFreq& kmerFreq1, const KmerFreq& kmerFreq2) {
    return !(kmerFreq1 == kmerFreq2);
}

bool operator<=(const KmerFreq& kmerFreq1, const KmerFreq& kmerFreq2) {
    return !(kmerFreq1 > kmerFreq2);
}

bool operator>=(const KmerFreq& kmerFreq1, const KmerFreq& kmerFreq2) {
    return !(kmerFreq1 < kmerFreq2);
}
    