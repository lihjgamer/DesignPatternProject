#pragma once

class CPerson;
class CBuilder;

class CDirector
{
private:
	CBuilder* m_pBuilder;
public:
	CDirector(CBuilder* pBuilder = nullptr);
	~CDirector();

	void set_builder(CBuilder* pBuilder);

	void create_person(CPerson& person);
};

