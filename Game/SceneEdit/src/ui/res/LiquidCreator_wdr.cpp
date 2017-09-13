//------------------------------------------------------------------------------
// Source code generated by wxDesigner from file: LiquidCreator.wdr
// Do not modify this file, all changes will be lost!
//------------------------------------------------------------------------------

#if defined(__GNUG__) && !defined(NO_GCC_PRAGMA)
    #pragma implementation "LiquidCreator_wdr.h"
#endif

// For compilers that support precompilation
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

// Include private header
#include "LiquidCreator_wdr.h"

#include <wx/intl.h>

// Euro sign hack of the year
#if wxUSE_UNICODE
    #define __WDR_EURO__ wxT("\u20ac")
#else
    #if defined(__WXMAC__)
        #define __WDR_EURO__ wxT("\xdb")
    #elif defined(__WXMSW__)
        #define __WDR_EURO__ wxT("\x80")
    #else
        #define __WDR_EURO__ wxT("\xa4")
    #endif
#endif

// Implement window functions

wxSizer *LiquidCreator( wxWindow *parent, bool call_fit, bool set_sizer )
{
    wxBoxSizer *item0 = new wxBoxSizer( wxVERTICAL );

    wxFlexGridSizer *item1 = new wxFlexGridSizer( 2, 0, 0 );

    wxStaticText *item2 = new wxStaticText( parent, -1, /*_("Tex Coord Scale")*/_("������������ֵ"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
    item1->Add( item2, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxTextCtrl *item3 = new wxTextCtrl( parent, ID_TEXCOORDSCALETEXTCTRL, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
    item1->Add( item3, 0, wxGROW|wxALL, 5 );

    wxStaticText *item4 = new wxStaticText( parent, -1, /*_("Subdivision")*/_("�������ϸ��ֵ"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
    item1->Add( item4, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxTextCtrl *item5 = new wxTextCtrl( parent, ID_SUBDIVISIONTEXTCTRL, wxT("1"), wxDefaultPosition, wxDefaultSize, 0 );
	
	// ��Ϊ����������ڻ�û�ã�������disable
	item5->Enable(false);
    item1->Add( item5, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxStaticText *item6 = new wxStaticText( parent, -1, /*_("Material")*/_("����"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
    item1->Add( item6, 0, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxString *strs7 = (wxString*) NULL;
    wxComboBox *item7 = new wxComboBox( parent, ID_MATERIALCOMBO, wxT(""), wxDefaultPosition, wxDefaultSize, 0, strs7, wxCB_DROPDOWN );
    item1->Add( item7, 0, wxGROW|wxALL, 5 );

    item0->Add( item1, 0, wxGROW|wxALIGN_CENTER_VERTICAL|wxALL, 5 );

    wxFlexGridSizer *item8 = new wxFlexGridSizer( 1, 0, 0, 0 );
    item8->AddGrowableCol( 0 );

    wxButton *item9 = new wxButton( parent, wxID_OK, /*_("&OK")*/_("ȷ��"), wxDefaultPosition, wxDefaultSize, 0 );
    item9->SetDefault();
    item8->Add( item9, 0, wxALIGN_CENTER|wxALL, 5 );

    wxButton *item10 = new wxButton( parent, wxID_CANCEL, /*_("&Cancel")*/_("ȡ��"), wxDefaultPosition, wxDefaultSize, 0 );
    item8->Add( item10, 0, wxALIGN_CENTER|wxALL, 5 );

    item0->Add( item8, 0, wxGROW|wxALL, 5 );

    if (set_sizer)
    {
        parent->SetSizer( item0 );
        if (call_fit)
            item0->SetSizeHints( parent );
    }
    
    return item0;
}

// Implement menubar functions

// Implement toolbar functions

// Implement bitmap functions


// End of generated file