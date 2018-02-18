#ifndef TCONSOLE_H
#define TCONSOLE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

#include "TObserver.h"

/*!
    ����� ��� ���������� ����� ������ �� �������
*/
class TConsole
{
    public:
        TConsole(std::istream& user_input);
        virtual ~TConsole();
        /*!
            �����,����������� ���� ��������� �����
        */
        void run();

        /*! ����� ����������� �����������*/
        void addObserver(ptrObserver newObserver);

    protected:

    private:
        //  ����� ��� �����
        std::istream& _input;
        //  ����������� ��� ������
        std::vector <ptrObserver>   _observers;
};

#endif // TCONSOLE_H
