#include "rwepch.h"
#include "RWEApp.h"

#include "RWE/Log.h"

#include <glad/glad.h>

namespace RWE
{

#define BIND_EVENT_FN(x) std::bind(&RWEApp::x, this, std::placeholders::_1)

	RWEApp* RWEApp::s_Instance = nullptr;

	RWEApp::RWEApp()
	{
		RWE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	RWEApp::~RWEApp()
	{

	}

	void RWEApp::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void RWEApp::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void RWEApp::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}

	void RWEApp::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

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