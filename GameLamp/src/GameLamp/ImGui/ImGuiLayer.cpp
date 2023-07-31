#include "pch.h"
#include "ImGuiLayer.h"

#include "GameLamp/Core/Application.h"
#include "GameLamp/Core/Timestep.h"

#include "backends/imgui_impl_opengl3.h"
#include "backends/imgui_impl_glfw.h"

#include <imgui.h>

#include <glad/glad.h>
#include <glfw/glfw3.h> 

namespace GameLamp {

	ImGuiLayer::ImGuiLayer()
		: Layer("ImGuiLayer")
	{
	}

	ImGuiLayer::~ImGuiLayer()
	{

	}

	void ImGuiLayer::onAttach()
	{
		// Setup Dear ImGui context
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
		//io.ConfigViewportsNoAutoMerge = true;
		//io.ConfigViewportsNoTaskBarIcon = true;

		// Setup Dear ImGui style
		ImGui::StyleColorsDark();
		//ImGui::StyleColorsLight();

		// When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
		ImGuiStyle& style = ImGui::GetStyle();
		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			style.WindowRounding = 0.0f;
			style.Colors[ImGuiCol_WindowBg].w = 1.0f;
		}

		Application& app = Application::get();
		GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().getNativeWindow());

		// Setup Platform/Renderer backends
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		ImGui_ImplOpenGL3_Init("#version 410");
	}

	void ImGuiLayer::onDetach()
	{
		ImGui_ImplOpenGL3_Shutdown();
		ImGui_ImplGlfw_Shutdown();
		ImGui::DestroyContext();
	}

	void ImGuiLayer::begin()
	{
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
	}

	void ImGuiLayer::end()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::get();
		io.DisplaySize = ImVec2((float)app.getWindow().getWidth(), (float)app.getWindow().getHeight());

		// Rendering
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			GLFWwindow* backup_current_context = glfwGetCurrentContext();
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
			glfwMakeContextCurrent(backup_current_context);
		}

	}

	float calculateFPS()
	{
		static float LastTime = 0.0f;
		float CurrentTime = Time::getSystemTime();
		float FrameTime = (CurrentTime - LastTime) * 1000.0f;
		LastTime = CurrentTime;

		if (FrameTime == 0) FrameTime = 0.001f;

		return 1000.0f / FrameTime;
	}

	ImVec4&& getTextColor(float FPS)
	{
		if (FPS < 59.0f) return std::move(ImVec4(1.0f, 0.0f, 0.0f, 1.0f));
		else if (FPS < 99.0f) return std::move(ImVec4(1.0f, 0.65f, 0.0f, 1.0f));
		else return std::move(ImVec4(0.0f, 0.5f, 0.0f, 1.0f));
	}

	void ImGuiLayer::drawFpsCounter()
	{
		static constexpr ImGuiWindowFlags imGuiWindowFlags = 
			  ImGuiWindowFlags_NoBackground
			| ImGuiWindowFlags_NoTitleBar
			| ImGuiWindowFlags_NoResize
			| ImGuiWindowFlags_NoScrollbar
			| ImGuiWindowFlags_NoCollapse
			| ImGuiWindowFlags_AlwaysAutoResize
			| ImGuiWindowFlags_NoMouseInputs
			| ImGuiWindowFlags_NoFocusOnAppearing
			| ImGuiWindowFlags_NoBringToFrontOnFocus
			| ImGuiWindowFlags_NoDocking;
		
		// Limit counter updating on screen
		static constexpr float UpdateRate = 0.2f;

		// This calculation may be inaccurate 
		static float LastUpdatedTime = 0.0f;
		static float FPS = 0.0f;
		float CurrentTime = Time::getSystemTime();

		if (CurrentTime - LastUpdatedTime >= UpdateRate)
		{
			LastUpdatedTime = CurrentTime;
			FPS = calculateFPS();
		} else calculateFPS();


		// Rework Min and Max displaying: Min And Max should display values only for last N seconds, for example for the last 1 minute
		//static float MinFps = FPS;
		//static float MaxFps = FPS;

		//MinFps = MinFps > FPS ? FPS : MinFps;
		//MaxFps = MaxFps < FPS ? FPS : MaxFps;


		ImGui::SetNextWindowPos(ImGui::GetWindowPos(), ImGuiCond_Always, { 0.5f, 0.5f });
		ImGui::Begin("FPS Counter", (bool*)0, imGuiWindowFlags);
		{
			//ImGui::SetWindowFontScale(1.2f);
			ImGui::TextColored(getTextColor(FPS), "FPS: %3.0f", FPS);
			//ImGui::TextColored(getTextColor(MinFps), "Min: %3.0f", MinFps);
			//ImGui::TextColored(getTextColor(MaxFps), "Max: %3.0f", MaxFps);
		}
		ImGui::End();
	}



	void ImGuiLayer::onImGuiRender()
	{

		drawFpsCounter();

		ImGui::Begin("Renderer");

		//GL_CORE_INFO("OpenGL Info:");
		//GL_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		//GL_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		//GL_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		ImGui::Text("Vendor: %s", glGetString(GL_VENDOR));
		ImGui::Text("Renderer: %s", glGetString(GL_RENDERER));
		ImGui::Text("Version: %s", glGetString(GL_VERSION));

		//ImGui::ColorEdit3("ColorPicker", (float*)&color, ImGuiColorEditFlags_Uint8);

		ImGui::End();
	}

} // namespace GameLamp 
