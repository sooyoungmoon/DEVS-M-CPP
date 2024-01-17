
#include <Windows.h>
#include "Coupled.h"
#include <libloaderapi.h>
//#include <wtypes.h>


int main() {

	/* model loading */

	//HINSTANCE hModule = LoadLibrary("sampleModels");

	/* paramter loading */

	/* simulation loop */


	/* print messages for users */

	/* cleanup dynamically allocated memory */




	/* coupling 추가/제거 테스트 */
	/*
	Coupled c1;

	c1.insertCoupling("A", "in", "B", "in");
	c1.insertCoupling("B", "out", "A", "out");

	c1.removeCoupling("A", "in", "B", "in");
	*/
	return 0;
}