//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Factura.h"
#include "Tablas.h"
#include "Clientes.h"
//#include "impreso.h"
#include "Listado.h"
#include "prueba.h"


//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFFactura *FFactura;
int cont, totalLineas;
double totalPiezas;

//---------------------------------------------------------------------------
__fastcall TFFactura::TFFactura(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void __fastcall GuardarEnTabla(TTable *Tabla,const System::AnsiString NombreClave)
{
    //Tabla->Edit();
    Tabla->Post();
    cont++;
    FFactura->Contador->Caption= IntToStr(cont);
    Tabla->Insert();
    Tabla->FieldByName (NombreClave)->AsInteger=cont;
    Tabla->FieldByName ("id_fact")->AsInteger=FClientes->clave;
}

//---------------------------------------------------------------------------
void __fastcall TFFactura::FormShow(TObject *Sender)
{
    cont=1;
    totalPiezas=0;
    totalLineas=0;
    Contador->Caption= IntToStr(cont);
    componente->Clear();
    cantidad->Clear();
    precio->Clear();
    MTablas->TLinea->Close();
    MTablas->TLinea->Open();
    MTablas->TLinea->Insert();
    MTablas->TLinea->FieldByName("id_linea")->AsInteger=cont;
    MTablas->TLinea->FieldByName("id_fact")->AsInteger=FClientes->clave;
    ManoObra->Clear();


}
//---------------------------------------------------------------------------

void __fastcall TFFactura::BAceptarClick(TObject *Sender)
{
//Insertar el contenido de la linea dentro de la tabla Linea.DB
MTablas->TLinea->FieldByName("componente")->AsString = componente->Text;
MTablas->TLinea->FieldByName("cantidad")->AsInteger = StrToInt(cantidad->Text);
MTablas->TLinea->FieldByName("precio")->AsFloat = StrToFloat(precio->Text);
MTablas->TLinea->FieldByName ("total")->AsFloat=(StrToInt(cantidad->Text))* (StrToFloat(precio->Text));
totalPiezas+= (StrToInt(cantidad->Text))* (StrToFloat(precio->Text));
GuardarEnTabla(MTablas->TLinea,"id_linea");
BFinalizar->Enabled=true;
SuperQuery->ParamByName("identificativo")->AsInteger=FClientes->clave;
SuperQuery->Close();
SuperQuery->Open();
componente->Clear();
cantidad->Clear();
precio->Clear();
DBGrid1->Show();
}
//---------------------------------------------------------------------------
void __fastcall BorrarEnTabla(TTable *Tabla, const System::AnsiString
                                NombreClave, const int clave){
  Tabla->Open();
  int i=0;
  int numReg=Tabla->RecordCount;
  Tabla->First();
  while (i<=numReg)
  {
    if (Tabla->FieldByName(NombreClave)->AsInteger==clave){
        Tabla->Delete();
        i++;
    }
    else{
        Tabla->Next();
        i++;
    }
  }//Fin del while
}//FIN del metodo BorrarEnTabla




//---------------------------------------------------------------------------

void __fastcall TFFactura::BFinalizarClick(TObject *Sender)
{
    //float Iva;
    if (ManoObra->Text=="")
      MessageBox(0,"Debes introducir la mano de obra" ,"Aviso de error",0);
    else{

        //Se termina de almacenar los datos de la factura dentro de la tabla
        //factura.DB, asi como de rellenar los campos que faltan.
        //Falta de redondear el total de las piezas instaladas
        MTablas->TFactura->FieldByName ("piezas")->AsFloat=totalPiezas;
        MTablas->TFactura->FieldByName ("mano")->AsFloat=StrToFloat(ManoObra->Text);
        MTablas->TFactura->Edit();
        MTablas->TFactura->Post();
        DBGrid1->Hide();
        //Preparar la factura para la visualizacion
        FListado->prepararFactura(FClientes->clave);
        // Impresión de la factura original
        FListado->duplicado->Caption="";
        FListado->QuickRep1->Prepare();
        FListado->QuickRep1->Preview();
        //FListado->QuickRep1->Print();
        // Impresión del duplicado de la factura
        FListado->duplicado->Caption="DUPLICADO";
        FListado->QuickRep1->Prepare();
        FListado->QuickRep1->Preview();
        /*FListado->QuickRep1->Print();
        FFactura->Close(); */
        }//Fin del else
}//Final del metodo de BFinalizarClick
//---------------------------------------------------------------------------
void __fastcall TFFactura::BCancelarClick(TObject *Sender){
    DBGrid1->Hide();
    //Eliminción de todas las lineas de la factura en curso
    BorrarEnTabla(MTablas->TLinea,"id_fact",FClientes->clave);
    //Cancelación de la inserción de la linea de la factura
    MTablas->TLinea->Cancel();
    MTablas->TLinea->Close();
    // Cancelación de la inserción de los datos de la factura,
    // iniciada en el formulario "FClientes"
    MTablas->TFactura->Cancel();
    MTablas->TFactura->Close();
    FFactura->Close();
}//Final del metodo de BCancelarClick
//---------------------------------------------------------------------------
 /*
    Anular las inserciones realizadas
 */
//Final del metdo FormClose
//---------------------------------------------------------------------------








