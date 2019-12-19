#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Black;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[i].radius;
		wheel.height = info.wheels[i].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	//Chassis of the car
	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());
	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();
	chassis.color = Green;
	
	Cube connection(info.connection_size.x, info.connection_size.y, info.connection_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&connection.transform);
	btVector3 b_offset(info.connection_offset.x, info.connection_offset.y, info.connection_offset.z);
	b_offset = b_offset.rotate(q.getAxis(), q.getAngle());
	connection.transform.M[12] += b_offset.getX();
	connection.transform.M[13] += b_offset.getY();
	connection.transform.M[14] += b_offset.getZ();
	connection.color = Red;

	Cube wing(info.wing_size.x, info.wing_size.y, info.wing_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&wing.transform);
	btVector3 fw_offset(info.wing_offset.x, info.wing_offset.y, info.wing_offset.z);
	fw_offset = fw_offset.rotate(q.getAxis(), q.getAngle());
	wing.transform.M[12] += fw_offset.getX();
	wing.transform.M[13] += fw_offset.getY();
	wing.transform.M[14] += fw_offset.getZ();
	wing.color = Purple;

	Cube glass(info.glass_size.x, info.glass_size.y, info.glass_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&glass.transform);
	btVector3 u_offset(info.glass_offset.x, info.glass_offset.y, info.glass_offset.z);
	u_offset = u_offset.rotate(q.getAxis(), q.getAngle());
	glass.transform.M[12] += u_offset.getX();
	glass.transform.M[13] += u_offset.getY();
	glass.transform.M[14] += u_offset.getZ();


	chassis.Render();
	connection.Render();
	wing.Render();
	glass.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}
vec3 PhysVehicle3D::GetForwardVector() const
{
	btVector3 h = vehicle->getForwardVector();
	vec3 ret;
	ret.Set(h.getX(), h.getY(), h.getZ());
	return ret;
}
void PhysVehicle3D::GetRotation(float angle_r)
{
	
	float matrix[16];
	memset(matrix, 0.0f, sizeof(matrix));

	// Keep position
	vec3 p = GetPos();
	matrix[12] = p.x;
	matrix[13] = p.y;
	matrix[14] = p.z;
	matrix[15] = 1;

	// Rotate the body by angle_r
	matrix[0] = cos(angle_r);
	matrix[2] = -sin(angle_r);
	matrix[5] = 1;
	matrix[8] = sin(angle_r);
	matrix[10] = cos(angle_r);

	SetTransform(matrix);

}