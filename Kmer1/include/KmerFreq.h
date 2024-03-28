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


#ifndef KMER_FREQ_H
#define KMER_FREQ_H

#include "Kmer.h"

/**
 * @class KmerFreq
 * @brief A pair formed by a Kmer object and a frequency (an int), 
 * that gives the frequency of a Kmer (times it appears) in a genoma.
 */
class KmerFreq {
public:
    /**
     * @brief Base constructor. 
     * It builds a KmerFreq object containing a Kmer with one nucleotide, the
     * unknown nucleotide (Kmer::MISSING_NUCLEOTIDE) and 0 as its frequency
     */
    KmerFreq();

    /**
     * @brief Gets a const reference to the Kmer of this KmerFreq object
     * Query method
     * @return A const reference to the Kmer of this KmerFreq object
     */
    const Kmer& getKmer() const;

    /**
     * @brief Gets the frequency of this KmerFreq object
     * Query method
     * @return The frequency of this KmerFreq object
     */
    int getFrequency() const;

    /**
     * @brief Sets the Kmer of this KmerFreq object.
     * Modifier method
     * @param kmer The new Kmer value for this object. Input parameter
     */
    void setKmer(const Kmer kmer);

    /**
     * @brief Sets the frequency of this KmerFreq object
     * Modifier method
     * @throw std::out_of_range if @p frequency is negative
     * @param frequency the new frequency value for this KmerFreq object. 
     * Input parameter
     */
    void setFrequency(const int frequency);
    
    /**
     * @brief Obtains a string with the string and frequency of the kmer
     * in this object (separated by a whitespace).
     * Query method.
     * @return A string with the nucleotide and frequency of the kmer
     * in this object
     */
    std::string toString() const;
    
private:
    Kmer _kmer; ///< the Kmer object
    int _frequency; ///< the frequency
}; // end class KmerFreq

#endif /* KMER_FREQ_H */



