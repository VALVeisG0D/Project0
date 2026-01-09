#include "pch.h"
#include "MainWindow.xaml.h"
#include <winrt/Microsoft.UI.Dispatching.h>
#include <wil/cppwinrt.h>
#include <wil/cppwinrt_helpers.h>
#include <vector>
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.
namespace winrt::Test0::implementation
{
	MainWindow::MainWindow()
	{
		InitializeComponent();
		LayoutDesign();
	}

	int32_t MainWindow::MyProperty()
	{
		throw hresult_not_implemented();
	}

	void MainWindow::MyProperty(int32_t /* value */)
	{
		throw hresult_not_implemented();
	}

	void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
	{
		//   myButton().Content(box_value(L"Clicked"));
	}
	void MainWindow::HandleCheck(IInspectable const&, RoutedEventArgs const&)
	{
		//text1().Text(L"Two-State CheckBox checked.");
	}

	void MainWindow::HandleUnchecked(IInspectable const&, RoutedEventArgs const&)
	{
		//text1().Text(L"Two-State Checkbox unchecked");
	}
	void MainWindow::LayoutDesign()
	{
		Microsoft::UI::Xaml::Media::SolidColorBrush red{ Microsoft::UI::Colors::Red() };
		Microsoft::UI::Xaml::Media::SolidColorBrush blue{ Microsoft::UI::Colors::Green() };
		Microsoft::UI::Xaml::Media::SolidColorBrush blueBrush{ Microsoft::UI::Colors::Cyan() };

		SP().Background(blueBrush);


		//apply lessons from subleq:


		//node will spawn new node. apply rule 110 to rewrite system or similar systems??
		//rule 110 has 3 points of input, how many points of input will this system have??
		//balance of chaos/order 
		//what does rewrite system even look like physically in order for this simulation to be entertaining?
		//most important thing to understand is the underlying idea (balance chaos/order, choice, emergence, stability), not the implementation infrastructure

		Microsoft::UI::Xaml::Controls::TextBlock tb;
		SP().Children().Append(tb);
		SP().Children().Append(text);
		
		b.Content(winrt::box_value(L"click"));
		b.Click({ this, &MainWindow::r });

		//SP().Children().Append(b);
		//	Windows::Foundation::IAsyncAction aa = DoWorkAsync(tb, e);


		SimulationLoop(tb);

		
		
		/*switch (aa.wait_for(1s))
		{
		case Windows::Foundation::AsyncStatus::Completed:
			tb.Text(L"Completed!");
			break;
		case Windows::Foundation::AsyncStatus::Canceled:
			tb.Text(L"Canceled!");
			break;
		case Windows::Foundation::AsyncStatus::Error:
			tb.Text(L"Error!");
			break;
		case Windows::Foundation::AsyncStatus::Started:
			tb.Text(L"Started!");
			break;
		}
		*/
	}

	Windows::Foundation::IAsyncAction MainWindow::DoWorkAsync(Microsoft::UI::Xaml::Controls::TextBlock textblock, winrt::Microsoft::UI::Xaml::Shapes::Ellipse& v)
	{
		int j = 1;
		int jf = 0;
		float f = 0.0;

		Microsoft::UI::Xaml::Media::TranslateTransform move;

		co_await winrt::resume_background();
		// Do compute-bound work here.


		for (; jf < 20000; ++jf)
			for (int js = 0; js < 20000; ++js)
			{
				++j += js;
				//move.X(f += 10.0);
				//move.Y(f += 10.0);
				//v.RenderTransform(move);
			}

		co_await wil::resume_foreground(textblock.DispatcherQueue());
		textblock.Text(L"Done!"); // Error: TextBlock has thread affinity.
		textblock.Text(to_hstring(j));
	}

	void MainWindow::SimulationLoop(Microsoft::UI::Xaml::Controls::TextBlock textblock)
	{
		repeatTimer.Interval(std::chrono::milliseconds{20});
		repeatTimer.Tick({ this, &MainWindow::TickEventHandler });
		repeatTimer.Start();

		//DispatcherQueueController.ShutdownQueueAsync();

	}

	void MainWindow::TickEventHandler(winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer d, winrt::Windows::Foundation::IInspectable i)
	{
		static int a = 0;

		if (a < 10)
		{
			universe.AddVertex(a, SP());	

			unsigned i = 0;
			std::string hs = "v";
			hs.append(to_string(to_hstring(a)));
			SP().Children().IndexOf(SP().FindName(to_hstring(hs)).as<winrt::Microsoft::UI::Xaml::UIElement>(), i);

			if (hs == "v0")
				SP().Children().GetAt(i).as<winrt::Microsoft::UI::Xaml::Shapes::Ellipse>().Fill(Microsoft::UI::Xaml::Media::SolidColorBrush{ Microsoft::UI::Colors::Red() });
	
			SP().Children().GetAt(i).Translation(winrt::Windows::Foundation::Numerics::float3((universe.getVertexPosition(a)).first, (universe.getVertexPosition(a)).second, 0.0));
		}
	/*	if (a == 20)
			{ 
				universe.AddEdge(0, 3, SP()); 
				universe.AddEdge(3, 5, SP());
				universe.AddEdge(7, 9, SP());
			}*/
		universe.AccessAll(text, SP());
		a++;

		/*if (a == 250)
		{
			universe.RemoveEdge(3, 0, SP());
		}*/
		if (a == 300)
		{
			
			universe.RemoveVertex(7, SP());
		}
	}

	void MainWindow::r(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& handler)
	{
		//b.Content(winrt::box_value(40));
	}
}