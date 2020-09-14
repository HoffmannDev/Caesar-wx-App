/***************************************************************
 * Name:      wxKryptApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2020-09-08
 * Copyright:  ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxKryptApp.h"
#include "wxKryptMain.h"

IMPLEMENT_APP(wxKryptApp);

bool wxKryptApp::OnInit()
{
    wxKryptFrame* frame = new wxKryptFrame(0L);
    frame->SetIcon(wxICON(aaaa)); // To Set App Icon
    frame->Show();
    
    return true;
}
