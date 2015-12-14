#pragma once
class CPerson;

class CBuilder
{
public:
	CBuilder();
	~CBuilder();
	
	virtual void create_head(CPerson &person) = 0;
	virtual void create_arm(CPerson &person) = 0;
	virtual void create_leg(CPerson &person) = 0;
	virtual void create_body(CPerson &person) = 0;
	virtual void create_hair(CPerson &person) = 0;
	virtual void create_face(CPerson &person) = 0;
};

class CChildBuilder : public CBuilder
{
public:
	virtual void create_head(CPerson &person) ;

	virtual void create_arm(CPerson &person) ;

	virtual void create_leg(CPerson &person) ;

	virtual void create_body(CPerson &person) ;

	virtual void create_hair(CPerson &person) ;

	virtual void create_face(CPerson &person) ;

};

class CAdultBuilder : public CBuilder
{
public:

	virtual void create_arm(CPerson &person) ;

	virtual void create_body(CPerson &person) ;

	virtual void create_face(CPerson &person) ;

	virtual void create_hair(CPerson &person) ;

	virtual void create_head(CPerson &person) ;

	virtual void create_leg(CPerson &person) ;

};

class COldAdultBuilder : public CBuilder
{
public:

	virtual void create_arm(CPerson &person) override;

	virtual void create_body(CPerson &person) override;

	virtual void create_face(CPerson &person) override;

	virtual void create_hair(CPerson &person) override;

	virtual void create_head(CPerson &person) override;

	virtual void create_leg(CPerson &person) override;

};


