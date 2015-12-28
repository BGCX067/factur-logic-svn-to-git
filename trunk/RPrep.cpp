//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "RPrep.h"
#include "Tablas.h"
#include "Prep.h"
#include "Math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFRPrep *FRPrep;
//---------------------------------------------------------------------------
__fastcall TFRPrep::TFRPrep(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFRPrep::BInsertarClick(TObject *Sender)
{
    BImprimir->Enabled=true;
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
    total+=(StrToFloat(precio->Text))*(StrToInt(cantidad->Text));
    Query->Close();
    Query->ExecSQL();
    Query->Open();
    DBGrid1->Hide();
    DBGrid1->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFRPrep::BImprimirClick(TObject *Sender)
{
    MTablas->TLinea->Close();
    if (mano->Text=="")
      MessageBox(0,"Debes Introducir la Mano de Obra" ,"Aviso de error",0);
    else if (matricula->Text=="")
      MessageBox(0,"Debes Introducir la Matricula del Vehicullo" ,"Aviso de error",0);
    else{
        //Matricula del Vehiculo
        FPrep->Matricula->Caption=matricula->Text;
        //Importe de las piezas
        FPrep->piezas->Caption=total;
        //Importe de piezas mas la mano de obra
        total+=StrToFloat(mano->Text);
        //Calculo del iva
        iva=(total*18.0)/100;
        double aux = floor(iva*100);
        iva=(double)aux/100;
        FPrep->iva->Caption=iva;
        //Calculo del total
        total+=iva;
        FPrep->total->Caption=total;
        FPrep->mano->Caption=mano->Text;

        FPrep->prepararPresupuesto();
        FPrep->QuickRep1->Prepare();
        FPrep->QuickRep1->Preview();
        this->Close();
    }//Final de la estructura else-if
}
//---------------------------------------------------------------------------
void __fastcall TFRPrep::FormShow(TObject *Sender)
{
    DBGrid1->Hide();
    componente->Clear();
    cantidad->Clear();
    precio->Clear();
    BImprimir->Enabled=false;
    numLineas=1;
    total=0;
    QueryBorrar->ExecSQL();
    //MessageBox(0,"Borrado realizado" ,"Aviso de error",0);
    //QueryBorrar->CommitUpdates();
}
//---------------------------------------------------------------------------//Final del metodo prepararPresupuesto




