#pragma once

#include <QObject>
#include <QSocketNotifier>
#include <iostream>
#include <unistd.h>
#include <QDir>
#include <QTimer>
#include <QCoreApplication>
// #include <QApplication>
#include <QProcess>
class Console : public QObject{
    Q_OBJECT;

public:
	uint64_t timeout;
	double AvgSize;
	bool Is_started;
	bool Exitness;
	double min;
	uint64_t min_n;
	std::vector<std::pair<std::string, uint64_t>> v;
    Console();

    void run();



signals:
    void quit();
    // void StartL();
    void Start();
    void Stop();
    void Exit();
    void TimerChange(uint64_t time);
    void Restart();
    // void loop();
    // void StartChange();
    // void If_Started();
// 
private:
    QSocketNotifier *m_notifier;
    QTimer *tmr;

private slots:
    void readCommand();

public slots:
	void SLOT_Start(){
        Is_started = 1;
    }
    void SLOT_Stop(){
    	// std::cout << std::endl << "!! STOPED !!" << std::endl;
        Is_started = 0;
    }
    void SLOT_Exit(){
        std::exit(0);
    }
    void SLOT_Restart(){
    	std::cout << "Restarting..." << std::endl;
        // app->(1337);
    }
    void restartApp(){
		QProcess::startDetached(QCoreApplication::applicationFilePath());
		exit(12);
	}
    void SLOT_Timeout(uint64_t t){
    	timeout = t;
    	// std::cout << "timeout now is " << t << std::endl;
    	tmr->setInterval(1000*timeout);
    }
    // void SLOT_Loop(){
    // 	connect(m_notifier, SIGNAL(activated(int)), this, SLOT(readCommand()));
    // 	if (Is_started) emit Start();
    // }

    void SLOT_WhatToDo(){

    	// std::cout << "AWAOAOAOOAO TIMEOUT SADAWD " << std::endl;

    	if (Is_started) {
    		AvgSize = 0;
    		
	        if (v.size() != 0){
	        	std::cout << "{";
	        	for (uint64_t i = 0; i < v.size(); i++){
	        		if (i != v.size() - 1) std::cout <<	v[i].first << ", ";
	        		else std::cout << v[i].first;
	        		AvgSize += v[i].second;
	        	}

	        	if (v.size() != 0 )std::cout << "}\n" << std::flush;
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
	        	std::cout << "AvgSize = " << AvgSize << " min = " << min << " min_n = " << min_n << "\n>" << std::flush;
	        	v.erase(v.begin() + min_n);
	        }
	        else {std::cout << "No more elements, stopped" << std::endl; emit Stop();} 
    	}
    	// else{
    	// 	std::cout << ">" << std::flush;
    	

    }

};

inline Console::Console()
{
	timeout = 0;
	Is_started = 0;
	Exitness = 0;
    m_notifier = new QSocketNotifier(fileno(stdin), QSocketNotifier::Read, this);
    tmr = new QTimer();
    tmr->setInterval(timeout*1000);
}