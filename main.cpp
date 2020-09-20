#include <QCoreApplication>
#include <QDir>
#include <QProcess>
#include <QTextStream>
#include <iostream>
#include <algorithm>
#include <vector>
#include "stdlib.h"
#include "stdio.h"
#include <string>
#include <QtCore>

bool is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

class Proc : public QObject{
    Q_OBJECT

public:
    Proc(QObject* parent = 0) : QObject(parent), Timer(0), Is_started(0), command(""), AvgSize(0), Exitness(0){}
    uint64_t Timer;
    bool Is_started;
    std::string command;
    uint64_t AvgSize;
    bool Exitness;

    virtual ~Proc() {};

//    Vars(){
//        Timer = 0;
//        AvgSize = 0;
//        command = "";
//        Is_started = 0;
//        Exitness = 0;
//    }

signals:
    void Start();
    void Stop();
    void Exit();
    void Timeout(uint64_t time);
    void Restart();



public slots:
    void TimerChanging(uint64_t NewTime){
        Timer = NewTime;
    }

    void CommandChange(std::string com){
        command = com;

        if (command.size()  == 5 && command == "start") emit Start();
        if (command.size() == 7 && command == "restart") emit Restart();
        if (command.size() == 4 && command == "stop") emit Stop();
        if (command.size() == 4 && command == "exit") emit Exit();
        if (command.size() > 7 && command.substr(0, 7) == "timeout"
                && is_digits(command.substr(8, command.size() - 9))){
//            this->TimerChanging();
            emit Timeout(std::stoi(command.substr(8, command.size() - 9).c_str()));
        }
//        else if (command.substr(0, 7) == "timeout" and is_digits(command.substr(8, command.size() - 9))){
//            Timer =
//        }
    }

    void S_Start(){
        Is_started = 1;
    }
    void SLOT_Stop(){
        Is_started = 0;
    }
    void SLOT_Exit(){
        std::exit(0);
    }
    void SLOT_Restart(){
        Exitness = 1;
    }
    void SLOT_Timeout(uint64_t time){
        this->TimerChanging(time);
    }


};


int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);

    QDir CurrentDir("");

    QTextStream qin(stdin);

    std::vector<std::pair<std::string, uint64_t>> v;
    v.clear();
    Proc *k1 = new Proc(&a);
//    Vars k2;
    std::string c = "";

    QFileInfoList files = CurrentDir.entryInfoList();



    for (int64_t i = 0; i < files.size(); i++){
        v.push_back(std::make_pair(files[i].fileName().toUtf8().constData(), files[i].size()));
        std::cout << files[i].fileName().toUtf8().constData() << "   " << files[i].size() << std::endl;
        k1->AvgSize += files[i].size();
    }
    k1->AvgSize /= files.size();
    k1->Timer = 0;
    k1->command = "";
    k1->Is_started = 0;


    std::sort(v.begin(), v.end(),
              [](const std::pair<std::string, uint64_t> &left, const std::pair<std::string, uint64_t> &right){
        return left.second < right.second;
    });

    while (1){

        std::cout << "\n{";

        for (int64_t i = 0; i < v.size(); i++){
            std::cout << v[i].first;
            if (i != v.size() - 1)  std::cout << ", ";
        }

        QObject::connect(k1, SIGNAL(Start()), k1, SLOT(SLOT_Start()));
        QObject::connect(k1, SIGNAL(Stop()), k1, SLOT(SLOT_Stop()));
        QObject::connect(k1, SIGNAL(Restart()), k1, SLOT(SLOT_Restart()));
        QObject::connect(k1, SIGNAL(Exit()), k1, SLOT(SLOT_Exit()));
        QObject::connect(k1, SIGNAL(Start()), k1, SLOT(SLOT_Start()));

        std::cout << "}\n";
        while (!k1->Is_started){
            std::cout << ">" << std::flush;
            std::getline(std::cin, c);
            k1->CommandChange(c);

//            std::cout << "123124";
//            command += "";

//            else std::cout << "Sorry, mate, wrong command" << std::endl;
        }
    }
    return a.exec();
}
