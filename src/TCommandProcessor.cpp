#include "TCommandProcessor.h"

TCommandProcessor::TCommandProcessor(size_t bulkSize):
    TObserver(),
    _bulkSize(bulkSize),
    _blockCounter(0),
    _store(bulkSize)
{
    //ctor
}

TCommandProcessor::~TCommandProcessor()
{
    //≈сли окончен ввод - надо вывести накопленные команды
    _store.printCommands();
}

void TCommandProcessor::newCommand(const std::string& newCommand){
    _store.addCommand(newCommand);
}

void TCommandProcessor::startBlock(){
    if(0==_blockCounter && 0<_store.size()){
        _store.printCommands();
        _store.clear();
    }
    ++_blockCounter;
}

void TCommandProcessor::finishBlock(){

    if(0<_blockCounter) --_blockCounter;
    //  „то должно происходить при нарушении синтаксиса?
    //else{}
}

void TCommandProcessor::handleCommand(const std::string& command){
    if(0==_blockCounter)
    {
        newCommand(command);
        if(_bulkSize == _store.size()){
            _store.printCommands();
            _store.clear();
        }
    }
    //  Ѕлоки обрабатываютс€ в другом наблюдателе.
    //  else{}

}
