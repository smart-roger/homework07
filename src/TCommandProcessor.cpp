#include "TCommandProcessor.h"

TCommandProcessor::TCommandProcessor(size_t bulkSize):
    TObserver(),
    _bulkSize(bulkSize),
    _blockCounter(0),
    _store(bulkSize)
{

}

TCommandProcessor::~TCommandProcessor()
{
    //���� ������� ���� - ���� ������� ����������� �������
    if(!_store.empty()){
        _store.printCommands();
        void logBlock();
        _store.clear();
    }
}

void TCommandProcessor::newCommand(const std::string& newCommand){
    _store.addCommand(newCommand);
}

void TCommandProcessor::startBlock(){
    if(0==_blockCounter && 0<_store.size()){
        _store.printCommands();
        logBlock();
        _store.clear();
    }
    ++_blockCounter;
}

void TCommandProcessor::finishBlock(){

    if(0<_blockCounter) --_blockCounter;
    //  ��� ������ ����������� ��� ��������� ����������?
    //else{}
}

void TCommandProcessor::handleCommand(const std::string& command){
    if(0==_blockCounter)
    {
        if(_store.empty())
            _timeStart = std::time(nullptr);
        newCommand(command);
        if(_bulkSize == _store.size()){
            _store.printCommands();
            logBlock();
            _store.clear();
        }
    }
    //  ����� �������������� � ������ �����������.
    //  else{}

}

void TCommandProcessor::logBlock(){
    std::ofstream fileLog("bulk"+std::to_string(_timeStart)+".log");
    _store.printCommands(fileLog);
}
