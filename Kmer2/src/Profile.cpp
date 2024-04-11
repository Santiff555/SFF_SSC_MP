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

void Profile::sort()
{
    SortArrayKmerFreq(_vectorKmerFreq, getCapacity());
    
    for (int i = 0; i < _size - 1; i++){
        for (int j = i+1; j < _size ; j++) { 
            if(_vectorKmerFreq[i].getKmer().toString() < _vectorKmerFreq[j].getKmer().toString()){ //tal vez esto falle, comprobarlo
                  SwapElementsArrayKmerFreq(_vectorKmerFreq,_size,i,j);
            }
        }
    }
}

void Profile::save(const char fileName[])
{
    std::ifstream inputFile(fileName);    
    
    //Comprobamos si hay algun fallo abriendo el fichero
    if (!inputFile.is_open())
    {
        std::cout << "Error trying to open the file: "<<fileName<<std::endl;
        exit(EXIT_FAILURE);
    }
    
    //Vaciamos el Profile
    *this = Profile(_size);
    
    //Comprobamos que es un fichero de Profile
    string isAProfileFile = "";
    inputFile>>isAProfileFile;
    
    if(isAProfileFile != MAGIC_STRING_T)
    {
        std::cout << "This is not a Profile file"<<std::endl;
        exit(EXIT_FAILURE);
    }
    
    //Obtenemos el id del Profile
    inputFile>>_profileId;
    
    //Obtenemos el numero de kmerFreq en el fichero.
    inputFile>>_size;
    
    if(_size > getCapacity())
    {
        _size = getCapacity();
    }
    else if(_size < 0)
    {
        _size = 0;
    }
    
    //Creamos variables temporales
    std::string aKmerToAdd;
    int aFreqToAdd;
    int i = 0;
    
    //Leemos y guardamos los kmerFreq
    while (inputFile >> aKmerToAdd && inputFile >> aFreqToAdd && i<_size)
    {
        _vectorKmerFreq[i].setKmer(Kmer(aKmerToAdd));
        _vectorKmerFreq[i].setFrequency(aFreqToAdd);
        i++;
    }
}

void Profile::load(const char fileName[])
{
    std::ofstream outputFile(fileName);    
    
    //Comprobamos si hay algun fallo abriendo el fichero
    if (!outputFile.is_open())
    {
        std::cout << "Error trying to open the file: "<<fileName<<std::endl;
        exit(EXIT_FAILURE);
    }
    
    //Indicamos que es un fichero de Profile
    outputFile<<MAGIC_STRING_T;
  
    //Escribimos el id del Profile
    outputFile<<_profileId;
    
    //Escribimos el numero de kmerFreq en el fichero.
    outputFile<<_size;
    
    //Escribimos los kmerFreq
    for(int i = 0; i < getSize(); i++)
    {
        outputFile<<_vectorKmerFreq[i].toString();
    }
}

void Profile::append(const KmerFreq kmerFreq)
{
    if(getSize() + 1 >= getCapacity())
    {
         throw std::out_of_range ("Index out of range");
    }
    
    int kmerFreqPos = findKmer(kmerFreq.getKmer());
    
    if(kmerFreqPos == -1){
        _vectorKmerFreq[getSize()] = kmerFreq;
        _size++;
    }
    else
    {
        _vectorKmerFreq[kmerFreqPos].setFrequency(_vectorKmerFreq[kmerFreqPos].getFrequency() + 1);   
    }
}

void Profile::deletePos(const int pos)
{
    DeletePosArrayKmerFreq(_vectorKmerFreq, _size, pos);
}

void Profile::join(const Profile profile)
{
    for(int i = 0; i < profile.getSize(); i++)
    {
        append(profile._vectorKmerFreq[i]);
    }
}

int Profile::findKmer(const Kmer kmer)
{
    return -1;
}

std::string Profile::toString() const
{
    return "";
}