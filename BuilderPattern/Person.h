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
	int     m_type;	// 小孩 、大人 、老人

	int		m_sex;	// 性别

	int		m_height;	// 身高

	int     m_weight;	// 体重

	int     m_head_type;	// 头模型

	int     m_arm_type;		// 胳膊模型

	int     m_leg_type;		// 腿模型

	int     m_body_type;	// 身体模型

	int     m_hair_type;	// 头发模型

	int     m_face_type;	// 脸模型

};

