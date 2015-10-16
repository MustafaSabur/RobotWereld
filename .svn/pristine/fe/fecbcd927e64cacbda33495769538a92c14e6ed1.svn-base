#include "MainFrameWindow.hpp"
#include "MainApplication.hpp"
#include "RobotWorldCanvas.hpp"
#include "LogTextCtrl.hpp"
#include "WidgetDebugTraceFunction.hpp"
#include "StdOutDebugTraceFunction.hpp"
#include "Button.hpp"
#include "RobotWorld.hpp"
#include "Robot.hpp"
#include "Math.hpp"
#include "Shape2DUtils.hpp"
#include <iostream>
#include "Thread.hpp"
#include "Logger.hpp"
#include "Client.hpp"
#include "Message.hpp"

/**
 * IDs for the controls and the menu commands
 * If there are (default) wxWidget ID's try to maintain
 * compatibility, especially wxID_ABOUT because on a Mac it is special
 */
enum
{
	ID_QUIT = wxID_EXIT,         	//!< ID_QUIT
	ID_OPTIONS = wxID_PROPERTIES,	//!< ID_OPTIONS
	ID_ABOUT = wxID_ABOUT,        	//!< ID_ABOUT
	ID_WIDGET_DEBUG_TRACE_FUNCTION, //!< ID_WIDGET_DEBUG_TRACE_FUNCTION
	ID_STDCOUT_DEBUG_TRACE_FUNCTION //!< ID_STDCOUT_DEBUG_TRACE_FUNCTION

};
/**
 *
 */
MainFrameWindow::MainFrameWindow( const std::string& aTitle) :
				Frame( NULL, DEFAULT_ID, WXSTRING( aTitle), DefaultPosition, Size( 500, 400)),
				clientPanel( NULL),
				menuBar( NULL),
				splitterWindow( NULL),
				lhsPanel( NULL),
				robotWorldCanvas( NULL),
				rhsPanel( NULL),
				logTextCtrl( NULL),
				buttonPanel( NULL),
				debugTraceFunction( NULL)
{
	initialise();
}
/**
 *
 */
MainFrameWindow::~MainFrameWindow()
{
	if (debugTraceFunction)
	{
		delete debugTraceFunction;
	}
}
/**
 *
 */
DebugTraceFunction* MainFrameWindow::getTraceFunction()
{
	return debugTraceFunction;
}
/**
 *
 */
void MainFrameWindow::initialise()
{
	SetMenuBar( initialiseMenuBar());

	GridBagSizer* sizer = new GridBagSizer( 5, 5);

	sizer->Add( initialiseClientPanel(),
	GBPosition( 0, 0), 	// row ,col
	GBSpan( 1, 1), 		// row ,col
	EXPAND);

	sizer->AddGrowableCol( 0);
	sizer->AddGrowableRow( 0);

	sizer->SetSizeHints( this);
	SetMinSize( wxSize( 500, 350));

	Bind( wxEVT_COMMAND_MENU_SELECTED,
	      [this](CommandEvent& anEvent){ this->OnQuit(anEvent);},
	      ID_QUIT);
	Bind( wxEVT_COMMAND_MENU_SELECTED,
	      [this](CommandEvent& anEvent){ this->OnWidgetDebugTraceFunction(anEvent);},
	      ID_WIDGET_DEBUG_TRACE_FUNCTION);
	Bind( wxEVT_COMMAND_MENU_SELECTED,
	      [this](CommandEvent& anEvent){ this->OnStdOutDebugTraceFunction(anEvent);},
	      ID_STDCOUT_DEBUG_TRACE_FUNCTION);
	Bind( wxEVT_COMMAND_MENU_SELECTED,
	      [this](CommandEvent& anEvent){ this->OnAbout(anEvent);},
	      ID_ABOUT);
}
/**
 *
 */
MenuBar* MainFrameWindow::initialiseMenuBar()
{
	Menu* fileMenu = new Menu;
	fileMenu->Append( ID_QUIT, WXSTRING( "E&xit\tAlt-X"), WXSTRING( "Exit the application"));

	Menu* debugMenu = new Menu;
	debugMenu->AppendRadioItem( ID_WIDGET_DEBUG_TRACE_FUNCTION, WXSTRING( "Widget"), WXSTRING( "Widget"));
	debugMenu->AppendRadioItem( ID_STDCOUT_DEBUG_TRACE_FUNCTION, WXSTRING( "StdOut"), WXSTRING( "StdOut"));

	Menu* helpMenu = new Menu;
	helpMenu->Append( ID_ABOUT, WXSTRING( "&About...\tF1"), WXSTRING( "Show about dialog"));

	menuBar = new wxMenuBar;
	menuBar->Append( fileMenu, WXSTRING( "&File"));
	menuBar->Append( debugMenu, WXSTRING( "&Debug"));
	menuBar->Append( helpMenu, WXSTRING( "&Help"));

	return menuBar;
}
/**
 *
 */
