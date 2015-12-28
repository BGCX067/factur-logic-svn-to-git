//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Prep.h"
#include "Tablas.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TFPresupuesto *FPresupuesto;
//---------------------------------------------------------------------------
__fastcall TFPresupuesto::TFPresupuesto(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFPresupuesto::BInsertarClick(TObject *Sender)
{
//Inserción de la linea del presuesto dentro de la tabla linea
MTablas->TLinea->Close();
MTablas->TLinea->Open();
MTablas->TLinea->Insert();
//El numero de factura para emular un presupuesto será el 0
MTablas->TLinea->FieldByName("id_fact")->AsInteger=0;
MTablas->TLinea->FieldByName("id_linea")->AsInteger=numLineas;
MTablas->TLinea->FieldByName("componente")->AsString=componente->Text;
MTablas->TLinea->FieldByName("cantidad")->AsInteger=StrToInt(cantidad->Text);
MTablas->TLinea->FieldByName("precio")->AsFloat=StrToFloat(precio->Text);
MTablas->TLinea->FieldByName("total")->AsFloat=(StrToFloat(precio->Text))*(StrToInt(cantidad->Text));
MTablas->TLinea->Post();
numLineas++;
Query->Close();
Query->ExecSQL();
Query->Open();
DBGrid1->Hide();
DBGrid1->Show();

}
//---------------------------------------------------------------------------


void __fastcall TFPresupuesto::FormShow(TObject *Sender)
{
    numLineas=1;
    QueryBorrar->ExecSQL(); 
}
//---------------------------------------------------------------------------

void __fastcall TFPresupuesto::BImprimirClick(TObject *Sender)
{
 if (mano->Text=="")
      MessageBox(0,"Debes introducir la mano de obra" ,"Aviso de error",0);
 else{
        FPrep->QuickReport1->Prepare();
        FPrep->QuickReport1->Preview();
 }//Final de la estructura else-if
}
//---------------------------------------------------------------------------

