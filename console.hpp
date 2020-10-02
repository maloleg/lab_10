#pragma once

#include <QObject>
#include <QSocketNotifier>
#include <iostream>
#include <QDir>
#include <QTimer>
#include <QCoreApplication>
#include <vector>
#include <QProcess>
#include <regex>
#include <set>
#include <cmath>
class Console : public QObject {
    Q_OBJECT;

public:
    void run();
    Console();
    ~Console(){
    	std::cout << "Destructor called\n" << std::flush;
    }

signals:
    void Start();
    void Stop();
    void Exit();
    void TimerChange(uint64_t time);
    void Restart();

private:
    QSocketNotifier *m_notifier;
    QTimer *tmr;
	double AvgSize;
	double min;
	uint64_t min_n;
	std::vector<std::pair<std::string, uint64_t>> v;
	std::set<std::string> CrutchSet;
    

private slots:
    void readCommand();

	void SLOT_Start();

    void SLOT_Stop();

    void SLOT_Exit();

    void SLOT_Timeout(uint64_t t);

    void SLOT_WhatToDo();
};

inline Console::Console()
{
    m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
    tmr = new QTimer();
    tmr->setInterval(0);
    v.clear();

    QDir CurrentDir("");

    QFileInfoList files = CurrentDir.entryInfoList();

    for (int64_t i = 0; i < files.size(); i++){
        if (files[i].isFile()){
            v.push_back(std::make_pair(files[i].fileName().toUtf8().constData(), files[i].size()));
            AvgSize += files[i].size();
        }
    }
  
    std::sort(v.begin(), v.end(),
              [](const std::pair<std::string, uint64_t> &left, const std::pair<std::string, uint64_t> &right){
        return left.second < right.second;
    });

    for (size_t i = 0; i < v.size(); i++){
        CrutchSet.insert(v[i].first);
    }

    std::cout << "\n{";
        for (uint64_t i = 0; i < v.size(); i++){
            if (i != v.size() - 1) std::cout << *CrutchSet.find(v[i].first) << ", ";
            else std::cout << *CrutchSet.find(v[i].first);
            // AvgSize += v[i].second;
        }

        std::cout << "}\n" << std::flush;
}