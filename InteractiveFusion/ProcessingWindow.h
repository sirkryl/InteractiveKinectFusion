#pragma once
#include "SubWindow.h"
#include "ButtonSlider.h"
namespace InteractiveFusion {

	class ProcessingWindowEvent : public SubWindowEvent{
	public:
		enum Type {
			FillHoles = SubWindowEvent::Last,
			RemoveComponents,
			Reset,
			Last
		};
	};

	class ProcessingWindow :
		public SubWindow
	{
	public:
		ProcessingWindow();
		virtual ~ProcessingWindow();

		virtual void Initialize(HWND _parentHandle, HINSTANCE _hInstance, float _marginTop, float _marginBottom, float _marginRight, float _marginLeft, std::wstring _className, ColorInt _backgroundColor);

		virtual void HandleEvents(MainWindow& _parentWindow);

		virtual void Resize(int parentWidth, int parentHeight);
		virtual void CleanUp();
		virtual LRESULT CALLBACK SubWindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


	private:
		virtual void ProcessUI(WPARAM wParam, LPARAM lParam);
		void UpdateProcessingValues();

		enum SliderType { HoleSize, ComponentSize};
		std::unordered_map<SliderType, ButtonSlider> sliderMap;
		int maxHoleSizeToBeClosed = 50000;
		int maxComponentSizeToBeRemoved = 1000;
	};
}

