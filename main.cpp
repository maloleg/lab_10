#include "console.hpp"
#include <QProcess>

int main(int argc, char** argv)
{
	// int result = 0;
	// do{


	    QCoreApplication app(argc, argv);

	    Console console;
	    console.run();
	    // QObject::connect(&console, SIGNAL(quit()), &app, SLOT(quit()));
	    // if (console.Is_started) emit console.If_St();
	    // std::cout << "123";
	    // sleep(50);
	    app.exec();
	// } while (result != 1337);

	// return result;
}
