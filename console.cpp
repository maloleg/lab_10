#include <iostream>
#include "console.hpp"

void Console::run()
{
    v.clear();
    std::string c = "";

    QDir CurrentDir("");

    QFileInfoList files = CurrentDir.entryInfoList();

    for (int64_t i = 0; i < files.size(); i++){
        v.push_back(std::make_pair(files[i].fileName().toUtf8().constData(), files[i].size()));
        std::cout << files[i].fileName().toUtf8().constData() << "   " << files[i].size() << "\n";
        AvgSize += files[i].size();
    }
  
    std::sort(v.begin(), v.end(),
              [](const std::pair<std::string, uint64_t> &left, const std::pair<std::string, uint64_t> &right){
        return left.second < right.second;
    });
    // std::cout << "First message" << std::endl;
    std::cout << ">" << std::flush;
    connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readCommand()));
    // connect(this, SIGNAL(StartChange()), this, SLOT(SLOT_WhatToDo()));
    connect(this, SIGNAL(Start()), this, SLOT(SLOT_Start()));
    connect(this, SIGNAL(Stop()), this, SLOT(SLOT_Stop()));
    connect(this, SIGNAL(Exit()), this, SLOT(SLOT_Exit())); 
    connect(this, SIGNAL(Restart()), this, SLOT(restartApp()));
    connect(this, SIGNAL(TimerChange(uint64_t)), this, SLOT(SLOT_Timeout(uint64_t)));
    connect(tmr, SIGNAL(timeout()), this, SLOT(SLOT_WhatToDo()));
    tmr->start();

}

void Console::readCommand()
{
    // std::exit(1);
    // std::cout << "lol mate slot is here, baby!" << std::endl;
    std::string command;
    std::getline(std::cin, command);

    // std::cout << "lol man\n command = " << command << std::endl;

    if ((command.size()  == 5 && command == "start")) emit Start();
    if (command.size() == 7 && command == "restart") emit Restart();
    if (command.size() == 4 && command == "stop") emit Stop();
    if (command.size() == 4 && command == "exit") emit Exit();
    if (command.size() > 7 && command.substr(0, 7) == "timeout"
                && command.substr(8, command.size() - 9).find_first_not_of("0123456789") == std::string::npos){
            // std::cout << "n=" << std::stoi(command.substr(8, command.size() - 8).c_str()) << std::endl;
            emit TimerChange(std::stoi(command.substr(8, command.size() - 8).c_str()));
            // this->timeout = std::stoi(command.substr(8, command.size() - 8).c_str());
        }
    std::cout << ">" << std::flush;
    // emit If_Started();
}