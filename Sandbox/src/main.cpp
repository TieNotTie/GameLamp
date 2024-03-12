#include "GameLamp.h"

using namespace ::Lamp;

class UserEventHandling : public Lamp::IKeyEventHandler
						, public Lamp::IMouseEventHandler
{
public:
	void onKeyPressed(const KeyEvent& e) override
	{
		//GL_CLIENT_INFO("UserEventHandling::onKeyPressed: Key: {}, IsShiftModifier: {}", e.getKey().getName(), e.isAnyShiftDown())
	}
	void onKeyReleased(const KeyEvent& e) override
	{
		if (e.getKey() == EKeys::A)
		{
			GL_CLIENT_INFO("UserEventHandling::onKeyReleased: Key: {}, IsShiftModifier: {}", e.getKey().getName(), e.isAnyShiftDown())
		}
	}
	void onKeyHold(const KeyEvent& e) override
	{
		//GL_CLIENT_INFO("UserEventHandling::onKeyHold: Key: {}, IsShiftModifier: {}", e.getKey().getName(), e.isAnyShiftDown())
	}

public:
	virtual void onMouseButtonPressed(const MouseButtonEvent& e) override
	{
		//GL_CLIENT_INFO("UserEventHandling::onMouseButtonPressed: Key: {}, MousePosition: X: {}, Y: {}", e.getKey().getName(), e.getCurrentMousePosition().X, e.getCurrentMousePosition().X);
	}
	virtual void onMouseButtonReleased(const MouseButtonEvent& e) override
	{
		//GL_CLIENT_INFO("UserEventHandling::onMouseButtonReleased: Key: {}, MousePosition: X: {}, Y: {}", e.getKey().getName(), e.getCurrentMousePosition().X, e.getCurrentMousePosition().X);
	}
	virtual void onMouseButtonHold(const MouseButtonEvent& e) override
	{
		//GL_CLIENT_INFO("UserEventHandling::onMouseButtonHold: Key: {}, MousePosition: X: {}, Y: {}", e.getKey().getName(), e.getCurrentMousePosition().X, e.getCurrentMousePosition().X);
	}

	virtual void onMouseWheelScrolled(double offset, const ModifierKeysState&) override
	{
		//GL_CLIENT_INFO("UserEventHandling::onMouseWheelScrolled: Offset: {}", offset);
	}

	virtual void onMouseMoved(const Position2D& currentPosition, const Position2D& deltaMouseMovement, const ModifierKeysState& modifierKeys) override
	{
		//GL_CLIENT_INFO("UserEventHandling::onMouseMoved: CurrentPos: X: {}; Y: {}, Delta: X: {}, Y: {}", currentPosition.X, currentPosition.Y, deltaMouseMovement.X, deltaMouseMovement.Y);
	}
};

class UserApplicationTick
{
public:
	void tick();
};

class UserApplicationTick;

class MyApplication : public Lamp::Application
{
public:
	MyApplication(int argc, char** argv)
		: Lamp::Application(argc, argv)
	{
		// TODO: Research how to move this to base class
		init(argc, argv);
	}

	virtual void init(int argc, char** argv) override 
	{
		auto tmp = std::make_shared<UserEventHandling>();

		addUserInputKeyEventHandler(tmp);
		addUserInputMouseEventHandler(tmp);

	}
	virtual void tick(double delta = 0.0) override 
	{ 
		m_UserApplicationTick.tick();
	}
	virtual void shutdown() override { GL_CORE_INFO("MyApplication::Shutdown"); }

private:
	UserApplicationTick m_UserApplicationTick;
};

Lamp::Application* CreateApplication(int argc, char** argv)
{
	return new MyApplication(argc, argv);
}

void UserApplicationTick::tick()
{
	if (MyApplication::isKeyPressed(Lamp::EKeys::A))
	{
		GL_CLIENT_INFO("'A' is Pressed!");
	}
}