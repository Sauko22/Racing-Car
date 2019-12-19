#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"
#include "Primitive.h"

#define MAX_SNAKE 2

struct PhysBody3D;
struct PhysMotor3D;
enum SENSORS {
	s_type

};

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt);
	bool CleanUp();

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2);
	PhysBody3D* CreateRectangle(vec3 position, vec3 size, Color s_color, float mass);

	void CreateMap();
	void Radio();
	void CreateObstacle();
	
public:
	
	PhysBody3D* pb_chassis;
	Cube p_chassis;

	PhysBody3D* pb_wheel;
	Cylinder p_wheel;

	PhysBody3D* pb_wheel2;
	Cylinder p_wheel2;

	PhysMotor3D* left_wheel;
	PhysMotor3D* right_wheel;

	

	
	p2List<Primitive*> map_objects;
	//Music hits
	unsigned int  sanic = 0;
	unsigned int  top = 0;
	unsigned int  take = 0;
	unsigned int  willy = 0;
	unsigned int  españita = 0;
	unsigned int  us = 0;
	unsigned int  giorno = 0;
	unsigned int  juju = 0;

	
};
