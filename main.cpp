#include "console.hpp"
#include <QProcess>

int main(int argc, char** argv){
	int ExitCode = 1;
	while(ExitCode != 1337){
	    QCoreApplication app(argc, argv);
	    Console console;
	    console.run();
	    QObject::connect(&console, SIGNAL(Restart()), &app, SLOT(quit()));
	    ExitCode = app.exec();
	}	    
	return 0;
}
