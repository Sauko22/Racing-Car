#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	CreateMap();
	App->camera->Move(vec3(0.0f, 4.0f, -12.5f));
	App->camera->LookAt(vec3(0, 0, 0));

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");
	map_objects.clear();
	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}
PhysBody3D* ModuleSceneIntro::CreateRectangle(vec3 position,  vec3 size, Color s_color, float mass)
{

	Cube* object = new Cube();

	object->SetPos(position.x, position.y, position.z);
	object->size = size;
	object->color = { ((float)(std::rand() % 255) / 255.f), ((float)(std::rand() % 255) / 255.f), ((float)(std::rand() % 255) / 255.f) };
	

	map_objects.add(*object);
	
	return App->physics->AddBody(*object, mass);
}

//void ModuleSceneIntro::CreateSensor(vec3 position, vec4 rotation, vec3 size, Color s_color, SENSORS s_type, vec3 mod, vec4 target_rotation)
//{
//
//	Cube* object = new Cube();
//
//	object->SetPos(position.x, position.y, position.z);
//	object->size = size;
//	object->color = s_color;
//	object->SetRotation(rotation.x, { rotation.y, rotation.z, rotation.w });
//	map_sensors.add(App->physics->AddSensor(*object, mod, s_type, target_rotation));
//
//}

void ModuleSceneIntro::CreateMap() {

	//primera recta derecha
	CreateRectangle({ 5,1,1 }, { 1, 4.0f, 1 }, Red,0);
	CreateRectangle({ 5,1,3 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,5 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,9 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,11 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,13}, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,15 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,17 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,19 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,21 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,23 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,25 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,27 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,29 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,31 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,33 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,35}, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,37 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,39 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,41}, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,43 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,45 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,47 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,49 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,51 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,53 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,55 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,57 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,59 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,61 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,63 }, { 1, 4.0f, 1 }, Red, 0);

	//primera recta izquierda
	CreateRectangle({ -5,1,1 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,3 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,5 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,9 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,11 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,13 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,15 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,17 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,19 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,21 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,23 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,25 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,27 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,29 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,31 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,33 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,35 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({-5,1,37 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,39 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,41 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,43 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,45 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,47 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,49 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,51 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,53 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,55 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,57 }, { 1, 4.0f, 1 }, Red, 0);
	
	//primera curva derecha
	CreateRectangle({ 4,1,65 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 3,1,67 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 2,1,69 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 1,1,71 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 0,1,73 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -1,1,75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -2,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -3,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -7,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -9,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -11,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -13,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -15,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -17,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -19,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -21,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -23,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -25,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -27,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -29,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -31,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -33,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -35,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -37,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -39,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -41,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -43,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -45,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -47,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -49,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -51,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -53,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -57,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -59,1,77 }, { 1, 4.0f, 1 }, Red, 0);

	//primera curva izquierda
	CreateRectangle({ -6,1,57 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -7,1,59 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -8,1,61 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -9,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -11,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -13,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -15,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -17,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -19,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -21,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -23,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -25,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -27,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -29,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -31,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -33,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -35,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -37,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -39,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -41,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -43,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -45,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -47,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -49,1,63 }, { 1, 4.0f, 1 }, Red, 0);

	//segunda curva derecha
	CreateRectangle({ -61,1,76 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -63,1,75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -65,1,74 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -67,1,73 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,72 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,70 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,68 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,66 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,64 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,62 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,60 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,58 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,56 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,54 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,52 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,50 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,48 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,46 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,44 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,42 }, { 1, 4.0f, 1 }, Red, 0);
	
	//segunda curva izquierda
	CreateRectangle({ -51,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -53,1,62 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,61 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,59 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,57 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,55 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,53 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,51 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,49 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,47 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,45 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,43 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,41 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,39 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,37 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,35 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,33 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,31 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,29 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,27 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,25 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,23 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,21 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,19 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,17 }, { 1, 4.0f, 1 }, Red, 0);

	//tercera curva derecha
	CreateRectangle({ -70,1,40 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -71,1,38 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -72,1,36 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -73,1,34 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -74,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -76,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -78,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -80,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -82,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -84,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -86,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -88,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -90,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -92,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -94,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -96,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -98,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	//tercera curva izquierda
	CreateRectangle({ -56,1,15 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -57,1,13 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -58,1,11 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -59,1,9 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -60,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -62,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -64,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -66,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -68,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -70,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -72,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -74,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -76,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -78,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -80,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -82,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -84,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	
	
	//cuarta curva derecha
	CreateRectangle({ -102,1,31 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -104,1,30 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -106,1,29 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -108,1,28 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -110,1,27 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -112,1,26 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -114,1,25 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,24 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,23 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,22 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,20 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,18 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,16 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,14 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,12 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,10 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,8 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,6 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,4 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,2 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,0 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-2 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-4 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-6 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-8 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-10 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-12 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-14 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-16 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-18 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-20 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-22 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-24 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-26 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-28 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-30 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-34}, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-36 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-38 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-40 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-42 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-44 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-46 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-48 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-50 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-52 }, { 1, 4.0f, 1 }, Red, 0);

	//Cuarta curva izquierda
	CreateRectangle({ -86,1,6 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -88,1,5 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -90,1,4 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -92,1,3 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -94,1,2 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -96,1,1 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -98,1,0 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-1 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-2 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-3 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-5 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-9 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-11 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-13}, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-15}, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-17}, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-19 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-21 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-23 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-25 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-27 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-29 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-31 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-33 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-35 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-37 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-39 }, { 1, 4.0f, 1 }, Red, 0);



}