//
// Created by Raj Kamal on 8/11/18.
//


class helloWorld {
public:
    std::thread *t2;
    helloWorld() {
        std::cout<<"Constructor called " << std::endl;
        t2= new std::thread(&helloWorld::hello, this);
    }
    void hello();
    void runThread();
    ~helloWorld(){
        t2->join();
        std::cout<<"Destructor Done " << std::endl;
    }
};

void printhello();

