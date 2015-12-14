#include <stdio.h>
#include <stdlib.h>
#include "Builder.h"
#include "Person.h"
#include "Director.h"


int main(int argc, char** argv)
{
	CDirector director;

	CAdultBuilder adultbuilder;
	COldAdultBuilder oldadultbuilder;
	CChildBuilder childbuilder;

	CPerson child;
	CPerson adult;
	CPerson oldadult;

	director.set_builder(&childbuilder);
	director.create_person(child);

	director.set_builder(&adultbuilder);
	director.create_person(adult);

	director.set_builder(&oldadultbuilder);
	director.create_person(oldadult);

	system("pause");
	return 0;
}