Panel* MainFrameWindow::initialiseClientPanel()
{
	if (!clientPanel)
	{
		clientPanel = new Panel( this, DEFAULT_ID);

		GridBagSizer* sizer = new GridBagSizer();

		sizer->Add( 5, 5,
		GBPosition( 0, 0));

		sizer->Add( initialiseSplitterWindow(),
		GBPosition( 1, 1),
		GBSpan( 1, 1), EXPAND);
		sizer->AddGrowableRow( 1);
		sizer->AddGrowableCol( 1);

		sizer->Add( 5, 5,
		GBPosition( 2, 2));

		clientPanel->SetSizer( sizer);
		sizer->SetSizeHints( clientPanel);
	}
	return clientPanel;

}
/**
 *
 */
SplitterWindow* MainFrameWindow::initialiseSplitterWindow()
{
	if (!splitterWindow)
	{
		GridBagSizer* sizer = new GridBagSizer();

		splitterWindow = new SplitterWindow( clientPanel, DEFAULT_ID);

		splitterWindow->SplitVertically( initialiseLhsPanel(), initialiseRhsPanel());

		sizer->Add( 5, 5,
		GBPosition( 0, 0));

		sizer->Add( splitterWindow,
		GBPosition( 1, 1),
		GBSpan( 1, 1), EXPAND);
		sizer->AddGrowableRow( 1);
		sizer->AddGrowableCol( 1);

		sizer->Add( 5, 5,
		GBPosition( 2, 2));

		splitterWindow->SetSizer( sizer);
		sizer->SetSizeHints( splitterWindow);

	}
	return splitterWindow;

}
/**
 *
 */
Panel* MainFrameWindow::initialiseLhsPanel()
{
	if (!lhsPanel)
	{
		lhsPanel = new Panel( splitterWindow, DEFAULT_ID);

		GridBagSizer* sizer = new GridBagSizer();
		sizer->Add( 5, 5,
		GBPosition( 0, 0),
		GBSpan( 1, 1), EXPAND);

		sizer->Add( robotWorldCanvas = new RobotWorldCanvas( lhsPanel),
		GBPosition( 1, 1),
		GBSpan( 1, 1), EXPAND);
		sizer->AddGrowableCol( 1);
		sizer->AddGrowableRow( 1);

		sizer->Add( 5, 5,
		GBPosition( 2, 2),
		GBSpan( 1, 1), EXPAND);

		lhsPanel->SetSizer( sizer);
		sizer->SetSizeHints( lhsPanel);
	}
	return lhsPanel;
}
/**
 *
 */
Panel* MainFrameWindow::initialiseRhsPanel()
{
	if (!rhsPanel)
	{
		rhsPanel = new Panel( splitterWindow, DEFAULT_ID);

		GridBagSizer* sizer = new GridBagSizer();
		sizer->Add( 5, 5,
		GBPosition( 0, 0),
		GBSpan( 1, 1), EXPAND);

		sizer->Add( logTextCtrl = new LogTextCtrl( rhsPanel, DEFAULT_ID, wxTE_MULTILINE | wxTE_DONTWRAP),
		GBPosition( 1, 1),
		GBSpan( 1, 1), EXPAND);
		sizer->AddGrowableCol( 1);
		sizer->AddGrowableRow( 1);
		logTextCtrl->SetMinSize( Size( 500, 300));

		debugTraceFunction = new WidgetDebugTraceFunction( logTextCtrl);

		sizer->Add( buttonPanel = initialiseButtonPanel(),
		GBPosition( 2, 1),
		GBSpan( 1, 1), SHRINK);
		sizer->AddGrowableRow( 2);

		sizer->Add( 5, 5,
		GBPosition( 2, 2),
		GBSpan( 1, 1), EXPAND);

		rhsPanel->SetSizer( sizer);
		sizer->SetSizeHints( rhsPanel);
	}
	return rhsPanel;
}
/**
 *
 */
