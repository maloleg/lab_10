#include <iostream>
#include "console.hpp"

void Console::run()
{
    


    std::cout << ">" << std::flush;
    connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readCommand()));
    connect(this, SIGNAL(Start()), this, SLOT(SLOT_Start()));
    connect(this, SIGNAL(Stop()), this, SLOT(SLOT_Stop()));
    connect(this, SIGNAL(Exit()), this, SLOT(SLOT_Exit())); 
    connect(this, SIGNAL(TimerChange(uint64_t)), this, SLOT(SLOT_Timeout(uint64_t)));
    connect(tmr, SIGNAL(timeout()), this, SLOT(SLOT_WhatToDo()));

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
    else std::cout << ">" << std::flush;

}

void Console::SLOT_Start(){
    tmr->start();
}
void Console::SLOT_Stop(){
    tmr->stop();
}
void Console::SLOT_Exit(){
    QCoreApplication::exit(1337);
}

void Console::SLOT_Timeout(uint64_t t){
    tmr->setInterval(1000*t);
}

void Console::SLOT_WhatToDo(){
    AvgSize = 0;
    
     if (v.size() != 0){
        for (uint64_t i = 0; i < v.size(); i++){
            // if (i != v.size() - 1) std::cout << v[i].first << ", ";
            // else std::cout << v[i].first;
            AvgSize += v[i].second;
        }
        AvgSize /= v.size();
        AvgSize *= 0.75;
        min = sqrt(abs(v[0].second*v[0].second-AvgSize*AvgSize));
        min_n = 0;

        for (uint64_t i = 0; i < v.size(); i++){
            if (sqrt(abs(AvgSize*AvgSize - v[i].second*v[i].second)) < min){
                min = sqrt(abs(AvgSize*AvgSize - v[i].second*v[i].second));
                min_n = i;
            }
        }
        CrutchSet.erase(v[min_n].first);
        v.erase(v.begin() + min_n);
    }
        std::cout << "\n{";
        for (uint64_t i = 0; i < v.size(); i++){
            if (i != v.size() - 1) std::cout << *CrutchSet.find(v[i].first) << ", ";
            else std::cout << *CrutchSet.find(v[i].first);
            // AvgSize += v[i].second;
        }

        std::cout << "}\n" << std::flush;
        
    // }
    // else {std::cout << "No more elements, stopped\n>" << std::flush; emit Stop();} 
}