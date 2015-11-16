/***************************************************************
 * Name:      gerador_de_wordlistApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Oric ()
 * Created:   2015-11-10
 * Copyright: Oric (www.guiadohacker.com.br)
 * License:
 **************************************************************/

#include "gerador_de_wordlistApp.h"

//(*AppHeaders
#include "gerador_de_wordlistMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(gerador_de_wordlistApp);

bool gerador_de_wordlistApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	gerador_de_wordlistFrame* Frame = new gerador_de_wordlistFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
