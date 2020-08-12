#pragma once
#include "Event.h"

namespace Comphi {

	class MouseMovedEvent : public Event
	{
	public:

		MouseMovedEvent(Uint posX, Uint posY) 
			: m_posX(posX), m_posY(posY){}

		inline Uint GetX() { return m_posX; };
		inline Uint GetY() { return m_posY; };

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << m_posX << "," << m_posY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

	private:
		Uint m_posX, m_posY;
	};
	
	class MouseScrolledEvent : public Event
	{
	public:

		MouseScrolledEvent(double offsetX, double offsetY)
			: m_offsetX(offsetX), m_offsetY(offsetY){}

		inline double GetOffsetX() { return m_offsetX; };
		inline double GetOffsetY() { return m_offsetY; };

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: (" << m_offsetX << "," << m_offsetY << ")";
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouse);

	private:
		double m_offsetX, m_offsetY;
	};


	class MouseButtonEvent : public Event
	{
	public:

		inline Uint GetMouseButton() { return m_button; };

		EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryMouseButton);
	
	protected :
		MouseButtonEvent(int button)
			: m_button(button) {}

		Uint m_button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button){}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed);

	};
	
	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:

		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button){}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased);

	};

}