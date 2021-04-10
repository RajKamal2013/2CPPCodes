//
// Created by Raj Kamal on 10/8/20.
//

#include <iostream>
#include <cstring>
#include <vector>


#include "helloworld.h"
#include "IntegerFileGenerator.h"
#include "qsort.h"

int main()
{
    /* Start Coding */
    std::cout << "1. ******Lets start coding *******" << std::endl;
    helloworld *test = new helloworld();
    test->start_coding();
    std::cout << std::endl;

    /* File Generation Test */
    std::cout << "2. *******Lets test file generation and random number generation ********" << std::endl;
    IntegerFileGenerator *fio = new IntegerFileGenerator(50, 500, "SampleInput.txt", "SampleOutput.txt");
    fio->write();
    std::vector<int> vec;
    vec = fio->read();
    std::cout << "size of vector:" << vec.size() << std::endl;
    for (int data:vec) {
        std::cout << data << " " ;
    }
    std::cout <<std::endl;
    fio->write(vec);

    std::cout <<std::endl;

    /*Qsort Testing */
    std::cout << "3. ****** Lets Test Qsort " << std::endl;
    IntegerFileGenerator *qsortIo = new IntegerFileGenerator(100, 700, "QsortInput.txt", "QsortOutput.txt");
    qsortIo->write();
    std::vector<int> qvec;
    qvec = qsortIo->read();
    for (int data:qvec) {
        std::cout << data << " ";
    }
    std::cout << std::endl;
    QSort *qfio = new QSort(std::move(qvec), qvec.size());
    qvec = qfio->run();
    qsortIo->write(qvec);
    for (int data:qvec) {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    return 0;
}