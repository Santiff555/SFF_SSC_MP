/*
 * Metodología de la Programación: Kmer2
 * Curso 2023/2024
 */

/** 
 * @file Profile.cpp
 * @author Santiago Fernández Fernández <santiff55@correo.ugr.es>
 * @author Santiago Salazar Cano <santyns17@correo.ugr.es>
 *
 * Created on 14 April 2024, 13:58
 */


#include "../include/Profile.h"
#include "../include/ArrayKmerFreqFunctions.h"
#include <cmath>

using namespace std;

const string Profile::MAGIC_STRING_T = "MP-KMER-T-1.0";

Profile::Profile()
{
    setProfileId("unknow");
    allocate(INITIAL_CAPACITY);
}

Profile::Profile(const int size)
{
    if(size < 0)
    {
        throw std::out_of_range("Input must be at least 0 and less than " + std::to_string(getCapacity()) );
    }
    
    setProfileId("unknow");
    allocate(size);
   
    for(int i = 0; i < getCapacity(); i++)
    {
        append(KmerFreq());
    }
}

Profile::~Profile()
{
    deallocate();
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
    return _util;
}

int Profile::getCapacity() const
{
    return _capacidad;
}

void Profile::sort()
{
    SortArrayKmerFreq(_vectorKmerFreq, getCapacity());
    
    for (int i = 0; i < _util - 1; i++){
        for (int j = i+1; j < _util ; j++) { 
            if(_vectorKmerFreq[i].getKmer().toString() < _vectorKmerFreq[j].getKmer().toString()){ //tal vez esto falle, comprobarlo
                  SwapElementsArrayKmerFreq(_vectorKmerFreq,_util,i,j);
            }
        }
    }
}

void Profile::load(const char fileName[]) {
    std::ifstream inputFile(fileName);

    // Comprobamos si hay algun fallo abriendo el fichero
    if (!inputFile.is_open()) {
        std::cerr << "Error trying to open the input file: " << fileName << std::endl;
        exit(EXIT_FAILURE);
    }

    // Comprobamos que es un fichero de Profile
    string isAProfileFile = "";
    std::getline(inputFile, isAProfileFile);
    if (isAProfileFile != MAGIC_STRING_T) {
        std::cerr << "This is not a Profile file" << std::endl;
        exit(EXIT_FAILURE);
    }

    // Obtenemos el id del Profile
    std::getline(inputFile, _profileId);

    // Obtenemos el numero de kmerFreq en el fichero.
    int inputFileKmerFreqSize = 0;
    inputFile >> inputFileKmerFreqSize;
    

    // Vaciamos el Profile
    deallocate();
    allocate(inputFileKmerFreqSize);

    // Creamos variables temporales
    std::string aKmerToAdd;
    KmerFreq aKmerFreqToAdd;
    int aFreqToAdd;
    int i = 0;
    // Leemos y guardamos los kmerFreq
    while (inputFile >> aKmerToAdd >> aFreqToAdd && i < inputFileKmerFreqSize) {
        aKmerFreqToAdd.setKmer(aKmerToAdd);
        aKmerFreqToAdd.setFrequency(aFreqToAdd);

        append(aKmerFreqToAdd);
        i++;
    }
    _util = i;
}

void Profile::save(const char fileName[])
{
    std::ofstream outputFile(fileName);    
    
    //Comprobamos si hay algun fallo abriendo el fichero
    if (!outputFile.is_open())
    {
        std::cout << "Error trying to open the file: "<<fileName<<std::endl;
        exit(EXIT_FAILURE);
    }
    
    //Indicamos que es un fichero de Profile
    outputFile<<MAGIC_STRING_T<<std::endl;
  
    //Escribimos el id del Profile
    outputFile<<_profileId<<std::endl;
    
    //Escribimos el numero de kmerFreq en el fichero.
    outputFile<<_util<<std::endl;
    
    //Escribimos los kmerFreq
    for(int i = 0; i < getSize(); i++)
    {
        outputFile<<_vectorKmerFreq[i].toString()<<std::endl;
    }
    
    outputFile.close();
}

