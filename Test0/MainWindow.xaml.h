#pragma once

#include "MainWindow.g.h"

namespace winrt::Test0::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
		class Graph
		{
			struct vertexProperties
			{
				float x, y;
				int vertexID;// Identifier incremented to max integer
				std::vector<int> adjancencyVector;

				//vertexProperties() : vertexID(adjList.size());
			};

			// map to represent an adjacency list
			// Add vertices first, then connect with edges
			std::map<int, vertexProperties> adjList;
			// Variable to track freed identifier after vertices have been removed
			std::vector<int> freedID;
			// Identifier incremented to max integer
			int vertexID;

			
			struct vertexVisualProperties
			{
				int x, y, id;
				Microsoft::UI::Xaml::Media::SolidColorBrush blue{ Microsoft::UI::Colors::Green() };
				Microsoft::UI::Xaml::Shapes::Ellipse f;
			};

		public:
			// Update VisualRepresentation in Graph member functions
			Microsoft::UI::Xaml::Shapes::Line edgeVisualRepresentation;
			Microsoft::UI::Xaml::Shapes::Ellipse vertexVisualRepresentation;
			std::vector<Microsoft::UI::Xaml::Shapes::Line> edgeVisualRepresenationList;
			std::vector<Microsoft::UI::Xaml::Shapes::Ellipse> vertexVisualRepresentationList;

			// Graph Constructor
			Graph() : vertexID(0)
			{
				edgeVisualRepresentation.Stroke(Microsoft::UI::Xaml::Media::SolidColorBrush{ Microsoft::UI::Colors::Green() });
			}

			Graph(std::map<int, vertexProperties> const& newAdjList) : adjList(newAdjList), vertexID(0)
			{
				edgeVisualRepresentation.Stroke(Microsoft::UI::Xaml::Media::SolidColorBrush{ Microsoft::UI::Colors::Green() });
			}

			// Adds single edge
			// Can add multiple of same edge
			// Evaluate per vertex and have v be the vertices u should connect to by repeatedly calling this, with u being constant
			void AddEdge(int u, int v)
			{
				adjList[u].adjancencyVector.push_back(v);
				adjList[v].adjancencyVector.push_back(u);

				// Coordinates of edge ends
				// How to assign coordinate?
				edgeVisualRepresentation.X2();
				edgeVisualRepresenationList.push_back(edgeVisualRepresentation);
			}

			// Removes single edge
			// Remove duplicate edges by calling this function with same argument repeatedly
			void RemoveEdge(int u, int v)
			{
				if (!(adjList.contains(u) && adjList.contains(v)))
					return;

				// remove edge from u to v
				adjList[u].adjancencyVector.erase(std::find(adjList[u].adjancencyVector.begin(), adjList[u].adjancencyVector.end(), v));

				// remove edge from v to u
				adjList[v].adjancencyVector.erase(std::find(adjList[v].adjancencyVector.begin(), adjList[v].adjancencyVector.end(), u));
			}

			// Adds one vertex
			int AddVertex()
			{
				/*if (adjList.contains(vertex))
					return;

				if (!freedID.empty())
				{
					adjList[freedID.back()];
					freedID.pop_back();
				}
				else
					adjList[vertex];*/

				adjList[vertexID];

				// connect the new vertex to which other vertex?
				// can be added to connect to vertex in focus?
				// Update VisualRepresentation structure, what visual coordinate for new vertex?
				// Need to be near vertices which are connected to it?
				// Should return id to be able to tell which vertex is being added.
				return vertexID++;
			}

			// Removes one vertex
			void RemoveVertex(int vertex)
			{
				// check if vertex exists
				if (!adjList.contains(vertex))
					return;

				// Remove all edge to this vertex from other vertex. CAUTION VERTICES MAY HAVE MULTIPLE EDGES
				for (int i : adjList[vertex].adjancencyVector)
					while (std::find(adjList[i].adjancencyVector.begin(), adjList[i].adjancencyVector.end(), vertex) != std::end(adjList[i].adjancencyVector))
						RemoveEdge(i, vertex);

				// delete this vertex and record its id for reuse
				freedID.push_back(vertex);
				adjList.erase(vertex);
			}

			// Goes through all vetices and its edges
			void AccessAll(winrt::Microsoft::UI::Xaml::Controls::TextBlock& t)
			{
				std::string s;

				for (auto& it : adjList)
				{
					s.append(std::to_string(it.first) + " --> ");

					for (int j : it.second.adjancencyVector)
					{
						s.append(std::to_string(j) + " ");
					}

					s.append("\n");
				}

				t.Text(to_hstring(s));
			}

			const std::map<int, vertexProperties>& getAdjList() const
			{
				return adjList;
			}

			// How vertices should be connected during each update
			// Tug of War between order and chaos
			// Mark all vertices that is about to be deleted, so as to avoid trying to connect edge to vertex that will be deleted
			// What kind of structure does this rule hope to achieve? What is a structure? Multiple vertex connected to each other in unique ways?
			void Rule()
			{
				// Rule 110 evaluation based on certain number of parameters: 2 color of 3 cells, 2 operations (NAND and shift) based on 3 cells,
				//  movement of the head that allows it to evaluate past results
				// Graph system evaluation is based on following number of parameters: number of edges connected to a vertex, can also evaluate past
				// results because all vertices will be evaluated again after update, communication with neighbor vertex to organize update?
				// Node creation rules (Chaos/Order)			
				// How many imbalances are there?
				// In the beginning there is one vertex (an imbalance). This will lead to creation of new vertex
				// Even/Odd number of connections

				/*Graph rewrite :
				-unlimited operands of binary value(positive / negative)
					- unknown number of rules
					- nodes / cells can be created or destroyed
					- alphabets are graph/subgraphs?
					- no boundaries, no dimension and direction (can emerge from rule?)
					- create / destroy sets of nodes ?
					- what kind of graph? simple, planar, connected is simplest?
					- computation(try to make it as simple as possible) : operand 1 = even / odd number of connections, operand 2 =

					Rule 110 :
					-3 operands of binary values(past, present, future)
					- 8 set of rules
					- alphabet is on/off
					- number of nodes / cells are fixed.
					- boundary exists and influences next state, has dimension and direction
					- only change value of cells
					- computation: 3 cells; determine state of the same cell for next generation; move sequentially to next cell on same row,





					how different they are*/
				if (adjList[vertexID].adjancencyVector.size() % 2)
					;//rule0 = NAND computation? How many of connected vertices are EVEN/ODD?
				else
					;//rule1 = memorize? save state?
			}
		};

        MainWindow();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void HandleCheck(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void HandleUnchecked(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
        void LayoutDesign();
        Windows::Foundation::IAsyncAction DoWorkAsync(Microsoft::UI::Xaml::Controls::TextBlock textblock, winrt::Microsoft::UI::Xaml::Shapes::Ellipse& v);
        void SimulationLoop(Microsoft::UI::Xaml::Controls::TextBlock textblock);
        void TickEventHandler(winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer d, winrt::Windows::Foundation::IInspectable i);

        void r(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& handler);

        Microsoft::UI::Xaml::Controls::TextBlock text;
        Microsoft::UI::Dispatching::DispatcherQueueController controller{ Microsoft::UI::Dispatching::DispatcherQueueController::CreateOnDedicatedThread()};
        Microsoft::UI::Dispatching::DispatcherQueue dispatch{ controller.DispatcherQueue().GetForCurrentThread()};
        Microsoft::UI::Dispatching::DispatcherQueueTimer repeatTimer{ dispatch.CreateTimer() };
        Microsoft::UI::Xaml::Controls::Primitives::RepeatButton b;
        Microsoft::UI::Xaml::Shapes::Line l;
        Microsoft::UI::Xaml::Shapes::Ellipse e, q;
        float xpose = 265.0, ypose = 400.0;
		class Graph universe;

        int sa = 0;
    };
}

namespace winrt::Test0::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
