#include <iostream>
#include <string>
#include <sstream>
#include "TConsole.h"
#include "TCommandProcessor.h"
#include "TBlockProcessor.h"

int main(int argc, char** argv)
{
    /*
    std::stringstream sstream;
    sstream << "cmd1" <<std::endl;
    sstream << "cmd2" <<std::endl;
    sstream << "cmd3" <<std::endl;
    sstream << "cmd4" <<std::endl;
    sstream << "cmd5" <<std::endl;
    sstream << "{" <<std::endl;
    sstream << "cmd11" <<std::endl;
    sstream << "cmd12" <<std::endl;
    sstream << "cmd13" <<std::endl;
    sstream << "cmd14" <<std::endl;
    sstream << "cmd15" <<std::endl;
    sstream << "}" <<std::endl;
    */

    //  Считываем размер блока
    //std::cout << argc << std::endl;
    if(argc<2){
        std::cerr << "Wrong arguments count. Using: bulk <bulk_size>"<< std::endl;
        return -1;
    }
    auto bulk_size(std::stoul(argv[1]));
    //std::cout << bulk_size << std::endl;

    //  Подготавливаем ввод
    //TConsole console(sstream);
    TConsole console(std::cin);

    //  Добавляем обработчики
    //  Обработчик команд
    console.addObserver(std::make_shared<TCommandProcessor>(bulk_size));
    //  Обработчик блоков
    console.addObserver(std::make_shared<TBlockProcessor>());

    //  Обрабатываем ввод
    console.run();

    return 0;
}
