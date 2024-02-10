#include "Window/Window.h"

struct GLFWwindow;

namespace Lamp {

	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProperties& props);
		virtual ~WindowsWindow();

		virtual void tick(double delta = 0.0) override;

		virtual uint32_t getWidth() const override;
		virtual uint32_t getHeight() const override;

		virtual void setWidth(uint32_t width) override;
		virtual void setHeight(uint32_t height) override;

		virtual bool isVSync() const override;
		virtual void setVSync(bool) override;

		virtual void* getNativeWindow() const override;

	private:
		void init(const WindowProperties& props);
		void shutdown();

	private:
		GLFWwindow* m_Window;

		WindowProperties m_WindowProperties;
	};

}
