//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Buscar.h"
#include "Listado.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFBuscar *FBuscar;
//---------------------------------------------------------------------------
__fastcall TFBuscar::TFBuscar(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFBuscar::BBuscarClick(TObject *Sender)
{
    String sql;
/* Query1->Relacionada con la tabla factura.DB
   SuperQuery->Relacionada con la tabla linea.DB
*/
/*Detección del tipo de Búsqueda*/
if (numFact->Checked==true){
    Query1->ParamByName("identificativo")->AsInteger=StrToInt(clave->Text);
    Query1->Close();
    Query1->Open();
    if (Query1->IsEmpty())
        MessageBox( 0,"Esta factura no existe, revisa el número introducido","",1);
    else{
       BBuscar->Enabled=false;
       DataSource1->DataSet=Query1;
       DBGrid1->Visible=true;
       BBuscar->Enabled=false;
       Label2->Visible=true;
       Label3->Visible=true;
       Label4->Visible=true;
    }//Final del else interno
}else{
    BBuscar->Enabled=false;
    sql = "select * from factura where Matricula='"+clave->Text+"'";
    SuperQuery->SQL->Clear();
    SuperQuery->SQL->Add(sql);
    SuperQuery->Close();
    SuperQuery->Open();
    if (!SuperQuery->IsEmpty()){
        DataSource1->DataSet=SuperQuery;
        DBGrid1->Visible=true;
        Label2->Visible=true;
        Label3->Visible=true;
        Label4->Visible=true;
    }else
        MessageBox( 0,"No existe ninguna factura relacionada con la matricula introducida","",1);
    /*Busque por matricula*/
}//Fin de la deteccion del tipo de busqueda
   
    factura->Visible = true;
    Label2->Visible = true;
    BDetallar->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TFBuscar::claveChange(TObject *Sender)
{
BBuscar->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TFBuscar::numFactClick(TObject *Sender)
{
    clave->ReadOnly=false;
}
//---------------------------------------------------------------------------

void __fastcall TFBuscar::matriculaClick(TObject *Sender)
{
    clave->ReadOnly=false;
}
//---------------------------------------------------------------------------


void __fastcall TFBuscar::facturaChange(TObject *Sender)
{
  BDetallar->Enabled=true; 
}
//---------------------------------------------------------------------------

void __fastcall TFBuscar::BDetallarClick(TObject *Sender)
{
      //Preparar la factura para la visualizacion

        DBGrid1->Visible=false;
        clave->Text="";
        FListado->prepararFactura(StrToInt(factura->Text));
        factura->Text="";
        BDetallar->Enabled=false;
        BBuscar->Enabled=false;
        // Impresión de la factura original
        FListado->duplicado->Caption="";
        FListado->QuickRep1->Prepare();
        FListado->QuickRep1->Preview();
        // Impresión del duplicado de la factura
        FListado->duplicado->Caption="DUPLICADO";
        FListado->QuickRep1->Prepare();
        FListado->QuickRep1->Preview();
        this->Close();
        /*String sql = "delete * from linea";
        SuperQuery->SQL->Clear();
        SuperQuery->SQL->Add(sql);
        SuperQuery->Close();
        SuperQuery->Open(); */

}//Final del metodo BDetallarClick
//---------------------------------------------------------------------------




void __fastcall TFBuscar::BSalirClick(TObject *Sender)
{
      this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TFBuscar::FormShow(TObject *Sender)
{
  clave->Clear();
  BBuscar->Enabled=false;
  Label2->Visible=false;
  Label3->Visible=false;
  Label4->Visible=false;
  DBGrid1->Visible=false;

}
//---------------------------------------------------------------------------

void __fastcall TFBuscar::claveClick(TObject *Sender)
{
  BBuscar->Enabled=true;
}
//---------------------------------------------------------------------------

