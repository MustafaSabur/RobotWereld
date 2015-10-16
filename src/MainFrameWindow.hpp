#ifndef MAINFRAMEWINDOW_HPP_
#define MAINFRAMEWINDOW_HPP_

#include "Config.hpp"
#include "Widgets.hpp"

class RobotWorldCanvas;
class LogTextCtrl;
class DebugTraceFunction;

/**
 *
 */
class MainFrameWindow : public Frame
{
	public:
		/**
		 *
		 * @param aTitle The title which is shown in the title bar
		 */
		MainFrameWindow( const std::string& aTitle);
		/**
		 *
		 */
		virtual ~MainFrameWindow();
		/**
		 *
		 */
		DebugTraceFunction* getTraceFunction();

	protected:
		/**
		 *
		 */
		void initialise();
		/**
		 *
		 */
		MenuBar* initialiseMenuBar();
		/**
		 *
		 */
		Panel* initialiseClientPanel();
		/**
		 *
		 */
		SplitterWindow* initialiseSplitterWindow();
		/**
		 *
		 */
		Panel* initialiseLhsPanel();
		/**
		 *
		 */
		Panel* initialiseRhsPanel();
		/**
		 *
		 */
		Panel* initialiseButtonPanel();

	protected:

	private:
		Panel* clientPanel;
		MenuBar* menuBar;
		SplitterWindow* splitterWindow;

		Panel* lhsPanel;
		RobotWorldCanvas* robotWorldCanvas;

		Panel* rhsPanel;
		LogTextCtrl* logTextCtrl;
		Panel* buttonPanel;

		DebugTraceFunction* debugTraceFunction;

		void OnQuit( CommandEvent& anEvent);
		void OnWidgetDebugTraceFunction( CommandEvent& anEvent);
		void OnStdOutDebugTraceFunction( CommandEvent& anEvent);
		void OnAbout( CommandEvent& anEvent);

		void OnButton1Clicked( CommandEvent& anEvent);
		void OnButton2Clicked( CommandEvent& anEvent);
		void OnButton3Clicked( CommandEvent& anEvent);
		void OnButton4Clicked( CommandEvent& anEvent);
		void OnButton5Clicked( CommandEvent& anEvent);
		void OnButton6Clicked( CommandEvent& anEvent);
		void OnButton7Clicked( CommandEvent& anEvent);
};
//	class MainFrameWindow

#endif // MAINFRAMEWINDOW_HPP_
