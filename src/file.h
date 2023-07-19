#ifndef FILE_H
#define FILE_H

#include<iostream>
#include<fstream>

class File {
    std::ofstream out;
    bool multipleInput;
    bool includeComparision;

    public:
    File(std::string filename, bool multipleInput = false, bool includeComparision = false) {
        this->includeComparision = includeComparision;
        this->multipleInput = multipleInput;
        out.open(filename);
        if(!out) {
            std::cout << "File opening error" << std::endl;
            exit(1);
        }
        if(multipleInput && includeComparision)
            out << "input size, runtime in ms(unsorted), runtime in ms(ascending), runtime in ms(descending), swaps(unsorted), swaps(ascending), swaps(descending)" << std::endl;
        else if(multipleInput)
            out << "input size, runtime in ms(unsorted), runtime in ms(ascending), runtime in ms(descending)" << std::endl;
        else
            out << "input size, runtime(ms)" << std::endl;
    }

    void addRecord(int inputSize, double randomMs, double ascMs = 0, double dscMs = 0, int swapRandom = 0, int swapAsc = 0, int swapDsc = 0) {
        if(multipleInput && includeComparision)
            out << inputSize << "," << randomMs << "," << ascMs << "," << dscMs << ", " << swapRandom << "," << swapAsc << "," << swapDsc << std::endl;
        else if(multipleInput)
            out << inputSize << "," << randomMs << "," << ascMs << "," << dscMs << std::endl;
        else
            out << inputSize << "," << randomMs << std::endl;
    }

    ~File() {
        out.close();
    }
};

#endif