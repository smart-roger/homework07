#include "TConsole.h"

TConsole::TConsole(std::istream& user_input):_input(user_input), _observers()
{
    //ctor
}

TConsole::~TConsole()
{
    //dtor
}

void TConsole::run(){

        std::string command;

        while(std::getline(_input, command)){
            try{
                //  В обработчиках могут быть проблемы. На всякий сдучай обернём
                std::for_each(_observers.begin(), _observers.end(),[command](auto ptrProcessor){
                        ptrProcessor->parseCommand(command);
                        }
                );
                //command.clear();
            }catch(std::exception e){
                std::cerr << "Exception in observer! " << e.what() << std::endl;
            }
            catch(...){
                std::cerr << "Unknown exception in observer! " << std::endl;
            }
        };
}

void TConsole::addObserver(ptrObserver newObserver){
    if(nullptr == newObserver)  {
            std::cerr << "nullptr in addObserver!" << std::endl;
            return;
    }
    _observers.push_back(newObserver);
}
