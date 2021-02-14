#pragma once
#include <gemcutter/Entity/Entity.h>
#include <gemcutter/Input/Input.h>
#include <gemcutter/Rendering/RenderPass.h>
#include <gemcutter/Resource/ConfigTable.h>

using namespace gem;

class Game
{
public:
	Game(ConfigTable& config);
	~Game();

	bool Init();

	void Update();
	void Draw();

private:
	/* Events */
	Listener<KeyPressed>  onKeyPressed;
	Listener<KeyReleased> onKeyReleased;
	Listener<MouseMoved>  onMouseMoved;

	/* Rendering */
	RenderPass mainRenderPass;

	/* Scene */
	Entity::Ptr camera = Entity::MakeNew("camera");
	Entity::Ptr root   = Entity::MakeNewRoot("root");
	Entity::Ptr sprite;

	/* Assets */
	// The config contains all the properties found in Settings.cfg.
	ConfigTable& config;
};
