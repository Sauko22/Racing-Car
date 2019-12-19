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
	/*void CreateSensor(vec3 position, vec4 rotation, vec3 size, Color s_color, SENSORS s_type, vec3 mod, vec4 target_rotation);*/
public:
	/*
	PhysBody3D* pb_snake[MAX_SNAKE];
	Sphere s_snake[MAX_SNAKE];

	PhysBody3D* pb_snake2[MAX_SNAKE];
	Sphere s_snake2[MAX_SNAKE];
	*/

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

	/*p2List<PhysSensor3D> map_sensors;*/
};
