#ifndef csvwriter_h
#define csvwriter_h

#include <fstream>

class CSVWriter {
    std::string fileName;
    std::string delimeter;
    int linesCount;
    
public:
    std::string algName1;
    std::string algName2;
    
    CSVWriter(std::string filename, std::string delm = ",") :
    fileName(filename), delimeter(delm), linesCount(0)
    {}
    
    template<typename T>
    void addDatainRow(T first1, T last1, T first2, T last2);
};

template<typename T>
void CSVWriter::addDatainRow(T first1, T last1, T first2, T last2) {
    std::fstream file;
    file.open(fileName, std::ios::out | (linesCount ? std::ios::app : std::ios::trunc));
    file << algName1 << delimeter << algName2 << std::endl;
    while (first1 != last1) {
        file << *first1 << delimeter << *first2;
        if (++first1 != last1) {
            file << std::endl;
            ++first2;
        }
    }
    ++linesCount;
    file.close();
}

#endif /* csvwriter_h */
