#pragma once
#include "GameObject.h"
#include "Vector2.h"
#include "Matrix2D.h"
#include <cassert>

class MovingGameObject : public GameObject
{
public:
	MovingGameObject();
	~MovingGameObject();


	inline Vector2 Velocity() { return m_Velocity; };
	inline void SetVelocity(Vector2 Vel) { m_Velocity = Vel; };

	float Mass() { return m_Mass; };

	Vector2 SideVector() { return m_SideVector; };

	float MaxSpeed() { return m_MaxSpeed; };
	void SetMaxSpeed(float Speed) { m_MaxSpeed = Speed; };

	float MaxForce() { return m_MaxForce; };
	void SetMaxForce(float Force) { m_MaxForce = Force; };

	float Speed() { return m_Velocity.length(); };
	float SpeedSq() { return m_Velocity.lengthSq(); };

	Vector2 Heading() { return m_Heading; };
	void SetHeading(Vector2 NewHeading);
	
	bool RotateToFacePosition(Vector2 Target);

	float MaxTurnRate() { return m_MaxTurnRate; };
	void SetMaxTurnRate(float TurnRate) { m_MaxTurnRate = TurnRate; };

protected:

	Vector2 m_Velocity;
	Vector2 m_Heading;
	Vector2 m_SideVector;

	float m_Mass;

	float m_MaxSpeed;

	float m_MaxForce;

	float m_MaxTurnRate;


};

