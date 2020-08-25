//#include "View/MyCLIView.h"
#include "View/MyCLIView.h"
#include "Controller/MyController.h"


int main() {

	Controller* controller = new MyController();

	MyCLIView view(std::cin, std::cout);
	view.setController(controller);
	
	view.start();

	return 0;
}
