#include "Core/EntryPoint.h"

class MyApplication : public Lamp::Application
{
public:
	virtual void init(int arhc, char** argv) override {}
	virtual void tick(double delta = 0.0) override {}
	virtual void shutdown() override {}
};

Lamp::Application* CreateApplication(int argc, char** argv)
{
	return new MyApplication;
}
