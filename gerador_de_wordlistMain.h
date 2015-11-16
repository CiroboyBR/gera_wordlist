/***************************************************************
 * Name:      gerador_de_wordlistMain.h
 * Purpose:   Defines Application Frame
 * Author:    Oric ()
 * Created:   2015-11-10
 * Copyright: Oric (www.guiadohacker.com.br)
 * License:
 **************************************************************/

#ifndef GERADOR_DE_WORDLISTMAIN_H
#define GERADOR_DE_WORDLISTMAIN_H

//(*Headers(gerador_de_wordlistFrame)
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/frame.h>
//*)

class gerador_de_wordlistFrame: public wxFrame
{
    public:

        gerador_de_wordlistFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~gerador_de_wordlistFrame();

    private:

        //(*Handlers(gerador_de_wordlistFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(gerador_de_wordlistFrame)
        static const long ID_TEXTCTRL1;
        static const long ID_TEXTCTRL2;
        static const long ID_TEXTCTRL3;
        static const long ID_BUTTON1;
        static const long ID_TEXTCTRL4;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_TEXTCTRL5;
        static const long ID_TEXTCTRL6;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT5;
        //*)

        //(*Declarations(gerador_de_wordlistFrame)
        wxTextCtrl* TextCtrl4;
        wxStaticText* StaticText2;
        wxButton* Button1;
        wxTextCtrl* TextCtrl6;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxButton* Button2;
        wxButton* Button3;
        wxStaticText* StaticText5;
        wxTextCtrl* TextCtrl2;
        wxTextCtrl* TextCtrl1;
        wxTextCtrl* TextCtrl5;
        wxStaticText* StaticText4;
        wxTextCtrl* TextCtrl3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GERADOR_DE_WORDLISTMAIN_H
