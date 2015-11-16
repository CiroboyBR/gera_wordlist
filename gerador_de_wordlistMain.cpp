/***************************************************************
 * Name:      gerador_de_wordlistMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Oric ()
 * Created:   2015-11-10
 * Copyright: Oric (www.guiadohacker.com.br)
 * License:
 **************************************************************/

#include "gerador_de_wordlistMain.h"
#include <wx/msgdlg.h>

void cria_wordlist(wxString pre, wxString Lim, wxString sufix);
void cria_wordlist_datas(wxString pre, wxString sufix, wxString ano_inicial, wxString ano_final );

//(*InternalHeaders(gerador_de_wordlistFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(gerador_de_wordlistFrame)
const long gerador_de_wordlistFrame::ID_TEXTCTRL1 = wxNewId();
const long gerador_de_wordlistFrame::ID_TEXTCTRL2 = wxNewId();
const long gerador_de_wordlistFrame::ID_TEXTCTRL3 = wxNewId();
const long gerador_de_wordlistFrame::ID_BUTTON1 = wxNewId();
const long gerador_de_wordlistFrame::ID_TEXTCTRL4 = wxNewId();
const long gerador_de_wordlistFrame::ID_STATICTEXT1 = wxNewId();
const long gerador_de_wordlistFrame::ID_STATICTEXT2 = wxNewId();
const long gerador_de_wordlistFrame::ID_STATICTEXT3 = wxNewId();
const long gerador_de_wordlistFrame::ID_BUTTON2 = wxNewId();
const long gerador_de_wordlistFrame::ID_BUTTON3 = wxNewId();
const long gerador_de_wordlistFrame::ID_TEXTCTRL5 = wxNewId();
const long gerador_de_wordlistFrame::ID_TEXTCTRL6 = wxNewId();
const long gerador_de_wordlistFrame::ID_STATICTEXT4 = wxNewId();
const long gerador_de_wordlistFrame::ID_STATICTEXT5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(gerador_de_wordlistFrame,wxFrame)
    //(*EventTable(gerador_de_wordlistFrame)
    //*)
END_EVENT_TABLE()

gerador_de_wordlistFrame::gerador_de_wordlistFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(gerador_de_wordlistFrame)
    Create(parent, wxID_ANY, _("Gerador de Wordlist"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(400,276));
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("21"), wxPoint(8,56), wxDefaultSize, wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, _("9999"), wxPoint(136,24), wxDefaultSize, wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(264,56), wxDefaultSize, wxTE_CENTRE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    Button1 = new wxButton(this, ID_BUTTON1, _("Gera numeros"), wxPoint(128,48), wxSize(120,30), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    TextCtrl4 = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(40,176), wxSize(208,72), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("max: 99999999"), wxPoint(152,8), wxSize(96,13), 0, _T("ID_STATICTEXT1"));
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Prefixo"), wxPoint(40,40), wxSize(40,13), 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Sufixo"), wxPoint(304,40), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Gera datas"), wxPoint(112,136), wxSize(120,30), 0, wxDefaultValidator, _T("ID_BUTTON2"));
    Button3 = new wxButton(this, ID_BUTTON3, _("Ajuda"), wxPoint(272,192), wxSize(120,30), 0, wxDefaultValidator, _T("ID_BUTTON3"));
    TextCtrl5 = new wxTextCtrl(this, ID_TEXTCTRL5, _("1970"), wxPoint(56,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
    TextCtrl6 = new wxTextCtrl(this, ID_TEXTCTRL6, _("2020"), wxPoint(200,104), wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Ano inicial"), wxPoint(80,88), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Ano final"), wxPoint(224,88), wxDefaultSize, 0, _T("ID_STATICTEXT5"));

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gerador_de_wordlistFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&gerador_de_wordlistFrame::OnButton2Click);
    //*)
}

gerador_de_wordlistFrame::~gerador_de_wordlistFrame()
{
    //(*Destroy(gerador_de_wordlistFrame)
    //*)
}

void gerador_de_wordlistFrame::OnQuit(wxCommandEvent& event) {
    Close();
}


void gerador_de_wordlistFrame::OnButton1Click(wxCommandEvent& event) {
    wxString prefixo, sufixo;

    prefixo = TextCtrl1->GetValue();
    sufixo = TextCtrl3->GetValue();

    cria_wordlist(prefixo, TextCtrl2->GetValue(), sufixo);
    TextCtrl4->SetValue("");
    TextCtrl4->SetValue(prefixo+TextCtrl2->GetValue()+sufixo+"  <<- Criada");
}