Panel* MainFrameWindow::initialiseButtonPanel()
{
	Panel* panel = new Panel( rhsPanel);

	GridBagSizer* sizer = new GridBagSizer();


	sizer->Add( makeButton( panel,
	                        "Start robot",
	                        [this](CommandEvent &anEvent){this->OnButton1Clicked(anEvent);}),
	            GBPosition( 0, 0),
	            GBSpan( 1, 1), EXPAND);

	sizer->Add( makeButton( panel,
	                        "Stop robot",
	                        [this](CommandEvent &anEvent){this->OnButton2Clicked(anEvent);}),
	            GBPosition( 0, 1),
	            GBSpan( 1, 1), EXPAND);


	sizer->Add( makeButton( panel,
	                        "Populate",
	                        [this](CommandEvent &anEvent){this->OnButton3Clicked(anEvent);}),
	            GBPosition( 1, 0),
	            GBSpan( 1, 1), EXPAND);

	sizer->Add( makeButton( panel,
	                        "Unpopulate",
	                        [this](CommandEvent &anEvent){this->OnButton4Clicked(anEvent);}),
	            GBPosition( 1, 1),
	            GBSpan( 1, 1), EXPAND);


	sizer->Add( makeButton( panel,
	                        "Start communicating",
	                        [this](CommandEvent &anEvent){this->OnButton5Clicked(anEvent);}),
	            GBPosition( 2, 0),
	            GBSpan( 1, 1), EXPAND);
	sizer->Add( makeButton( panel,
	                        "Say the words",
	                        [this](CommandEvent &anEvent){this->OnButton6Clicked(anEvent);}),
	            GBPosition( 2, 1),
	            GBSpan( 1, 1), EXPAND);
	sizer->Add( makeButton( panel,
	                        "Stop communicating",
	                        [this](CommandEvent &anEvent){this->OnButton7Clicked(anEvent);}),
	            GBPosition( 2, 2),
	            GBSpan( 1, 1), EXPAND);

	panel->SetSizerAndFit( sizer);

	return panel;
}
/**
 *
 */
void MainFrameWindow::OnQuit( CommandEvent& UNUSEDPARAM(anEvent))
{
	Close( true);
}
/**
 *
 */
void MainFrameWindow::OnWidgetDebugTraceFunction( CommandEvent& UNUSEDPARAM(anEvent))
{
	if (debugTraceFunction)
		delete debugTraceFunction;
	debugTraceFunction = new WidgetDebugTraceFunction( logTextCtrl);
}
/**
 *
 */
void MainFrameWindow::OnStdOutDebugTraceFunction( CommandEvent& UNUSEDPARAM(anEvent))
{
	if (debugTraceFunction)
		delete debugTraceFunction;
	debugTraceFunction = new StdOutDebugTraceFunction();

}

/**
 *
 */
void MainFrameWindow::OnAbout( CommandEvent& UNUSEDPARAM(anEvent))
{
	wxMessageBox( WXSTRING( "OOSE/CAR 2014 RobotWorld.\n"), WXSTRING( "About RobotWorld"), wxOK | wxICON_INFORMATION, this);
}
/**
 *
 */
void MainFrameWindow::OnButton1Clicked( CommandEvent& UNUSEDPARAM(anEvent))
{
	Logger::log( "Attempting to start Thijs...");
	RobotPtr robot = RobotWorld::getRobotWorld().getRobotByName( "Thijs");
	if (robot)
	{
		robot->startActing();
	}
}
/**
 *
 */
void MainFrameWindow::OnButton2Clicked( CommandEvent& UNUSEDPARAM(anEvent))
{
	Logger::log( "Attempting to stop Thijs...");
	RobotPtr robot = RobotWorld::getRobotWorld().getRobotByName( "Thijs");
	if (robot)
	{
		robot->stopActing();
	}
}
/**
 *
 */
void MainFrameWindow::OnButton3Clicked( CommandEvent& UNUSEDPARAM(anEvent))
{
	Logger::log( __PRETTY_FUNCTION__);

	robotWorldCanvas->populate( 2);
}
/**
 *
 */
void MainFrameWindow::OnButton4Clicked( CommandEvent& UNUSEDPARAM(anEvent))
{
	Logger::log( __PRETTY_FUNCTION__);

	robotWorldCanvas->unpopulate();
}
/**
 *
 */
void MainFrameWindow::OnButton5Clicked( CommandEvent& UNUSEDPARAM(anEvent))
{
	Logger::log( __PRETTY_FUNCTION__);

	RobotPtr robot = RobotWorld::getRobotWorld().getRobotByName( "Thijs");
	if (robot)
	{
		robot->startCommunicating();
	}
}
/**
 *
 */
void MainFrameWindow::OnButton6Clicked( CommandEvent& UNUSEDPARAM(anEvent))
{
	Logger::log( __PRETTY_FUNCTION__);

	RobotPtr robot = RobotWorld::getRobotWorld().getRobotByName( "Thijs");
	if (robot)
	{
		std::string remoteIpAdres = "localhost";
		std::string remotePort = "12345";

		if (MainApplication::isArgGiven( "-ip"))
		{
			remoteIpAdres = MainApplication::getArg( "-ip").value;
		}
		if (MainApplication::isArgGiven( "-port"))
		{
			remotePort = MainApplication::getArg( "-port").value;
		}

		MessageASIO::Client c1ient( CommunicationService::getCommunicationService().getIOService(), remoteIpAdres, remotePort, robot);
		MessageASIO::Message message( 1, "Hello world!");
		c1ient.dispatchMessage( message);
	}
}
/**
 *
 */
void MainFrameWindow::OnButton7Clicked( CommandEvent& UNUSEDPARAM(anEvent))
{
	Logger::log( __PRETTY_FUNCTION__);

	RobotPtr thijs = RobotWorld::getRobotWorld().getRobotByName( "Thijs");
	if (thijs)
	{
		thijs->stopCommunicating();
	}
}

