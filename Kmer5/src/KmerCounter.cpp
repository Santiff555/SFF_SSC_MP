/*
 * Metodología de la Programación: Kmer5
 * Curso 2023/2024
 */

/** 
 * @file KmerCounter.cpp
 * @author Santiago Fernández Fernández <santiff55@correo.ugr.es>
 * @author Santiago Salazar Cano <santyns17@correo.ugr.es>
 *
 * Created on 28 March 2024, 13:58
 */

#include "../include/KmerCounter.h"

#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;

/**
 * DEFAULT_VALID_NUCLEOTIDES is a c-string that contains the set of characters
 * that will be considered as valid nucleotides. 

 * The constructor of the class KmerCounter uses this c-string as a 
 * default parameter. It is possible to use a different c-string if that
 * constructor is used with a different c-string
 */
const char* const KmerCounter::DEFAULT_VALID_NUCLEOTIDES="ACGT";

KmerCounter::KmerCounter(int k, std::string validNucleotides) 
    : _k(k), _validNucleotides(validNucleotides), _allNucleotides(Kmer::MISSING_NUCLEOTIDE + validNucleotides) {
    initFrequencies();
}

KmerCounter::KmerCounter(const KmerCounter& orig) 
    : _k(orig._k), _validNucleotides(orig._validNucleotides), _allNucleotides(orig._allNucleotides) {
    initFrequencies();
    for (int i = 0; i < getNumRows(); ++i) {
        for (int j = 0; j < getNumCols(); ++j) {
            _frequency[i][j] = orig._frequency[i][j];
        }
    }
}

KmerCounter::~KmerCounter() {
    for (int i = 0; i < getNumRows(); ++i) {
        delete[] _frequency[i];
    }
    delete[] _frequency;
}

int KmerCounter::getNumNucleotides() const {
    return _allNucleotides.size();
}

int KmerCounter::getK() const {
    return _k;
}

int KmerCounter::getNumKmers() const {
    return std::pow(getNumNucleotides(), _k);
}

int KmerCounter::getNumberActiveKmers() const {
    int count = 0;
    for (int i = 0; i < getNumRows(); ++i) {
        for (int j = 0; j < getNumCols(); ++j) {
            if (_frequency[i][j] > 0) {
                ++count;
            }
        }
    }
    return count;
}

string KmerCounter::toString() const{
    string outputString = _allNucleotides + " " + to_string(_k) + "\n";
    
    for(int row=0; row<this->getNumRows(); row++){
        for(int col=0; col<this->getNumCols(); col++){
            outputString += to_string((*this)(row,col)) + " ";
        }
        outputString += "\n";
    }
    
    return outputString;
}

void KmerCounter::increaseFrequency(const Kmer& kmer, int frequency) {
    int row, column;
    getRowColumn(kmer, row, column);
    if (row != -1 && column != -1) {
        _frequency[row][column] += frequency;
    } else {
        std::cerr << "Invalid kmer: " << kmer.toString() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void KmerCounter::calculateFrequencies(const char* fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }

    initFrequencies();
    std::string line;
    while (std::getline(inputFile, line)) {
        for (size_t i = 0; i + _k <= line.size(); ++i) {
            std::string kmerStr = line.substr(i, _k);
            Kmer kmer(kmerStr);
            kmer.normalize(_validNucleotides);
            increaseFrequency(kmer);
        }
    }
    inputFile.close();
}

Profile KmerCounter::toProfile() const {
    Profile profile;
    for (int i = 0; i < getNumRows(); ++i) {
        for (int j = 0; j < getNumCols(); ++j) {
            if (_frequency[i][j] > 0) {
                Kmer kmer = getKmer(i, j);
                KmerFreq kmerFreq = KmerFreq();
                kmerFreq.setKmer(kmer);
                kmerFreq.setFrequency(_frequency[i][j]);
                profile.append(kmerFreq);
            }
        }
    }
    return profile;
}

int KmerCounter::getNumRows() const {
    return std::pow(getNumNucleotides(), _k / 2 + _k % 2);
}

int KmerCounter::getNumCols() const {
    return std::pow(getNumNucleotides(), _k / 2);
}

int KmerCounter::getIndex(const std::string& kmer) const{
    int index = 0;
    int base = getNumNucleotides();
    for (char nucleotide : kmer) {
        int pos = _allNucleotides.find(nucleotide);
        if (pos == std::string::npos) {
            return -1;
        }
        index = index * base + pos;
    }
    return index;
}

string KmerCounter::getInvertedIndex(int index, int nCharacters) const {
    string kmer(nCharacters, Kmer::MISSING_NUCLEOTIDE);
    int base = getNumNucleotides();
    for (int i = nCharacters - 1; i >= 0; --i) {
        kmer[i] = _allNucleotides[index % base];
        index /= base;
    }
    return kmer;
}

void KmerCounter::getRowColumn(const Kmer& kmer, int& row, int& column) const {
    std::string kmerStr = kmer.toString();
    std::string rowStr = kmerStr.substr(0, _k / 2 + _k % 2);
    std::string colStr = kmerStr.substr(_k / 2 + _k % 2);
    row = getIndex(rowStr);
    column = getIndex(colStr);
}

Kmer KmerCounter::getKmer(int row, int column) const {
    std::string rowStr = getInvertedIndex(row, _k / 2 + _k % 2);
    std::string colStr = getInvertedIndex(column, _k / 2);
    return Kmer(rowStr + colStr);
}

void KmerCounter::initFrequencies() {
    _frequency = new int*[getNumRows()];
    for (int i = 0; i < getNumRows(); ++i) {
        _frequency[i] = new int[getNumCols()];
        std::fill(_frequency[i], _frequency[i] + getNumCols(), 0);
    }
}

const int& KmerCounter::operator()(int row, int column) const {
    return _frequency[row][column];
}

int& KmerCounter::operator()(int row, int column) {
    return _frequency[row][column];
}




