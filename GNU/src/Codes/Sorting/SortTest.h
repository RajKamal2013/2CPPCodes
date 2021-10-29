//
// Created by kamr on 10/28/2021.
//

#ifndef GNU_SORTTEST_H
#define GNU_SORTTEST_H

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

void SortTest()
{
    /* -------------------- Start Coding --------------------*/
    char *banner = "-------------------";
    int size, range;
    std::cout << banner << "Lets start coding " << banner << std::endl;
    helloworld *test = new helloworld();
    test->start_coding();
    std::cout << std::endl;

    /* -------------------File Generation Test --------------------*/
    size = 50;
    range = 500;
    IntegerFileGenerator *fio = new IntegerFileGenerator(size, range, "SampleInput.txt", "SampleOutput.txt");
    fio->generate();
    std::vector<int> vec;
    vec = fio->read();
    PrintArrayWithBanner(vec, "Testing file generation and random number generation");
    fio->write(vec);
    std::cout <<std::endl;

    /*--------------------Quick sort Testing --------------------*/
    size = 100;
    range = 700;
    IntegerFileGenerator *qsortIo = new IntegerFileGenerator(size, range, "QsortInput.txt", "QsortOutput.txt");
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


    /*--------------------Merge sort Testing --------------------*/
    size = 100;
    range  = 700;
    IntegerFileGenerator *msortIo = new IntegerFileGenerator(size, range, "MsortInput.txt", "MsortOutput.txt");
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

    /* -----------------------Heap Sort Testing ----------------------*/
    size = 100;
    range = 700;
    IntegerFileGenerator *hSortIo = new IntegerFileGenerator(size, range, "HSortInput.txt", "HSortOutput.txt");
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
    PrintArrayWithBanner(hvec, "HSort Test:Ouput Array");
    hSortIo->write(hvec);

    /* -----------------------Counting Sort Testing ----------------------*/
    size = 100;
    range = 500;
    IntegerFileGenerator *CSortIo = new IntegerFileGenerator(size, range, "CSortInput.txt", "CSortOutput.txt");
    CSortIo->generate();
    std::vector<int>Cvec;
    Cvec = CSortIo->read();
    PrintArrayWithBanner(Cvec, "Csort Test:Input Array");

    start= std::chrono::steady_clock::now();
    CSort::Sort(Cvec, range);
    end = std::chrono::steady_clock::now();
    std::cout << "Elapsed time in nanoseconds "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()
              << " ns"
              <<std::endl;
    PrintArrayWithBanner(Cvec, "CSort Test:Ouput Array");
    CSortIo->write(Cvec);

}

void SortingTest()
{
    /* Start Coding */
    std::cout << "1. ******Lets start coding *******" << std::endl;
    helloworld *test = new helloworld();
    test->start_coding();
    std::cout << std::endl;

    /* File Generation Test */
    std::cout << "2. *******Lets test file generation and random number generation ********" << std::endl;
    IntegerFileGenerator *fio = new IntegerFileGenerator(50, 500, "SampleInput.txt", "SampleOutput.txt");
    fio->generate();
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
    qsortIo->generate();
    std::vector<int> qvec;
    qvec = qsortIo->read();
    for (int data:qvec) {
        std::cout << data << " ";
    }
    std::cout << std::endl;
    QSort *qfio = new QSort(std::move(qvec), qvec.size());
    auto start = std::chrono::steady_clock::now();
    qvec = qfio->run();
    auto end = std::chrono::steady_clock::now();
    std::cout << "Elapsed time in nanoseconds "
              << std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count()
              << " ns"
              <<std::endl;
    qsortIo->write(qvec);
    for (int data:qvec) {
        std::cout << data << " ";
    }
    std::cout << std::endl;

    std::cout <<std::endl;
}

#endif //GNU_SORTTEST_H
