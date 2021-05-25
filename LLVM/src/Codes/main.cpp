//
// Created by Raj Kamal on 10/8/20.
//

#include <iostream>
#include <cstring>
#include <vector>


#include "helloworld.h"
#include "Util/IntegerFileGenerator.h"
#include "Sorting/qsort.h"
#include "Sorting/Msort.h"
#include "Sorting/Hsort.h"


void PrintArrayWithBanner(std::vector<int> vec, char *str )
{
    char *banner = "---------------------";
    std::cout<<banner << str << banner << std::endl;
    std::cout << "size of vector:" << vec.size() << std::endl;
    for (int data:vec) {
        std::cout << data << " " ;
    }
    std::cout <<std::endl;
}

int main()
{
    /* -------------------- Start Coding --------------------*/
    char *banner = "-------------------";
    std::cout << banner << "Lets start coding " << banner << std::endl;
    helloworld *test = new helloworld();
    test->start_coding();
    std::cout << std::endl;

    /* -------------------File Generation Test --------------------*/
    IntegerFileGenerator *fio = new IntegerFileGenerator(50, 500, "SampleInput.txt", "SampleOutput.txt");
    fio->generate();
    std::vector<int> vec;
    vec = fio->read();
    PrintArrayWithBanner(vec, "Testing file generation and random number generation");
    fio->write(vec);
    std::cout <<std::endl;

    /*--------------------Qsort Testing --------------------*/
    IntegerFileGenerator *qsortIo = new IntegerFileGenerator(100, 700, "QsortInput.txt", "QsortOutput.txt");
    qsortIo->generate();
    std::vector<int> qvec;
    qvec = qsortIo->read();
    PrintArrayWithBanner(qvec, "Qsort Test:Input Array");

    auto start = std::chrono::steady_clock::now();
    QSort::Sort(qvec);
    auto end = std::chrono::steady_clock::now();

    PrintArrayWithBanner(qvec, "QSort Test:Output Array");
    std::cout << "Elapsed time in nanoseconds "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()
              << " ns"
              <<std::endl;

    qsortIo->write(qvec);


    /*--------------------Msort Testing --------------------*/
    IntegerFileGenerator *msortIo = new IntegerFileGenerator(100, 700, "MsortInput.txt", "MsortOutput.txt");
    msortIo->generate();
    std::vector<int>mvec;
    mvec = msortIo->read();
    PrintArrayWithBanner(mvec, "Msort Test:Input Array");

    start = std::chrono::steady_clock::now();
    MSort::Sort(mvec);
    end = std::chrono::steady_clock::now();
    std::cout << "Elapsed time in nanoseconds "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()
              << " ns"
              <<std::endl;
    PrintArrayWithBanner(mvec, "MSort Test:Ouput Array");
    msortIo->write(mvec);

    /* -----------------------HSort Testing ----------------------*/
    IntegerFileGenerator *hSortIo = new IntegerFileGenerator(100, 700, "HSortInput.txt", "HSortOutput.txt");
    hSortIo->generate();
    std::vector<int>hvec;
    hvec = hSortIo->read();
    PrintArrayWithBanner(hvec, "Hsort Test:Input Array");

    start= std::chrono::steady_clock::now();
    HSort::Sort(hvec);
    end = std::chrono::steady_clock::now();
    std::cout << "Elapsed time in nanoseconds "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()
              << " ns"
              <<std::endl;
    PrintArrayWithBanner(hvec, "MSort Test:Ouput Array");
    msortIo->write(hvec);

    return 0;
}