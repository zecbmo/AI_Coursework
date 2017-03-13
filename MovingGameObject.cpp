#include "MovingGameObject.h"



MovingGameObject::MovingGameObject()
{
}


MovingGameObject::~MovingGameObject()
{
	
}

void MovingGameObject::SetHeading(Vector2 NewHeading)
{
	assert((NewHeading.lengthSq() - 1.0) < 0.00001);

	m_Heading = NewHeading;

	//the side vector must always be perpendicular to the heading
	m_SideVector = m_Heading.perp();
}

bool MovingGameObject::RotateToFacePosition(Vector2 Target)
{

	Vector2 toTarget = Target - m_Position;
	toTarget.normalize();

	float angle = acos(m_Heading.dot(toTarget));

	if (angle < 0.0001)
	{
		return true;
	}

	if (angle > m_MaxTurnRate)
	{
		angle = m_MaxTurnRate;
	}

	Matrix2D RotationMatrix;

	RotationMatrix.Rotate(angle * m_Heading.sign(toTarget));
	RotationMatrix.TransformVector2Ds(m_Heading);
	RotationMatrix.TransformVector2Ds(m_Velocity);


	return false;
}
