#ifndef WIDGETS_HPP_
#define WIDGETS_HPP_

#include "Config.hpp"

#include <wx/wx.h>
#include <wx/scrolwin.h>

#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <wx/gauge.h>
#include <wx/gbsizer.h>
#include <wx/notebook.h>
#include <wx/listctrl.h>
#include <wx/menu.h>
#include <wx/statline.h>
#include <wx/treectrl.h>
#include <wx/imaglist.h>
#include <wx/splitter.h>
#include <wx/dnd.h>
#include <wx/scrolwin.h>
#include <wx/grid.h>

#define ActivateEvent 			wxActivateEvent
#define ActivateEventHandler 	wxActivateEventHandler
#define BoxSizer				wxBoxSizer
#define Brush					wxBrush
#define Button					wxButton
#define Colour 					wxColour
#define Cursor					wxCursor
#define CommandEvent    		wxCommandEvent
#define CloseEvent 				wxCloseEvent
#define CommandEventHandler 	wxCommandEventHandler
#define Coord					wxCoord
#define DataFormat				wxDataFormat
#define DefaultPosition 		wxDefaultPosition
#define DefaultSize				wxDefaultSize
#define DefaultValidator 		wxDefaultValidator
#define DragResult 				wxDragResult
#define Event 					wxEvent
#define EventHandler    		wxEvtHandler
#define FlexGridSizer			wxFlexGridSizer
#define FocusEvent 				wxFocusEvent
#define Font					wxFont
#define Frame					wxFrame
#define GBPosition 				wxGBPosition
#define GBSpan 					wxGBSpan
#define GridBagSizer			wxGridBagSizer
#define ImageList				wxImageList
#define KeyEvent 				wxKeyEvent
#define KeyEventHandler			wxKeyEventHandler
#define ListEvent 				wxListEvent
#define ListEventHandler 		wxListEventHandler
#define ListItem				wxListItem
#define MenuBar					wxMenuBar
#define Menu					wxMenu
#define MouseEvent 				wxMouseEvent
#define MouseEventHandler		wxMouseEventHandler
#define NotifyEvent 			wxNotifyEvent
#define NullColour				wxNullColour
#define PaintEvent  			wxPaintEvent
#define PaintEventHandler		wxPaintEventHandler
#define Panel					wxPanel
#define Point					wxPoint
#define ScrolledCanvas			wxScrolledCanvas
#define ScrolledWindow 			wxScrolledWindow
#define Region					wxRegion
#define Size					wxSize
#define SizeEvent 				wxSizeEvent
#define SizeEventHandler		wxSizeEventHandler
#define Sizer					wxSizer
#define SizerFlags 				wxSizerFlags
#define SplitterWindow 			wxSplitterWindow
#define StaticBoxSizer			wxStaticBoxSizer
#define StaticLine				wxStaticLine
#define TextEntryDialog 		wxTextEntryDialog
#define ToolBar					wxToolBar
#define TreeEvent 				wxTreeEvent
#define TreeEventHandler		wxTreeEventHandler
#define TreeItemId				wxTreeItemId
#define Validator				wxValidator
#define WindowId				wxWindowID
#define Window					wxWindow

#define DEFAULT_ID				wxID_ANY

#define FOCUS_COLOUR			wxColour(240,240,200)
#define DEFAULT_FRAME_STYLE		wxDEFAULT_FRAME_STYLE
#define DEFAULT_DIALOG_STYLE	wxDEFAULT_DIALOG_STYLE

#define CROSS_CURSOR       		wxCROSS_CURSOR
#define HOURGLASS_CURSOR  		wxHOURGLASS_CURSOR
#define STANDARD_CURSOR   		wxSTANDARD_CURSOR

#define TAB_TRAVERSAL			wxTAB_TRAVERSAL

#define LC_LIST 				wxLC_LIST
#define LC_REPORT				wxLC_REPORT
#define LC_SINGLE_SEL 			wxLC_SINGLE_SEL

#define TR_HAS_BUTTONS			wxTR_HAS_BUTTONS
#define TR_HIDE_ROOT			wxTR_HIDE_ROOT

enum GeometryCentre
{
	CENTRE = wxCENTRE,
	CENTER = CENTRE
};

enum Orientation
{
	HORIZONTAL = wxHORIZONTAL,
	DIR_HORIZONTAL = HORIZONTAL,
	VERTICAL = wxVERTICAL,
	DIR_VERTICAL = VERTICAL,

	BOTH = VERTICAL | HORIZONTAL
};

enum Direction
{
	LEFT = wxLEFT,
	RIGHT = wxRIGHT,
	UP = wxUP,
	DOWN = wxDOWN,

	TOP = UP,
	BOTTOM = DOWN,

	NORTH = UP,
	SOUTH = DOWN,
	WEST = LEFT,
	EAST = RIGHT,

	ALL = (UP | DOWN | RIGHT | LEFT)
};

enum Alignment
{
	ALIGN_NOT = wxALIGN_NOT,
	ALIGN_CENTER_HORIZONTAL = wxALIGN_CENTER_HORIZONTAL,
	ALIGN_CENTRE_HORIZONTAL = ALIGN_CENTER_HORIZONTAL,
	ALIGN_LEFT = ALIGN_NOT,
	ALIGN_TOP = ALIGN_NOT,
	ALIGN_RIGHT = wxALIGN_RIGHT,
	ALIGN_BOTTOM = wxALIGN_BOTTOM,
	ALIGN_CENTER_VERTICAL = wxALIGN_CENTER_VERTICAL,
	ALIGN_CENTRE_VERTICAL = ALIGN_CENTER_VERTICAL,

	ALIGN_CENTER = (ALIGN_CENTER_HORIZONTAL | ALIGN_CENTER_VERTICAL),
	ALIGN_CENTRE = ALIGN_CENTER,
	ALIGN_MASK = wxALIGN_MASK
};

enum Stretch
{
	STRETCH_NOT = wxSTRETCH_NOT,
	SHRINK = wxSHRINK,
	GROW = wxGROW,
	EXPAND = GROW,
	SHAPED = wxSHAPED,
	FIXED_MINSIZE = wxFIXED_MINSIZE,
	RESERVE_SPACE_EVEN_IF_HIDDEN = wxRESERVE_SPACE_EVEN_IF_HIDDEN,
	TILE = wxTILE
};

inline wxString WXSTRING( const char* aText)
{
	return wxString::FromAscii( aText);
}

inline wxString WXSTRING( const std::string& aString)
{
	return wxString::FromAscii( aString.c_str());
}

inline wxString WXSTRING( std::string& aString)
{
	return wxString::FromAscii( aString.c_str());
}

inline std::string STDSTRING( const wxString& aString)
{
	return std::string( aString.ToAscii());
}

inline std::string STDSTRING( wxString& aString)
{
	return std::string( aString.ToAscii());
}

/**
 *
 * @param aTitleBarMessage
 * @param aMessage
 * @param aDefaultValue
 * @param aParent
 * @param centre
 * @param aPoint
 * @return
 */
std::string GetTextFromUser(	const std::string& aTitleBarMessage,
								const std::string& aMessage,
								const std::string& aDefaultValue = "",
								Window* aParent = NULL,
								bool centre = false,
								const Point& aPoint = DefaultPosition);

#endif /* WIDGETS_HPP_ */
