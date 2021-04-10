//
// Created by Raj Kamal on 03/04/21.
//

#include "IntegerFileGenerator.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <vector>

IntegerFileGenerator ::IntegerFileGenerator() {
    this->range = 100;
    this->size = 50;
    this->InputFileName = "intput.txt";
    this->OutputFileName = "output.txt";
}

IntegerFileGenerator ::IntegerFileGenerator(int size, int range )
{
    this->size = size;
    this->range = range;
    this->InputFileName = "input.txt";
    this->OutputFileName = "output.txt";
}

IntegerFileGenerator::IntegerFileGenerator(int size, int range, std::string OutputFileName)
{
    this->size = size;
    this->range = range;
    this->InputFileName = "input.txt";
    this->OutputFileName = OutputFileName;
}

IntegerFileGenerator::IntegerFileGenerator(int size, int range, std::string InputFileName, std::string OutputFileName)
{
    this->size = size;
    this->range = range;
    this->InputFileName = InputFileName;
    this->OutputFileName = OutputFileName;
}

IntegerFileGenerator::IntegerFileGenerator(std::string InputFileName, std::string OutputFileName)
{
    this->size = 0;
    this->range = 0;
    this->InputFileName = InputFileName;
    this->OutputFileName = OutputFileName;

}

void IntegerFileGenerator :: write()
{
    std::cout<< "Writing Random Generated Data to the file:" << InputFileName << std::endl;
    std::ofstream myfile;
    int data;
    myfile.open (InputFileName);
    myfile << this->size << std::endl;
    for (int i = 0; i < this->size; i++) {
        data = rand() % range;
        myfile << data << std::endl;
    }
    myfile.close();
}

void IntegerFileGenerator :: write(std::vector<int> vec)
{
    std::cout << "Writing Processed Data to the file:" << OutputFileName << std::endl;
    std::ofstream myfile;
    int data;
    myfile.open(OutputFileName);
    myfile << vec.size() << std::endl;
    for (int i = 0; i < vec.size(); i++) {
        data = vec[i];
        myfile << data << std::endl;
    }
    myfile.close();
}

std::vector<int> IntegerFileGenerator :: read()
{
    std::cout <<"Reading from the file:" << InputFileName << std::endl;
    std::ifstream myfile;
    int size;
    int data;
    myfile.open(InputFileName);
    myfile >> size;
    if (this->size == 0) {
        this->size = size;
    }
    std::cout << "Size of data:" << size << std::endl;
    std::vector<int> vec(size);
    for (int i = 0; i < size; i++) {
        myfile >> vec[i];
        //vec.push_back(data);
    }
    return vec;
}