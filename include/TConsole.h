#ifndef TCONSOLE_H
#define TCONSOLE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

#include "TObserver.h"

/*!
    Класс для реализации приёма данных из консоли
*/
class TConsole
{
    public:
        TConsole(std::istream& user_input);
        virtual ~TConsole();
        /*!
            Метод,запускающий цикл обработки ввода
        */
        void run();

        /*! Метод добавляющий обработчики*/
        void addObserver(ptrObserver newObserver);

    protected:

    private:
        //  Поток для ввода
        std::istream& _input;
        //  Обработчики для команд
        std::vector <ptrObserver>   _observers;
};

#endif // TCONSOLE_H
