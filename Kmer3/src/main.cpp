/*
 * Metodología de la Programación: Kmer3
 * Curso 2023/2024
 */

/**
 * @file main.cpp
 * @author Santiago Fernández Fernández <santiff55@correo.ugr.es>
 * @author Santiago Salazar Cano <santyns17@correo.ugr.es>
 *
 * Created on 20 April 2024, 13:58
 */

#include <iostream>

#include "../include/Profile.h"

using namespace std;


/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc) 
 */
void showEnglishHelp(ostream& outputStream) {
    outputStream << "ERROR in Kmer3 parameters" << endl;
    outputStream << "Run with the following parameters:" << endl;
    outputStream << "kmer3 [-t min|max] <file1.prf> <file2.prf> [ ... <filen.prf>]" << endl;
    outputStream << endl;
    outputStream << "Parameters:" << endl;
    outputStream << "-t min | -t max: search for minimun distances or maximum distances (-t min by default)" << endl;
    outputStream << "<file1.prf>: source profile file for computing distances" << endl;
    outputStream << "<file2.prf> [ ... <filen.prf>]: target profile files for computing distances" << endl;  
    outputStream << endl;
    outputStream << "This program computes the distance from profile <file1.prf> to the rest" << endl;
    outputStream << endl;
}

/**
 * This program reads an undefined number of Profile objects from the set of 
 * files passed as parameters to main(). All the Profiles object, except the 
 * first one, must be stored in a dynamic array of Profile objects. Then, 
 * for each Profile in the dynamic array, this program prints to the 
 * standard output the name of the file of that Profile and the distance from 
 * the first Profile to the current Profile. 
 * Finally, the program should print in the standard output, the name of 
 * the file with the Profile with the minimum|maximum  distance to the Profile 
 * of the first file and its profile identifier.
 * 
 * At least, two Profile files are required to run this program.
 * 
 * This program assumes that the profile files are already normalized and 
 * sorted by frequency. This is not checked in this program. Unexpected results
 * will be obtained if those conditions are not met.
 * 
 * Running sintax:
 * > kmer3 [-t min|max] <file1.prf> <file2.prf> [  ... <filen.prf>] 
 * 
 * Running example:
 * > kmer3 ../Genomes/human1.prf ../Genomes/worm1.prf ../Genomes/mouse1.prf 
Distance to ../Genomes/worm1.prf: 0.330618
Distance to ../Genomes/mouse1.prf: 0.224901
Nearest profile file: ../Genomes/mouse1.prf
Identifier of the nearest profile: mus musculus
 * 
 * Running example:
 * > kmer3 -t max ../Genomes/human1.prf ../Genomes/worm1.prf ../Genomes/mouse1.prf 
 * ./dist/debug/MinGw-Windows/kmer4 ../Genomes/human1.prf ../Genomes/worm1.prf ../Genomes/mouse1.prf
Distance to ../Genomes/worm1.prf: 0.330618
Distance to ../Genomes/mouse1.prf: 0.224901
Farthest profile file: ../Genomes/worm1.prf
Identifier of the farthest profile: worm
 */
int main(int argc, char* argv[]) {
    
    // Process the main() arguments
    if(argc < 4)
    {
        showEnglishHelp(cerr);
        return -1;
    }
    
    /*C:\Users\santy\Desktop\MP\Practicas\SFF_SSC_MP\Kmer3\dist\debug\MinGw-Windows\kmer3.exe: 0
     *-t: 1                                                                                     
     *min: 2
     *../Genomes/human1.prf: 3
     *../Genomes/worm1.prf: 4
     *../Genomes/mouse1.prf: 5
     *...
     */
   
    int numberOfProfiles = argc - 1;
    int startOfProfilesFiles = 1;
    
    const string tParameter = "-t";
    const string minParameter = "min", maxParameter = "max";
    string searchParameter = minParameter;
    if(argv[1] == tParameter)
    {
        numberOfProfiles -= 2;
        startOfProfilesFiles = 3;
        if(argv[2] == maxParameter)
        {
            searchParameter = maxParameter;
        }
    }
    // Allocate a dynamic array of Profiles
    Profile* profiles = new Profile[numberOfProfiles];
    
    // Load the input Profiles
    for(int i = 0; i < numberOfProfiles;i++)
    {
        profiles[i].load(argv[i+startOfProfilesFiles]);
    }
    
    // Calculate and print the distance from the first Profile to the rest
    double distance_i = profiles[0].getDistance(profiles[1]);
    cout<<"Distance to "<<argv[startOfProfilesFiles+1]<<": "<<distance_i<<endl;
    
    double maxmin_distance_value = distance_i;
    int maxmin_distance_index = 1;
    
    if(numberOfProfiles > 2)
    {
        for(int i = 2; i < numberOfProfiles; ++i)
        {
            distance_i = profiles[0].getDistance(profiles[i]);
            cout<<"Distance to "<<argv[startOfProfilesFiles+i]<<": "<<distance_i<<endl;

            if(searchParameter == minParameter)
            {
                if(maxmin_distance_value > distance_i)
                {
                    maxmin_distance_value = distance_i;
                    maxmin_distance_index = i;
                }
            }
            else if(searchParameter == maxParameter)
            {
               if(maxmin_distance_value < distance_i)
                {
                    maxmin_distance_value = distance_i;
                    maxmin_distance_index = i;
                }
            }
        }
    }
    // Print name of the file and identifier that takes min|max distance to the first one
    if(searchParameter == maxParameter)
    {
        cout<<"Farthest profile file: ";
    }
    
    if(searchParameter == minParameter)
    {
        cout<<"Nearest profile file: ";
    }
    cout<<argv[startOfProfilesFiles + maxmin_distance_index]<<endl;
    cout<<"Identifier of the farthest profile: "<<profiles[maxmin_distance_index].getProfileId()<<endl;
    
    // Deallocate the dynamic array of Profiles 
    delete[] profiles;
    
    //End of main
    return 0;
}
