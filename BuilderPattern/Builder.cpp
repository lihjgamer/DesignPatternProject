#include "Builder.h"
#include "Person.h"

CBuilder::CBuilder()
{
}


CBuilder::~CBuilder()
{
}

void CChildBuilder::create_head(CPerson &person)
{
	person.Head_type(1);
}

void CChildBuilder::create_arm(CPerson &person)
{
	person.Arm_type(1);
}

void CChildBuilder::create_leg(CPerson &person)
{
	person.Leg_type(1);
}

void CChildBuilder::create_body(CPerson &person)
{
	person.Body_type(1);
}

void CChildBuilder::create_hair(CPerson &person)
{
	person.Hair_type(1);
}

void CChildBuilder::create_face(CPerson &person)
{
	person.Face_type(1);
}

void CAdultBuilder::create_arm(CPerson &person)
{
	person.Arm_type(2);
}

void CAdultBuilder::create_body(CPerson &person)
{
	person.Body_type(2);
}

void CAdultBuilder::create_face(CPerson &person)
{
	person.Face_type(2);
}

void CAdultBuilder::create_hair(CPerson &person)
{
	person.Hair_type(2);
}

void CAdultBuilder::create_head(CPerson &person)
{
	person.Head_type(2);
}

void CAdultBuilder::create_leg(CPerson &person)
{
	person.Leg_type(2);
}

void COldAdultBuilder::create_arm(CPerson &person)
{
	person.Arm_type(3);
}

void COldAdultBuilder::create_body(CPerson &person)
{
	person.Body_type(3);
}

void COldAdultBuilder::create_face(CPerson &person)
{
	person.Face_type(3);
}

void COldAdultBuilder::create_hair(CPerson &person)
{
	person.Hair_type(3);
}

void COldAdultBuilder::create_head(CPerson &person)
{
	person.Head_type(3);
}

void COldAdultBuilder::create_leg(CPerson &person)
{
	person.Leg_type(3);
}
