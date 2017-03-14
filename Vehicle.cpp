#include "Vehicle.h"
#include "SteeringBehaviours.h"


Vehicle::Vehicle()
{
}


Vehicle::~Vehicle()
{
}

void Vehicle::Update(float dt)
{
	//update the time elapsed
	m_TimeElapsed = dt;

	//keep a record of its old position so we can update its cell later
	//in this method
	Vector2 OldPos = m_Position;


	Vector2 SteeringForce;

	//calculate the combined force from each steering behavior in the 
	//vehicle's list
	SteeringForce = m_Steering->Calculate();

	//Acceleration = Force/Mass
	Vector2 acceleration = SteeringForce / m_Mass;

	//update velocity
	m_Velocity += acceleration * dt;

	//make sure vehicle does not exceed maximum velocity
	m_Velocity.truncate(m_MaxSpeed);

	//update the position
	m_Position += m_Velocity * dt;

	//update the heading if the vehicle has a non zero velocity
	if (m_Velocity.lengthSq() > 0.00000001)
	{
		Vector2 vel = m_Velocity;

		m_Heading = vel.normalize();

		m_SideVector = m_Heading.perp();
	}

	//EnforceNonPenetrationConstraint(this, World()->Agents());

	//treat the screen as a toroid
	WrapAround(m_Position, m_World->cxClient(), m_World->cyClient());

	//update the vehicle's current cell if space partitioning is turned on

	if (Steering()->isSpacePartitioningOn())
	{
		World()->CellSpace()->UpdateEntity(this, OldPos);
	}

	if (IsSmoothingOn())
	{
		m_SmoothedHeading = m_HeadingSmoother->Update(Heading());
	}

}
