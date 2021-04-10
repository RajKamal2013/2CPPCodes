//
// Created by Raj Kamal on 03/04/21.
//

#ifndef SORTING_INTEGERFILEGENERATOR_H
#define SORTING_INTEGERFILEGENERATOR_H

#include <string>
#include <iostream>
#include <vector>

class IntegerFileGenerator {
private:
    int size;
    int range;
    std::string InputFileName;
    std::string OutputFileName;

public:
    IntegerFileGenerator();
    IntegerFileGenerator(int size, int range);
    IntegerFileGenerator(int size, int range, std::string OutputFileName);
    IntegerFileGenerator(int size, int range, std::string InputFileName, std::string OutputFileName);
    IntegerFileGenerator(std::string InputFileName, std::string OutputFileName);
    std::vector<int> read();
    void write();
    void write(std::vector<int>vec);
};


#endif //SORTING_INTEGERFILEGENERATOR_H
