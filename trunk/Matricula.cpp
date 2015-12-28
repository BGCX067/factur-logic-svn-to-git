//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Matricula.h"
#include "BuscarFact.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFMatricula *FMatricula;
//---------------------------------------------------------------------------
__fastcall TFMatricula::TFMatricula(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TFMatricula::BCancelarClick(TObject *Sender)
{
    this->Close();    
}
//---------------------------------------------------------------------------

void __fastcall TFMatricula::BAceptarClick(TObject *Sender)
{
    this->Close();
    FBuscarFact->BuscarVehiculo(matricula->Text);
}
//---------------------------------------------------------------------------

