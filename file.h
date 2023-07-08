#ifndef FILE_H
#define FILE_H

#include<iostream>
#include<fstream>

class File {
    std::ofstream out;

    public:
    File(std::string filename) {
        out.open(filename);
        if(!out) {
            std::cout << "File opening error" << std::endl;
            exit(1);
        }
        out << "input size, runtime in ms(unsorted), runtime in ms(ascending), runtime in ms(descending)" << std::endl;
    }

    void addRecord(int inputSize, double randomMs, double ascMs, double dscMs) {
        out << inputSize << "," << randomMs << "," << ascMs << "," << dscMs << std::endl;
    }

    ~File() {
        out.close();
    }
};

#endif