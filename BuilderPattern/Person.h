#pragma once
class CPerson
{
public:
	CPerson();
	~CPerson();

	int Type() const { return m_type; }
	void Type(int val) { m_type = val; }

	int Sex() const { return m_sex; }
	void Sex(int val) { m_sex = val; }

	int Height() const { return m_height; }
	void Height(int val) { m_height = val; }

	int Weight() const { return m_weight; }
	void Weight(int val) { m_weight = val; }

	int Head_type() const { return m_head_type; }
	void Head_type(int val) { m_head_type = val; }

	int Arm_type() const { return m_arm_type; }
	void Arm_type(int val) { m_arm_type = val; }

	int Leg_type() const { return m_leg_type; }
	void Leg_type(int val) { m_leg_type = val; }

	int Body_type() const { return m_body_type; }
	void Body_type(int val) { m_body_type = val; }

	int Hair_type() const { return m_hair_type; }
	void Hair_type(int val) { m_hair_type = val; }

	int Face_type() const { return m_face_type; }
	void Face_type(int val) { m_face_type = val; }
private:
	int     m_type;	// С�� ������ ������

	int		m_sex;	// �Ա�

	int		m_height;	// ���

	int     m_weight;	// ����

	int     m_head_type;	// ͷģ��

	int     m_arm_type;		// �첲ģ��

	int     m_leg_type;		// ��ģ��

	int     m_body_type;	// ����ģ��

	int     m_hair_type;	// ͷ��ģ��

	int     m_face_type;	// ��ģ��

};

