#include "cg/cg.h"
#include "MainApp.h"

int main(int argc, char** argv) {
	cg::Manager::instance()->runApp(new proj::MainApp(),60,argc,argv);
	return 0;
}