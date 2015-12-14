#include "Director.h"
#include "Person.h"
#include "Builder.h"

CDirector::CDirector(CBuilder* pBuilder)
{
	m_pBuilder = pBuilder;
}


CDirector::~CDirector()
{
}

void CDirector::create_person(CPerson& person)
{
	if (m_pBuilder == nullptr)
	{
		return;
	}
	m_pBuilder->create_arm(person);
	m_pBuilder->create_body(person);
	m_pBuilder->create_face(person);
	m_pBuilder->create_hair(person);
	m_pBuilder->create_head(person);
	m_pBuilder->create_leg(person);
}

void CDirector::set_builder(CBuilder* pBuilder)
{
	m_pBuilder = pBuilder;
}
