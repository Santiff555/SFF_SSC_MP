#include <iostream>
#include <cstring>

#include "../include/Profile.h"
#include "../include/KmerCounter.h"
/*
 * Metodología de la Programación: Kmer5
 * Curso 2023/2024
 */

/** 
 * @file LEARN.cpp
 * @author Santiago Fernández Fernández <santiff55@correo.ugr.es>
 * @author Santiago Salazar Cano <santyns17@correo.ugr.es>
 *
 * Created on 28 March 2024, 13:58
 */
using namespace std;

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc) 
 */
void showEnglishHelp(ostream& outputStream) {
    outputStream << "ERROR in LEARN parameters" << endl;
    outputStream << "Run with the following parameters:" << endl;
    outputStream << "LEARN [-t|-b] [-k kValue] [-n nucleotidesSet] [-p profileId] [-o outputFilename] <file1.dna> [<file2.dna> <file3.dna> .... ]" << endl;
    outputStream << endl;
    outputStream << "Parameters:" << endl;
    outputStream << "-t|-b: text mode or binary mode for the output file (-t by default)" << endl;
    outputStream << "-k kValue: number of nucleotides in a kmer (5 by default)" << endl;
    outputStream << "-n nucleotidesSet: set of possible nucleotides in a kmer (ACGT by default). " 
                 << "Note that the characters should be provided in uppercase" << endl;
    outputStream << "-p profileId: profile identifier (unknown by default)" << endl;
    outputStream << "-o outputFilename: name of the output file (output.prf by default)" << endl;
    outputStream << "<file1.dna> <file2.dna> <file3.dna> ....: names of the input files (at least one is mandatory)" << endl;
    outputStream << endl;
    outputStream << "This program learns a profile model from a set of "<< 
            "input DNA files <file1.dna> <file2.dna> <file3.dna> ...." << endl;
    outputStream << endl;
}

/**
 * This program learns a Profile model from a set of input DNA files (file1.dna,
 * file2.dna, ...). The learned Profile object is then zipped (kmers with any 
 * missing nucleotide or with frequency equals to zero will be removed) 
 * and ordered by frequency and saved in 
 * the file outputFilename (or output.prf if the output file is not provided).
 * 
 * Running sintax:
 * > LEARN [-t|-b] [-k kValue] [-n nucleotidesSet] [-p profileId] [-o outputFilename] <file1.dna> [<file2.dna> <file3.dna> ....]
 * 
 * Running example:
 * > LEARN -k 2 -p bug -o /tmp/unknownACGT.prf ../Genomes/unknownACGT.dna
 * 
 * > cat /tmp/unknownACGT.prf
MP-KMER-T-1.0
bug
7
GG 2
AC 1
AG 1
AT 1
CC 1
GA 1
TA 1
 * 
 * @param argc The number of command line parameters
 * @param argv The vector of command line parameters (cstrings)
 * @return 0 If there is no error; a value > 0 if error
 */
int main(int argc, char *argv[]) {   
// Process the main() arguments
    // Default values
    char mode = 't';
    int kValue = 5;
    string nucleotidesSet = "ACGT";
    string profileId = "unknown";
    string outputFilename = "output.prf";

    // Parse command line arguments
    int i = 1;
    while (i < argc) {
        if (strcmp(argv[i], "-t") == 0) {
            mode = 't';
        } else if (strcmp(argv[i], "-b") == 0) {
            mode = 'b';
        } else if (strcmp(argv[i], "-k") == 0 && i + 1 < argc) {
            kValue = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            nucleotidesSet = argv[++i];
        } else if (strcmp(argv[i], "-p") == 0 && i + 1 < argc) {
            profileId = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
            outputFilename = argv[++i];
        } else if (argv[i][0] != '-') {
            break;
        } else {
            showEnglishHelp(cerr);
            return 1;
        }
        ++i;
    }

    if (i >= argc) {
        showEnglishHelp(cerr);
        return 1;
    }
    
// Loop to calculate the kmer frecuencies of the input genome files using 
// a KmerCounter object
    
    // Create KmerCounter
    KmerCounter kmerCounter(kValue, nucleotidesSet);

    // Process each input file
    for (; i < argc; ++i) {
        kmerCounter.calculateFrequencies(argv[i]);
    }
    
// Obtain a Profile object from the KmerCounter object
    
    Profile profile = kmerCounter.toProfile();
    // Set the correct profile ID
    profile.setProfileId(profileId);
    
// Zip the Profile object
    profile.zip(true, 0);
// Sort the Profile object
    profile.sort();
// Save the Profile object in the output file
    profile.save(outputFilename.c_str(), mode);
    return 0;
}
