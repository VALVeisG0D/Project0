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

//class Graph
//{
//public:
//	// map to represent an adjacency list
//	// Add vertex first, then connect with edges
//	std::map<int, std::vector<int>> adjList;
//	// Variable to track freed identifier after vertices have been removed
//	std::vector<int> freedID;
//
//	// Graph Constructor
//	Graph(std::map<int, std::vector<int>> const& newAdjList) : adjList(newAdjList)
//	{
//	}
//
//	// Adds single edge
//	// Can add multiple of same edge
//	void AddEdge(int u, int v)
//	{
//		adjList[u].push_back(v);
//		adjList[v].push_back(u);
//	}
//
//	// Removes single edge
//	// Remove duplicate edges by calling this function with same argument repeatedly
//	void RemoveEdge(int u, int v)
//	{
//		if (!(adjList.contains(u) && adjList.contains(v)))
//			return;
//
//		// remove edge from u to v
//		adjList[u].erase(std::find(adjList[u].begin(), adjList[u].end(), v));
//
//		// remove edge from v to u
//		adjList[v].erase(std::find(adjList[v].begin(), adjList[v].end(), u));
//	}
//
//	// Adds one vertex
//	void AddVertex(int vertex)
//	{
//		if (adjList.contains(vertex))
//			return;
//
//		if (!freedID.empty())
//		{
//			adjList[freedID.back()];
//			freedID.pop_back();
//		}
//		else
//			adjList[vertex];
//
//		// connect the new vertex to which other vertex?
//		// can be added to connect to vertex in focus?
//	}
//
//	// Removes one vertex
//	void RemoveVertex(int vertex)
//	{
//		// check if vertex exists
//		if (!adjList.contains(vertex))
//			return;
//
//		// Remove all edge to this vertex from other vertex. CAUTION VERTICES MAY HAVE MULTIPLE EDGE TO SAME VERTEX
//		for (int i : adjList[vertex])
//			while (std::find(adjList[i].begin(), adjList[i].end(), vertex) != std::end(adjList[i]))
//				RemoveEdge(i, vertex);
//
//		// delete this vertex and record its id for reuse
//		freedID.push_back(vertex);
//		adjList.erase(vertex);
//	}
//
//	// Goes through all vetices and its edges
//	void AccessAll(winrt::Microsoft::UI::Xaml::Controls::TextBlock &t)
//	{
//		std::string s;
//
//		for (auto& it : adjList)
//		{
//			s.append(std::to_string(it.first) + " --> ");
//
//			for (int j : it.second)
//			{
//				s.append(std::to_string(j) + " ");
//			}
//
//			s.append("\n");
//		}
//
//		t.Text(to_hstring(s));
//	}
//
//	// How vertices should be connected during each update
//	// Tug of War between order and chaos
//	// Mark all vertices that is about to be deleted, so as to avoid trying to connect edge to vertex that will be deleted
//	// What kind of structure does this rule hope to achieve? What is a structure? Multiple vertex connected to each other in unique ways?
//	void UpdateRule(int vertex)
//	{
//		// Rule 110 evaluation based on certain number of parameters: 2 color of 3 cells, 2 operations (NAND and shift) based on 3 cells,
//		//  movement of the head that allows it to evaluate past results
//		// Graph system evaluation is based on following number of parameters: number of edges connected to a vertex, can also evaluate past
//		// results because all vertices will be evaluated again after update, communication with neighbor vertex to organize update?
//		/*if (adjList[vertex].size() > 5)
//			rule0;
//		else
//			rule1;*/
//
//		for (auto& it : adjList)
//		{
//			it.second.size() < 5;
//			AddVertex(it.first);
//		}
//	}
//};

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
		float xposq = 800.0, yposq = 400.0;
		float vertexRadius = 50.0;
		

		e.Translation(winrt::Windows::Foundation::Numerics::float3(xpose, ypose, 0.0));
		q.Translation(winrt::Windows::Foundation::Numerics::float3(xposq, yposq, 0.0));

		l.Stroke(blue);
	//	l.X1(xpose + vertexRadius / 2.0);
		l.X2(xposq + vertexRadius / 2.0);
		//l.Y1(ypose + vertexRadius / 2.0);
		l.Y2(yposq + vertexRadius / 2.0);

		e.Fill(blue);
		e.Height(vertexRadius);
		e.Width(vertexRadius);
		q.Fill(red);
		q.Height(vertexRadius);
		q.Width(vertexRadius);
		SP().Children().Append(e);
		SP().Children().Append(q);
		SP().Children().Append(l);
		//Microsoft::UI::Xaml::Media::Animation::RepositionThemeAnimation a;
		//a.SetValue(e.);

		//node will spawn new node. apply rule 110 to rewrite system or similar systems??
		//rule 110 has 3 points of input, how many points of input will this system have??
		//balance of chaos/order 
		//what does rewrite system even look like physically in order for this simulation to be entertaining?
		//most important thing to understand is the underlying idea (balance chaos/order, choice, emergence, stability), not the implementation infrastructure

		/*Microsoft::UI::Xaml::Media::TranslateTransform move;
		move.X(5.0);
		move.Y(6.0);
		e.RenderTransform(move);*/

		Microsoft::UI::Xaml::Controls::TextBlock tb;
		SP().Children().Append(tb);
		SP().Children().Append(text);

		/*int jj = 20;
		tb.Text(to_hstring(++jj + 'z'));
		using namespace std::chrono_literals;*/

		
		b.Content(winrt::box_value(L"click"));
		b.Click({ this, &MainWindow::r });

		SP().Children().Append(b);
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
		//e.Translation(winrt::Windows::Foundation::Numerics::float3(xpose + x, ypose + x, 0.0));
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
		repeatTimer.Interval(std::chrono::milliseconds{1});
		repeatTimer.Tick({ this, &MainWindow::TickEventHandler });
		repeatTimer.Start();

		//DispatcherQueueController.ShutdownQueueAsync();

	}

	void MainWindow::TickEventHandler(winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer d, winrt::Windows::Foundation::IInspectable i)
	{
		static int a = 0;
		a++;
		text.Text(to_hstring(a));
		sa = 4070;
		xpose += 1.0, ypose += 1.0;
		e.Translation(winrt::Windows::Foundation::Numerics::float3(xpose, ypose, 0.0));

		Microsoft::UI::Xaml::Shapes::Ellipse te;
		te.Fill(Microsoft::UI::Xaml::Media::SolidColorBrush({ Microsoft::UI::Colors::Green() }));
		te.Height(50.0);
		te.Width(50.0);

		if (universe.AddVertex() > 50)
		{
			l.X1(xpose + 200.0);
			l.Y1(ypose + 200.0);
			universe.AddEdge(2, 3);
		}
		universe.AccessAll(text);

		universe.vertexVisualRepresentationList.push_back(te);
		SP().Children().Append(universe.vertexVisualRepresentationList.back());
		universe.vertexVisualRepresentationList.back().Translation(winrt::Windows::Foundation::Numerics::float3(xpose + 200.0, ypose + 200.0, 0.0));

		for (auto& it : universe.getAdjList())
		{

		}
	}

	void MainWindow::r(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& handler)
	{
		b.Content(winrt::box_value(sa + 40));
	}
}