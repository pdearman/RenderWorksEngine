#include "rwepch.h"
#include "RWEApp.h"

#include <GLFW/glfw3.h>

namespace RWE
{

#define BIND_EVENT_FN(x) std::bind(&RWEApp::x, this, std::placeholders::_1)

	RWEApp::RWEApp()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	RWEApp::~RWEApp()
	{

	}

	void RWEApp::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
	}

	void RWEApp::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	void RWEApp::OnEvent(Event& e)
	{
		RWE_CORE_TRACE("Event: {0}", e);

		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(RWEApp::OnWindowClose));
		//dispatcher.Dispatch<WindowResizeEvent>(BIND_EVENT_FN(RWEApp::OnWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
	}

	void RWEApp::Run()
	{
		while (m_Running)
		{
			//glClearColor(1, 0, 1, 1);
			//glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : m_LayerStack)
				layer->OnUpdate();

			m_Window->OnUpdate();
		}
	}

	bool RWEApp::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}