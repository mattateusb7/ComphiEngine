#pragma once
#include "Comphi/Core.h"
#include "../IInput.h"

#include <GLFW/glfw3.h>

namespace Comphi::Windows {

	class Input : public IInput
	{
	protected:
		virtual bool IsKeyPressedImpl(int KeyCode) override;
		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual std::pair<int, int> GetMousePosImpl() override;
		inline virtual int GetMouseXImpl() override { return GetMousePosImpl().first; };
		inline virtual int GetMouseYImpl() override { return GetMousePosImpl().second; }
	};


}