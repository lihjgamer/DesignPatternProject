#include <stdio.h>
#include <stdlib.h>
#include "Builder.h"
#include "Person.h"
#include "Director.h"


int main(int argc, char** argv)
{
	
	CDirector director;

	CPerson child;
	CPerson adult;
	CPerson oldadult;

	CChildBuilder childbuilder;
	director.set_builder(&childbuilder);
	director.create_person(child);

	CAdultBuilder adultbuilder;
	director.set_builder(&adultbuilder);
	director.create_person(adult);

	COldAdultBuilder oldadultbuilder;
	director.set_builder(&oldadultbuilder);
	director.create_person(oldadult);


	system("pause");
	return 0;
}