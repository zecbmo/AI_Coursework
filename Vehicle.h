#pragma once
#include "MovingGameObject.h"
#include "Smoother.h"

class GameWorld;
class SteeringBehaviour;

class Vehicle :	public MovingGameObject
{
public:
	Vehicle();
	~Vehicle();


	//updates the vehicle's position and orientation
	void Update(float dt);



	//-------------------------------------------accessor methods
	SteeringBehaviour*const  Steering()const { return m_Steering; }
	GameWorld*const         World()const { return m_World; }


	Vector2    SmoothedHeading()const { return m_SmoothedHeading; }

	bool IsSmoothingOn()const { return m_SmoothingOn; }
	void  SmoothingOn() { m_SmoothingOn = true; }
	void  SmoothingOff() { m_SmoothingOn = false; }
	void  ToggleSmoothing() { m_SmoothingOn = !m_SmoothingOn; }

	float TimeElapsed()const { return m_TimeElapsed; }


private:

	//a pointer to the world data. So a vehicle can access any obstacle,
	//path, wall or agent data
	GameWorld* m_World;

	//the steering behavior class
	SteeringBehaviour* m_Steering;


	//some steering behaviors give jerky looking movement. The
	//following members are used to smooth the vehicle's heading
	Smoother<Vector2>* m_HeadingSmoother;

	//this vector represents the average of the vehicle's heading
	//vector smoothed over the last few frames
	Vector2 m_SmoothedHeading;

	//when true, smoothing is active
	bool m_SmoothingOn;


	//keeps a track of the most recent update time. (some of the
	//steering behaviors make use of this - see Wander)
	float m_TimeElapsed;


	//buffer for the vehicle shape
	std::vector<Vector2> m_vecVehicleVB;




};