void cria_wordlist(wxString pre, wxString Lim, wxString sufix) {
   wxString prefixo, sufixo;
   FILE *arq;
    int limite, i;
    char prefixoS[20], sufixoS[20], nome_arq[100];

    prefixo = pre;
    limite = atoi(Lim.mbc_str());
    sufixo = sufix;
    strcpy(sufixoS, (const char*)sufixo.mbc_str());
    strcpy(prefixoS, (const char*)prefixo.mbc_str());

    sprintf(nome_arq,"%s-%d-%s.txt", prefixoS, limite, sufixoS);

    arq = fopen(nome_arq, "w");

    for (i = 0; i < limite; i++) {
        if (limite < 10)
          fprintf(arq, "%s%d%s\n", prefixoS, i, sufixoS);
        else if (limite < 100 && limite > 9)
          fprintf(arq, "%s%02d%s\n", prefixoS, i, sufixoS);
        else if (limite < 1000 && limite > 99)
          fprintf(arq, "%s%03d%s\n", prefixoS, i, sufixoS);
        else if (limite < 10000 && limite > 999)
          fprintf(arq, "%s%04d%s\n", prefixoS, i, sufixoS);
        else if (limite < 100000 && limite > 9999)
          fprintf(arq, "%s%05d%s\n", prefixoS, i, sufixoS);
        else if (limite < 1000000 && limite > 99999)
          fprintf(arq, "%s%06d%s\n", prefixoS, i, sufixoS);
        else if (limite < 10000000 && limite > 999999)
          fprintf(arq, "%s%07d%s\n", prefixoS, i, sufixoS);
        else if (limite < 100000000 && limite > 9999999)
          fprintf(arq, "%s%08d%s\n", prefixoS, i, sufixoS);

        //printf("\n %s %d %s ", prefixoS, i,  sufixoS);
    }
    fclose(arq);
}


void cria_wordlist_datas(wxString pre, wxString sufix, wxString ano_inicial, wxString ano_final ) {
   wxString prefixo, sufixo;
   FILE *arq;
   int mes = 1, dia = 1, ano = 1970, ano_fin;
   char prefixoS[20], sufixoS[20], nome_arq[100];

    ano = atoi(ano_inicial.mbc_str());
    ano_fin = atoi(ano_final.mbc_str());

    prefixo = pre;
    sufixo = sufix;
    strcpy(sufixoS, (const char*)sufixo.mbc_str());
    strcpy(prefixoS, (const char*)prefixo.mbc_str());

    sprintf(nome_arq,"%s-%d_%d-%s.txt", prefixoS,ano, ano_fin, sufixoS);

    arq = fopen(nome_arq, "w");

  while (ano < ano_fin){
      fprintf(arq, "\n%02d%02d%4d", dia, mes, ano);
      fprintf(arq, "\n%4d%02d%02d", ano, mes, dia);
      //com baras EX: "01/02/1995"
      fprintf(arq, "\n%02d/%02d/%4d", dia, mes, ano);
      fprintf(arq, "\n%4d/%02d/%02d", ano, mes, dia);
      //com tracos EX: "01-02-1999"
      fprintf(arq, "\n%02d-%02d-%4d", dia, mes, ano);
      fprintf(arq, "\n%4d-%02d-%02d", ano, mes, dia);

      if (dia <= 31)
        dia++;
      else {
        mes++;
        dia = 1;
        if(mes > 12) {
          ano++;
          dia = 1;
          mes = 1;
        }
      }
  }
  printf("\n\nLista criada!");
  fclose(arq);
}

void gerador_de_wordlistFrame::OnButton2Click(wxCommandEvent& event)
{
   wxString prefixo, sufixo, ano_f, ano_i;

    prefixo = TextCtrl1->GetValue();
    sufixo = TextCtrl3->GetValue();
    ano_i = TextCtrl5->GetValue();
    ano_f = TextCtrl6->GetValue();


    cria_wordlist_datas(prefixo, sufixo, ano_i, ano_f);
    TextCtrl4->SetValue("");
    TextCtrl4->SetValue(prefixo + "-" + ano_i + "/" + ano_f + "-" + sufixo + "  <<- Criada" );
}
