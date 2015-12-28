//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Clientes.h"
#include "Factura.h"
#include "Tablas.h"
#include "Listado.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFClientes *FClientes;

int clave;
bool existe;
//---------------------------------------------------------------------------
__fastcall TFClientes::TFClientes(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

int __fastcall PrimeraClaveDisponible(TTable *Tabla,const System::AnsiString NombreClave)
{
    Tabla->Open();
    //int i=0;
    //bool encontrado=false;
    int numCampos=Tabla->RecordCount;
    return numCampos + 1;
    /*Tabla->First();
    while ((i<numCampos) && (!encontrado)) {
        //Hacer un try...catch
        if (Tabla->FieldByName (NombreClave)->AsInteger > (i+1))
            encontrado=true;
        else {
            Tabla->Next();
            i++;
        }
    }
    return i+1;*/
}

//---------------------------------------------------------------------------
void __fastcall TFClientes::BAceptarClick(TObject *Sender)
 {


   //Introduciendo los datos del cliente en la factura
   /*FListado->vehiculo->Caption = Vehiculo->Text;
   FListado->marca->Caption = Marca->Text;
   FListado->matricula->Caption = Matricula->Text;
   FListado->f_ent->Caption = FEntrada->Text;
   FListado->f_sal->Caption = FSalida->Text;
   FListado->nombre->Caption = Nombre->Text;
   FListado->domicilio->Caption = Direccion->Text;
   FListado->dni->Caption = DNI->Text;
   FListado->telefono->Caption = Telefono->Text;*/

   // Se introducirán los datos de la factura en la tabla correspondiente
   // de la BD. No se inserta realmente, ya que hay que esperar a terminar
   // la factura, cuando se pulsa el boton finalizar de la factura.
   MTablas->TFactura->Close();
   MTablas->TFactura->Open();
   clave=PrimeraClaveDisponible(MTablas->TFactura,"id_fact");
   MTablas->TFactura->Insert();
   MTablas->TFactura->FieldByName ("id_fact")->AsInteger=clave;
   MTablas->TFactura->FieldByName ("f_ent")->AsString=FEntrada->Text;
   MTablas->TFactura->FieldByName ("f_sal")->AsString=FSalida->Text;
   MTablas->TFactura->FieldByName ("dni")->AsString=DNI->Text;
   MTablas->TFactura->FieldByName ("matricula")->AsString=Matricula->Text;
   MTablas->TFactura->FieldByName("Nombre")->AsString=Nombre->Text;
   MTablas->TFactura->FieldByName("Direccion")->AsString=Direccion->Text;
   MTablas->TFactura->FieldByName("Telefono")->AsString=Telefono->Text;
   MTablas->TFactura->FieldByName("Vehiculo")->AsString=Vehiculo->Text;
   MTablas->TFactura->FieldByName("Marca")->AsString= Marca->Text;
   MTablas->TFactura->FieldByName("Kms")->AsInteger= StrToInt(kms->Text);

   //MTablas->TFactura->Edit();
   //MTablas->TFactura->Post();
   //MTablas->TFactura->Close();
   //Introducción de los datos de los vehiculos dentro de la tabla
   //coche.DB, en el caso de que el coche no exista
   if (!existe){
    MTablas->TCoche->Close();
    MTablas->TCoche->Open();
    MTablas->TCoche->Insert();
    MTablas->TCoche->FieldByName ("Dni")->AsString=DNI->Text;
    MTablas->TCoche->FieldByName ("matricula")->AsString=Matricula->Text;
    MTablas->TCoche->FieldByName("Nombre")->AsString=Nombre->Text;
    MTablas->TCoche->FieldByName("Direccion")->AsString=Direccion->Text;
    MTablas->TCoche->FieldByName("Telefono")->AsString=Telefono->Text;
    MTablas->TCoche->FieldByName("Vehiculo")->AsString=Vehiculo->Text;
    MTablas->TCoche->FieldByName("Marca")->AsString= Marca->Text;
    MTablas->TCoche->Post();
   }//Final del if

   //Se cierre el formulario actual
   FClientes->Visible=false;
   //Se abre el formulario para ir insertando las lineas de la factura
   FFactura->Show();


}
//---------------------------------------------------------------------------

void __fastcall TFClientes::BCancelarClick(TObject *Sender)
{
MTablas->TFactura->Cancel();
MTablas->TFactura->Close();
FClientes->Close();    
}
//---------------------------------------------------------------------------

void __fastcall TFClientes::FormShow(TObject *Sender)
{
    existe=false;
    Vehiculo->Clear();
    Marca->Clear();
    Matricula->Clear();
    FEntrada->Clear();
    FSalida->Clear();
    kms->Clear();
    Nombre->Clear();
    DNI->Clear();
    Direccion->Clear();
    Telefono->Clear();
    BBuscar->Enabled=false;
    DNI->ReadOnly=false;
    Matricula->ReadOnly=false;
    Nombre->ReadOnly=false;
    Direccion->ReadOnly=false;
    Telefono->ReadOnly=false;
    Vehiculo->ReadOnly=false;
    Marca->ReadOnly=false;
    BAceptar->Enabled=false;
    DNI->Color=miColor->Color;
    Nombre->Color=miColor->Color;
    Direccion->Color=miColor->Color;
    Telefono->Color=miColor->Color;
    Vehiculo->Color=miColor->Color;
    Marca->Color=miColor->Color;


}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TFClientes::BBuscarClick(TObject *Sender)
{
    //QBuscar->ParamByName("mat")->AsString=Matricula->Text;
    //QBuscar->SQL->Add("select * from factura where Matricula='"+Matricula->Text+"'");
    String sql = "select * from coche where Matricula='"+Matricula->Text+"'";
    QBuscar->SQL->Clear();
    QBuscar->SQL->Add(sql);
    QBuscar->ExecSQL();
    QBuscar->Open();
    if(QBuscar->IsEmpty()){
        MessageBox(0,"Esta matricula no se ha encontrado. \n Introduzca los datos manualmente." ,"Aviso de error",0);
        DNI->Color=kms->Color;
        Nombre->Color=kms->Color;
        Direccion->Color=kms->Color;
        Telefono->Color=kms->Color;
        Vehiculo->Color=kms->Color;
        Marca->Color=kms->Color;
    }
    else{
        existe=true;
        DNI->Text=QBuscar->FieldByName ("dni")->AsString;
        Matricula->Text=QBuscar->FieldByName ("matricula")->AsString;
        Nombre->Text=QBuscar->FieldByName("Nombre")->AsString;
        Direccion->Text=QBuscar->FieldByName("Direccion")->AsString;
        Telefono->Text=QBuscar->FieldByName("Telefono")->AsString;
        Vehiculo->Text=QBuscar->FieldByName("Vehiculo")->AsString;
        Marca->Text=QBuscar->FieldByName("Marca")->AsString;
        //Si el coche existe no se pueden modificar sus datos
        DNI->ReadOnly=true;
        Matricula->ReadOnly=true;
        Nombre->ReadOnly=true;
        Direccion->ReadOnly=true;
        Telefono->ReadOnly=true;
        Vehiculo->ReadOnly=true;
        Marca->ReadOnly=true;
    }
    BBuscar->Enabled=false;
    BAceptar->Enabled=true;
}
//---------------------------------------------------------------------------


void __fastcall TFClientes::MatriculaKeyPress(TObject *Sender, char &Key)
{
    BBuscar->Enabled=true;
}
//---------------------------------------------------------------------------
void __fastcall TFClientes::MatriculaChange(TObject *Sender)
{
    BBuscar->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TFClientes::MatriculaClick(TObject *Sender)
{
    BBuscar->Enabled=true;    
}
//---------------------------------------------------------------------------

