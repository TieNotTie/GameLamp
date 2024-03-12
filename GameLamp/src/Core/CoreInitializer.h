#pragma once

namespace Lamp {

	class CoreInitializer
	{
	private:
		CoreInitializer() = delete;
		CoreInitializer(const CoreInitializer&) = delete;
		void operator==(const CoreInitializer&) = delete;
	
	public:
		// Create and initialize all core components
		static void InitCoreModules();
	private:

	};

}
