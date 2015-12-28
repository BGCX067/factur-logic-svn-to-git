//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Prep.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFPrep *FPrep;
//---------------------------------------------------------------------------
__fastcall TFPrep::TFPrep(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

 void __fastcall TFPrep::prepararPresupuesto()
{
    Query->Close();
    Query->ExecSQL();
    Query->Open();
}
