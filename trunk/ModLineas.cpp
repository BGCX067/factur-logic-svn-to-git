//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "ModLineas.h"
#include "Tablas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
/* Dentro de esta unidad existen dos atributos para recoger los datos de la
 linea, que son idFact e idLinea*/
TFModLineas *FModLineas;
//---------------------------------------------------------------------------
__fastcall TFModLineas::TFModLineas(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFModLineas::FormShow(TObject *Sender)
{
    //Todos los botones estarán inactivos y las cajas limpias
    componente->Clear();
    cantidad->Clear();
    precio->Clear();
    numLinea->Clear();
    BSituar->Enabled=false;
    BInsertar->Enabled=false;
    BFinalizar->Enabled=false;
    this->estado=0;
    /*const char *mensaje="FFormShow"+idFact;
    MessageBox(0,mensaje ,"Aviso de error",0);*/
    String sql = "select * from linea where id_fact=";
    sql+=idFact;
    Query->SQL->Clear();
    Query->SQL->Add(sql);
    Query->ExecSQL();
    Query->Open();
    if (!Query->IsEmpty())
        DBGrid1->Show();
    else
        DBGrid1->Hide();
    //Query->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFModLineas::BSituarClick(TObject *Sender)
{
    //Se recoge la linea en curso
    this->idLinea=StrToInt(numLinea->Text);
    BSituar->Enabled=false;
    BInsertar->Enabled=true;
    String sql = "select * from linea where id_fact=";
    sql+=idFact;
    sql+=" AND id_linea=";
    sql+=idLinea;
    QueryLinea->SQL->Clear();
    QueryLinea->SQL->Add(sql);
    QueryLinea->ExecSQL();
    QueryLinea->Open();
    //Si la linea de la factura existe
    if (!QueryLinea->IsEmpty()){
        this->estado=1;
        //Mostrar datos en las cajas de texto
        componente->Text=QueryLinea->FieldByName("componente")->AsString;
        cantidad->Text=QueryLinea->FieldByName("cantidad")->AsString;
        precio->Text=QueryLinea->FieldByName("precio")->AsString;
        QueryLinea->Close();
        MessageBox(0,"Modifique los datos de la linea que desee \n en las cajas de texto inferiores","Aviso",0);
    }else{
        MessageBox(0,"Esta Linea no existe. \n Deberá introducir su datos en las cajas de texto inferiores","Aviso",0);
    }
}
//---------------------------------------------------------------------------


void __fastcall TFModLineas::BInsertarClick(TObject *Sender)
{

    String sql;
    if (estado==1){
        sql = "delete  from linea where id_fact=";
        sql+=idFact;
        sql+=" AND id_linea=";
        sql+=idLinea;
        QueryLinea->SQL->Clear();
        QueryLinea->SQL->Add(sql);
        QueryLinea->ExecSQL();
    }else{
    }//Final de la estructura if-else
    //Inserción de la linea en curso, ya sea modificada o nueva
     MTablas->TLinea->Close();
     MTablas->TLinea->Open();
     MTablas->TLinea->Insert();
     MTablas->TLinea->FieldByName ("id_fact")->AsInteger=idFact;
     MTablas->TLinea->FieldByName ("id_linea")->AsInteger=idLinea;
     MTablas->TLinea->FieldByName ("componente")->AsString=componente->Text;
     MTablas->TLinea->FieldByName ("cantidad")->AsInteger=StrToInt(cantidad->Text);
     MTablas->TLinea->FieldByName ("precio")->AsFloat=StrToFloat(precio->Text);
     MTablas->TLinea->FieldByName ("total")->AsFloat=(StrToInt(cantidad->Text))* (StrToFloat(precio->Text));
     MTablas->TLinea->Post();
    //Cambio de estado
    this->estado=0;
    //Visualizar en el dbGrid las lineas de la factura en curso
    sql = "select * from linea where id_fact=";
    sql+=idFact;
    Query->Close();
    Query->SQL->Clear();
    Query->SQL->Add(sql);
    Query->ExecSQL();
    Query->Open();
    if (!Query->IsEmpty())
        DBGrid1->Show();
    else
        DBGrid1->Hide();
    //Preparación de los componentes visuales
    numLinea->Clear();
    BInsertar->Enabled=false;
    BFinalizar->Enabled=true;
    BSituar->Enabled=false;
    componente->Clear();
    cantidad->Clear();
    precio->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TFModLineas::BFinalizarClick(TObject *Sender)
{
        //Cuando se de al boton de finalizar hay que calcular de nuevo
        //el campo piezas de la tabla Factura.DB, de la factura
        //cuyas lineas han sido modificadas.

        //Primero calcular el total, para ello se utilizara el elemento Query
        //ya que contiene todas las lineas de la factura en curso.
       double total=0;
        int numLineas=0;
        Query->Close();
        Query->Open();
        Query->First();
        while(!Query->Eof){
            numLineas++;
            total+=Query->FieldByName("total")->AsFloat;
            Query->Next();
        }//Final del bucle while

        //Faltaria redondear el total de las piezas
        /*total=total*1000;
        long aux = floor(total);
        total=aux/1000.0;*/
        totalL->Caption=total;
        QueryUpdate->ParamByName("totalP")->AsFloat=total;
        QueryUpdate->ParamByName("identificativo")->AsInteger=idFact;
        QueryUpdate->ExecSQL();
        MessageBox(0,"Las Lineas de la Factura han sido Modificadas" ,"Aviso de error",0);
        this->Close();

}
//---------------------------------------------------------------------------


void __fastcall TFModLineas::numLineaChange(TObject *Sender)
{
    BSituar->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TFModLineas::numLineaClick(TObject *Sender)
{
    BSituar->Enabled=true;  
}
//---------------------------------------------------------------------------

