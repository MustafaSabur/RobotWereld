#include "MainApplication.hpp"
#include "MainFrameWindow.hpp"
#include <stdexcept>
#include <algorithm>

/* static */std::vector< CommandlineArgument > MainApplication::commandlineArguments;
/* static */std::vector< std::string > MainApplication::commandlineFiles;

// Create a new application object: this macro will allow wxWidgets to create
// the application object during program execution (it's better than using a
// static object for many reasons) and also implements the accessor function
// wxGetApp() which will return the reference of the right type (i.e. MyApp and
// not wxApp)
IMPLEMENT_APP_NO_MAIN( MainApplication);

/**
 *
 */
MainApplication& TheApp()
{
	return wxGetApp();
}
/**
 *
 */
bool MainApplication::OnInit()
{
	// To make all platforms use all available images
	wxInitAllImageHandlers();

	MainApplication::setCommandlineArguments( argc, argv);

	// create the main application window
	MainFrameWindow* frame = new MainFrameWindow( "RobotWorld");

	SetTopWindow( frame);

	// and show it (the frames, unlike simple controls, are not shown when
	// created initially)
	frame->Show( true);

	// success: wxApp::OnRun() will be called which will enter the main message
	// loop and the application will run. If we returned false here, the
	// application would exit immediately.
	return true;
}

/* static */void MainApplication::setCommandlineArguments( 	int argc,
															char* argv[])
{

	// argv[0] contains the executable name as one types on the command line (with or without extension)
	MainApplication::commandlineArguments.push_back( CommandlineArgument( 0, "Executable", argv[0]));

	for (int i = 1; i < argc; ++i)
	{
		char* arg = argv[i];
		size_t argLength = std::strlen( arg);

		// If the first char of the argument is not a "-" we assume that is is a filename
		// otherwise it is an ordinary argument

		if (arg[0] == '-') // ordinary argument
		{
			bool inserted = false;

			// First handle the arguments in the form of "variable=value".
			for (size_t j = 0; j < argLength; ++j)
			{
				if (arg[j] == '=')
				{
					std::string variable( arg, j);
					std::string value( &arg[j + 1]);

					//std::cerr << "variable = " << variable  << ", value = " << value << std::endl;

					MainApplication::commandlineArguments.push_back( CommandlineArgument( i, variable, value));
					inserted = true;
				}
			}

			// Second handle the stand alone arguments.
			// There is assumed that they actually are booleans.
			// If given on the command line than they will be set to true
			if (inserted == false)
			{
				std::string variable( arg);
				std::string value( "true");

				//std::cerr << "variable = " << variable  << ", value = " << value << std::endl;

				MainApplication::commandlineArguments.push_back( CommandlineArgument( i, variable, value));
			}
		} else // file argument
		{
			//std::cerr << "file = " << arg << std::endl;

			MainApplication::commandlineFiles.push_back( arg);
		}

		std::cerr << "number of argument: " << MainApplication::commandlineArguments.size() << std::endl;

	}
}

/* static */bool MainApplication::isArgGiven( const std::string& aVariable)
{
	std::vector< CommandlineArgument >::iterator i = std::find( MainApplication::commandlineArguments.begin(), MainApplication::commandlineArguments.end(), aVariable);
	return i != commandlineArguments.end();
}

/* static */CommandlineArgument& MainApplication::getArg( const std::string& aVariable)
{
	std::vector< CommandlineArgument >::iterator i = std::find( MainApplication::commandlineArguments.begin(), MainApplication::commandlineArguments.end(), aVariable);
	if (i == MainApplication::commandlineArguments.end())
	{
		throw std::invalid_argument( "No such commandline argument");
	}
	return *i;
}

/* static */CommandlineArgument& MainApplication::getArg( unsigned long anArgumentNumber)
{
	std::vector< CommandlineArgument >::iterator i = std::find( MainApplication::commandlineArguments.begin(), MainApplication::commandlineArguments.end(), anArgumentNumber);
	if (i == MainApplication::commandlineArguments.end())
	{
		throw std::invalid_argument( "No such commandline argument");
	}
	return *i;
}

/* static */std::vector< std::string >& MainApplication::getCommandlineFiles()
{
	return commandlineFiles;
}
