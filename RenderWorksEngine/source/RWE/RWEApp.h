#pragma once

#include "Core.h"

#include "Window.h"
#include "RWE/LayerStack.h"
#include "RWE/Events/Event.h"
#include "RWE/Events/ApplicationEvent.h"


namespace RWE {

	class RWE_API RWEApp
	{
	public:
		RWEApp();
		virtual ~RWEApp();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }

		inline static RWEApp& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;

		static RWEApp* s_Instance;
	};

	// Projects that use RWE must define this function.
	RWEApp* CreateRWEApp();

}

