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
class Console : public QObject {
    Q_OBJECT;

public:
    void run();
    Console();
    ~Console(){
    	std::cout << "\nDestructor called\n" << std::flush;
    }

signals:
    void quit();
    void Start();
    void Stop();
    void Exit();
    void TimerChange(uint64_t time);
    void Restart();

private:
    QSocketNotifier *m_notifier;
    QTimer *tmr;
	double AvgSize;
	bool Is_started;
	bool Exitness;
	double min;
	uint64_t min_n;
	std::vector<std::pair<std::string, uint64_t>> v;
    

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
	// timeout = 0;
	Is_started = 0;
	Exitness = 0;
    m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
    tmr = new QTimer();
    tmr->setInterval(0);
}