#include "Game.h"

#include <gemcutter/Application/Application.h>
#include <gemcutter/Application/Logging.h>
#include <gemcutter/Entity/Hierarchy.h>
#include <gemcutter/Rendering/Camera.h>
#include <gemcutter/Rendering/Rendering.h>
#include <gemcutter/Rendering/Sprite.h>
#include <gemcutter/Resource/Material.h>
#include <gemcutter/Sound/SoundListener.h>

Game::Game(ConfigTable& _config)
	: config(_config)
{
	// Basic initialization here.
	// ...
}

Game::~Game()
{
	// Cleanup here.
	// ...
}

bool Game::Init()
{
	// Load game assets here...
	auto logo = Load<Material>("materials/Logo");

	// Set up the camera. It is also the listener for all sound in the scene.
	camera->Add<SoundListener>();
	camera->Add<Camera>(60.0f, Application.GetAspectRatio(), 1.0f, 1000.0f);
	camera->LookAt(vec3(0.0f, 0.75f, 2.0f), vec3(0.0f));

	// Set up the scene.
	sprite = root->Get<Hierarchy>().CreateChild();
	sprite->Add<Sprite>(Alignment::Center, false, logo);

	// Set up the renderer.
	mainRenderPass.SetCamera(camera);

	// Set the background color to cornflower blue.
	SetClearColor(0.35f, 0.7f, 0.9f, 0.0f);

	// Bind input events.
	onKeyPressed = [](const KeyPressed& event)
	{
		switch (event.key)
		{
		case Key::Escape:
			Application.Exit();
			break;
		}
	};

	onKeyReleased = [](const KeyReleased& event)
	{
		// ...
	};

	onMouseMoved = [](const MouseMoved& event)
	{
		//...
	};

	return true;
}

void Game::Update()
{
	// The amount of time in seconds that has passed since the last update.
	float deltaTime = Application.GetDeltaTime();

	// Update entities and game logic...
	sprite->RotateY(deltaTime * -35.0f);

	// Engine systems and components are updated here.
	Application.UpdateEngine();
}

void Game::Draw()
{
	ClearBackBuffer();

	// Render the scene starting from the root entity.
	mainRenderPass.Bind();
	mainRenderPass.RenderRoot(*root);
}
