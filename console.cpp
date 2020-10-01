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
        // std::cout << files[i].fileName().toUtf8().constData() << "   " << files[i].size() << "\n";
        AvgSize += files[i].size();
    }
  
    std::sort(v.begin(), v.end(),
              [](const std::pair<std::string, uint64_t> &left, const std::pair<std::string, uint64_t> &right){
        return left.second < right.second;
    });

    std::cout << ">" << std::flush;
    connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readCommand()));
    connect(this, SIGNAL(Start()), this, SLOT(SLOT_Start()));
    connect(this, SIGNAL(Stop()), this, SLOT(SLOT_Stop()));
    connect(this, SIGNAL(Exit()), this, SLOT(SLOT_Exit())); 
    connect(this, SIGNAL(TimerChange(uint64_t)), this, SLOT(SLOT_Timeout(uint64_t)));
    connect(tmr, SIGNAL(timeout()), this, SLOT(SLOT_WhatToDo()));
    tmr->start();

}

void Console::readCommand()
{
    std::string s;
    std::getline(std::cin, s);

    if (regex_match(s.begin(), s.end(), std::regex("start"))) {emit Start(); std::cout << ">" << std::flush;}
    else if (regex_match(s.begin(), s.end(), std::regex("stop"))) {emit Stop(); std::cout << ">" << std::flush;}
    else if (regex_match(s.begin(), s.end(), std::regex("exit"))) emit Exit();
    else if (regex_match(s.begin(), s.end(), std::regex("restart"))) emit Restart();
    else if (regex_match(s.begin(), s.end(), std::regex("timeout\\s\\d+"))) {emit TimerChange(std::stoi(s.substr(8, s.size() - 8).c_str())); std::cout << ">" << std::flush;}

}

void Console::SLOT_Start(){
        Is_started = 1;
}
void Console::SLOT_Stop(){
    Is_started = 0;
}
void Console::SLOT_Exit(){
    QCoreApplication::exit(1337);
}

void Console::SLOT_Timeout(uint64_t t){
    tmr->setInterval(1000*t);
}

void Console::SLOT_WhatToDo(){

    if (Is_started) {
        AvgSize = 0;
        
        if (v.size() != 0){
            std::cout << "\n{";
            for (uint64_t i = 0; i < v.size(); i++){
                if (i != v.size() - 1) std::cout << v[i].first << ", ";
                else std::cout << v[i].first;
                AvgSize += v[i].second;
            }

            if (v.size() != 0)std::cout << "}\n>" << std::flush;
            // std::cout << ">" << std::flush();
            AvgSize /= v.size();
            AvgSize *= 0.75;
            min = abs(v[0].second-AvgSize);
            min_n = 0;

            for (uint64_t i = 0; i < v.size(); i++){
                if (abs(AvgSize - v[i].second) < min){
                    min = abs(AvgSize - v[i].second);
                    min_n = i;
                }
            }
            // std::cout << "AvgSize = " << AvgSize << " min = " << min << " min_n = " << min_n << "\n>" << std::flush;
            
            v.erase(v.begin() + min_n);
        }
        else {std::cout << "No more elements, stopped\n>" << std::flush; emit Stop();} 
    }
}