void Profile::append(const KmerFreq kmerFreq)
{
    int kmerFreqPos = findKmer(kmerFreq.getKmer());
    
    if(kmerFreqPos == -1){ //Si no existe en el vector, lo agrega
        if(getSize() >= getCapacity())
        {
             reallocate(getCapacity() > 0 ? getCapacity() + BLOCK_SIZE : INITIAL_CAPACITY);
        }
        _vectorKmerFreq[getSize()] = kmerFreq;
        _util++;
    }
    else //Si existe le suma 1 a la frecuencia
    {
        _vectorKmerFreq[kmerFreqPos].setFrequency(_vectorKmerFreq[kmerFreqPos].getFrequency() + 1);   
    }
}

void Profile::deletePos(const int pos)
{
    if (pos < 0 || pos >= _util) {
        throw std::out_of_range("Position out of range");
    }
    DeletePosArrayKmerFreq(_vectorKmerFreq, _util, pos);
    _util--;
}

void Profile::join(const Profile profile)
{
    for(int i = 0; i < profile.getSize(); i++)
    {
        append(profile._vectorKmerFreq[i]);
    }
}

void Profile::copy(const Profile& otherProfile)
{
    deallocate();
    _util = otherProfile._util;
    _capacidad = otherProfile._capacidad;
    _profileId = otherProfile._profileId;
    
    this->_vectorKmerFreq = new KmerFreq[_capacidad];
    
    for(int i = 0; i<_util;i++)
    {
        this->_vectorKmerFreq[i] = otherProfile._vectorKmerFreq[i];
    }
}

void Profile::allocate(int new_capacity)
{
    _vectorKmerFreq = new KmerFreq[new_capacity];
    _capacidad = new_capacity;
    _util = 0;
}

void Profile::deallocate()
{
     if (_vectorKmerFreq != nullptr) {
        delete[] _vectorKmerFreq;
        _vectorKmerFreq = nullptr;
        _util = 0;
        _capacidad = 0;
    }
}
void Profile::reallocate(int new_capacity)
{
    if (new_capacity <= _capacidad)
    {
        std::cerr << "New capacity must be greater than current capacity." << std::endl;
        return;
    }
    
    KmerFreq* new_vectorKmerFreq = new KmerFreq[new_capacity];
    if (_vectorKmerFreq != nullptr) {
        for(int i = 0; i<_util;i++)
        {
            new_vectorKmerFreq[i] = _vectorKmerFreq[i];
        }
        delete[] _vectorKmerFreq;
    }
    _vectorKmerFreq = new_vectorKmerFreq;
    _capacidad = new_capacity;
}
    
Profile& Profile::operator=(const Profile& otherProfile)
{
    if (this != &otherProfile) {
        deallocate(); // Evitar fugas de memoria al liberar la memoria existente
        copy(otherProfile);
    }
    
    return *this;
}

Profile::Profile(const Profile& otherProfile)
{
    _vectorKmerFreq = nullptr;
    copy(otherProfile);
}

int Profile::findKmer(const Kmer kmer, int initialPos, int finalPos) 
{    
    return FindKmerInArrayKmerFreq(_vectorKmerFreq, kmer, initialPos, finalPos);
    
}
int Profile::findKmer(const Kmer kmer) 
{
    return findKmer(kmer, 0, getSize() - 1);
}

std::string Profile::toString() const
{
    string profileToString = "";
    profileToString += MAGIC_STRING_T;
    profileToString += "\n";
    profileToString += _profileId;
    profileToString += "\n";
    profileToString += to_string(_util);
    for(int i = 0; i<_util; i++)
    {
        profileToString += "\n";
        profileToString += _vectorKmerFreq[i].toString();
    }
    return profileToString;
}

void Profile::normalize(std::string validNucleotides)
{
    NormalizeArrayKmerFreq(_vectorKmerFreq, _util, validNucleotides);
}

void Profile::zip(bool deleteMissing, const int lowerBound)
{
    ZipArrayKmerFreq(_vectorKmerFreq, _util, deleteMissing, lowerBound);
}

double Profile::getDistance(Profile otherProfile)
{
    if(getSize() == 0 || otherProfile.getSize() == 0)
    {
         throw std::invalid_argument ("Profiles can't be void");
    }
    double distance = 0.0;
    for (int i=0; i<getSize(); i++)
    {
        int rank_other = otherProfile.findKmer(_vectorKmerFreq[i].getKmer());

        if (rank_other == -1) {
            rank_other = otherProfile.getSize();
        }

        distance += std::abs(i - rank_other);
    }
    distance /= (getSize() * otherProfile.getSize());
    return distance;
}

std::string Profile::getProfileId()
{
    return _profileId;
}