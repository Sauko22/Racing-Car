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

	p2List_item<Primitive*>* item = map_objects.getFirst();
	while (item) 
	{
		item->data->Render();
		item = item->next;
	
	
	}
	//Music list

	if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
	{
		App->audio->stopMusic();
		sanic = App->audio->PlayMusic("Music/sanic.ogg");
	}
	if (App->input->GetKey(SDL_SCANCODE_2) == KEY_DOWN)
	{
		App->audio->stopMusic();
		top = App->audio->PlayMusic("Music/top.ogg");
	}
	if (App->input->GetKey(SDL_SCANCODE_3) == KEY_DOWN)
	{
		App->audio->stopMusic();
		take = App->audio->PlayMusic("Music/take.ogg");
	}
	if (App->input->GetKey(SDL_SCANCODE_4) == KEY_DOWN)
	{
		App->audio->stopMusic();
		willy = App->audio->PlayMusic("Music/willy.ogg");
	}
	if (App->input->GetKey(SDL_SCANCODE_5) == KEY_DOWN)
	{
		App->audio->stopMusic();
		españita = App->audio->PlayMusic("Music/espanita.ogg");
	}
	if (App->input->GetKey(SDL_SCANCODE_6) == KEY_DOWN)
	{
		App->audio->stopMusic();
		us = App->audio->PlayMusic("Music/us.ogg");
	}
	
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
	object->color = s_color;
	

	map_objects.add(object);
	
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

	
	CreateRectangle({ 5,1,1 }, { 1, 4.0f, 1 }, Red,0);
	CreateRectangle({ 5,1,3 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,5 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,3,7 }, { 1, 8.0f, 1 }, Purple, 0);
	CreateRectangle({ 5,1,9 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,11 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,13}, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,15 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,17 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,19 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,21 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,23 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,25 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,27 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,29 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,31 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,33 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,35}, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,37 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,39 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,41}, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,43 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,45 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,47 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,49 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,51 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,53 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,55 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,57 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,59 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,61 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,63 }, { 1, 4.0f, 1 }, White, 0);

	
	CreateRectangle({ -5,1,1 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,3 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,5 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,3,7 }, { 1, 8.0f, 1 }, Purple, 0);
	CreateRectangle({ -5,1,9 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,11 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,13 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,15 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,17 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,19 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,21 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,23 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,25 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,27 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,29 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,31 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,33 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,35 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({-5,1,37 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,39 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,41 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,43 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,45 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,47 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,49 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,51 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,53 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,55 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,57 }, { 1, 4.0f, 1 }, Red, 0);
	
	CreateRectangle({ 4,1,65 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 3,1,67 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 2,1,69 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 1,1,71 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 0,1,73 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -1,1,75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -2,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -3,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -7,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -9,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -11,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -13,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -15,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -17,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -19,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -21,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -23,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -25,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -27,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -29,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -31,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -33,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -35,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -37,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -39,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -41,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -43,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -45,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -47,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -49,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -51,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -53,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,77 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -57,1,77 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -59,1,77 }, { 1, 4.0f, 1 }, White, 0);

	
	CreateRectangle({ -6,1,57 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -7,1,59 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -8,1,61 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -9,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -11,1,63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -13,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -15,1,63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -17,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -19,1,63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -21,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -23,1,63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -25,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -27,1,63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -29,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -31,1,63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -33,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -35,1,63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -37,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -39,1,63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -41,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -43,1,63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -45,1,63 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -47,1,63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -49,1,63 }, { 1, 4.0f, 1 }, Red, 0);


	CreateRectangle({ -61,1,76 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -63,1,75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -65,1,74 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -67,1,73 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -69,1,72 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,70 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -69,1,68 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,66 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -69,1,64 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,62 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -69,1,60 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,58 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -69,1,56 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,54 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -69,1,52 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,50 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -69,1,48 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,46 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -69,1,44 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,42 }, { 1, 4.0f, 1 }, White, 0);
	
	
	CreateRectangle({ -51,1,63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -53,1,62 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,61 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,59 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,57 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,55 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,53 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,51 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,49 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,47 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,45 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,43 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,41 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,39 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,37 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,35 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,33 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,31 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,29 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,27 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,25 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,23 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,21 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,19 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -55,1,17 }, { 1, 4.0f, 1 }, White, 0);

	
	CreateRectangle({ -70,1,40 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -71,1,38 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -72,1,36 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -73,1,34 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -74,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -76,1,32 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -78,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -80,1,32 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -82,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -84,1,32 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -86,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -88,1,32 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -90,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -92,1,32 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -94,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -96,1,32 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -98,1,32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,32 }, { 1, 4.0f, 1 }, White, 0);

	CreateRectangle({ -56,1,15 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -57,1,13 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -58,1,11 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -59,1,9 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -60,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -62,1,7 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -64,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -66,1,7 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -68,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -70,1,7 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -72,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -74,1,7 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -76,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -78,1,7 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -80,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -82,1,7 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -84,1,7 }, { 1, 4.0f, 1 }, Red, 0);
	
	
	
	CreateRectangle({ -102,1,31 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -104,1,30 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -106,1,29 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -108,1,28 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -110,1,27 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -112,1,26 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -114,1,25 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,24 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,23 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,22 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,20 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,18 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,16 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,14 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,12 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,10 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,8 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,6 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,4 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,2 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,0 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-2 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-4 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-6 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-8 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-10 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-12 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-14 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-16 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-18 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-20 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-22 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-24 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-26 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-28 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-30 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-32 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-34}, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-36 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-38 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-40 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-42 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-44 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-46 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-48 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-50 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-52 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-54 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-56 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-58 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-60 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-62 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-64 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-66 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-68 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-70 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -116,1,-72 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -116,1,-74 }, { 1, 4.0f, 1 }, White, 0);
	


	
	CreateRectangle({ -86,1,6 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -88,1,5 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -90,1,4 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -92,1,3 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -94,1,2 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -96,1,1 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -98,1,0 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-1 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-2 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-3 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-5 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-7 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-9 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-11 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-13}, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-15}, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-17}, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-19 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-21 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-23 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-25 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-27 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-29 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-31 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-33 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-35 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-37 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-39 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-41 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-43 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-45 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-47 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-49 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-51 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-53 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-55 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-57 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-59 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -100,1,-61 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -100,1,-63 }, { 1, 4.0f, 1 }, Red, 0);

	
	CreateRectangle({ -115,1,-76 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -114,1,-78 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -113,1,-80 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -112,1,-82 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -111,1,-84 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -110,1,-86 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -109,1,-88 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -108,1,-90 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -107,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -105,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -103,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -101,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -99,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -97,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -95,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -93,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -91,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -89,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -87,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -85,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -83,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -81,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -79,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -77,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -75,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -73,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -71,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -69,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -67,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -65,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -63,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -61,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -59,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -57,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -55,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -53,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -51,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -49,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -47,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -45,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -43,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -41,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -39,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -37,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -35,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -33,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -31,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -29,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -27,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -25,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -23,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -21,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -19,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -17,1,-92 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -15,1,-92 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -13,1,-92 }, { 1, 4.0f, 1 }, White, 0);

	
	CreateRectangle({ -99,1,-65 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -98,1,-67 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -97,1,-69 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -96,1,-71 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -95,1,-73 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -94,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -92,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -90,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -88,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -86,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -84,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -82,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -80,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -78,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -76,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -74,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -72,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -70,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -68,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -66,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -64,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -62,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -60,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -58,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -56,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -54,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -52,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -50,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -48,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -46,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -44,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -42,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -40,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -38,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -36,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -34,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -32,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -30,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -28,1,-75 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -24,1,-75 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -22,1,-75 }, { 1, 4.0f, 1 }, Red, 0);


   
	CreateRectangle({ -12,1,-90 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -11,1,-88 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -10,1,-86 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -9,1,-84 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -8,1,-82 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -7,1,-80 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -6,1,-78 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-76 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -4,1,-74 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -3,1,-72 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -2,1,-70 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -1,1,-68 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 0,1,-66 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 1,1,-64 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 2,1,-62 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 3,1,-60 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 4,1,-58 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-56 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-54 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-52 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-50 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-48 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-46 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-44 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-42 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-40 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-38 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-36 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-34 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-32 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-30 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-28 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-26 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-24 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-22 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-20 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-18 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-16 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-14 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-12 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-10 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-8 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-6 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ 5,1,-4 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ 5,1,-2 }, { 1, 4.0f, 1 }, Red, 0);
	
	
	CreateRectangle({ -21,1,-73 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -20,1,-71 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -19,1,-69 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -18,1,-67 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -17,1,-65 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -16,1,-63 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -14,1,-61 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -13,1,-59 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -12,1,-57 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -11,1,-55 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -10,1,-53 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -9,1,-51}, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -8,1,-49 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -7,1,-47 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -6,1,-45 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-43 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,-41 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-39 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,-37 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-35 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,-33 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-31 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,-29 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-27 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,-25 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-23 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,-21 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-19 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,-17 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-15 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,-13 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-11 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,-9 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-7 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,-5 }, { 1, 4.0f, 1 }, Red, 0);
	CreateRectangle({ -5,1,-3 }, { 1, 4.0f, 1 }, White, 0);
	CreateRectangle({ -5,1,-1 }, { 1, 4.0f, 1 }, Red, 0);

	


}