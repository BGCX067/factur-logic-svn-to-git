//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "ModVehiculo.h"
#include "Tablas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFModVehiculo *FModVehiculo;
//---------------------------------------------------------------------------
__fastcall TFModVehiculo::TFModVehiculo(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFModVehiculo::BBuscarClick(TObject *Sender)
{
    String sql = "select * from coche where Matricula='"+matricula->Text+"'";
    QBuscar->SQL->Clear();
    QBuscar->SQL->Add(sql);
    QBuscar->ExecSQL();
    QBuscar->Open();

    if(QBuscar->IsEmpty())
        MessageBox(0,"Esta matricula no se ha encontrado." ,"Aviso de error",0);
    else{
        BoxPropietario->Visible=true;
        BoxVehiculo->Visible=true;
        DNI->Text=QBuscar->FieldByName ("dni")->AsString;
        matricula->Text=QBuscar->FieldByName ("matricula")->AsString;
        Nombre->Text=QBuscar->FieldByName("Nombre")->AsString;
        Direccion->Text=QBuscar->FieldByName("Direccion")->AsString;
        Telefono->Text=QBuscar->FieldByName("Telefono")->AsString;
        Vehiculo->Text=QBuscar->FieldByName("Vehiculo")->AsString;
        Marca->Text=QBuscar->FieldByName("Marca")->AsString;
        BAceptar->Enabled=true;
        BCancelar->Enabled=true;
        BBuscar->Enabled=false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TFModVehiculo::BAceptarClick(TObject *Sender)
{
     String sql = "delete  from coche where Matricula='"+matricula->Text+"'";
     QBuscar->SQL->Clear();
     QBuscar->SQL->Add(sql);
     QBuscar->ExecSQL();

     MTablas->TCoche->Close();
     MTablas->TCoche->Open();
     MTablas->TCoche->Insert();
     MTablas->TCoche->FieldByName ("dni")->AsString=DNI->Text;
     MTablas->TCoche->FieldByName ("Matricula")->AsString=matricula->Text;
     MTablas->TCoche->FieldByName ("Vehiculo")->AsString=Vehiculo->Text;
     MTablas->TCoche->FieldByName ("Nombre")->AsString=Nombre->Text;
     MTablas->TCoche->FieldByName ("Telefono")->AsString=Telefono->Text;
     MTablas->TCoche->FieldByName ("Direccion")->AsString=Direccion->Text;
     MTablas->TCoche->FieldByName ("Marca")->AsString=Marca->Text;
     MTablas->TCoche->Post();
     MessageBox(0,"Datos del Vehiculo Modificados" ,"Aviso de error",0);
     sql = "update factura set dni='"+DNI->Text+"', Vehiculo='"+Vehiculo->Text+"', Nombre='"+Nombre->Text+"',Telefono='"+Telefono->Text+"', Direccion='"+Direccion->Text+"', Marca='"+Marca->Text+"' where Matricula='"+matricula->Text+"'";
     Tsql->Caption=sql;
     QBuscar->SQL->Clear();
     QBuscar->SQL->Add(sql);
     QBuscar->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TFModVehiculo::BCancelarClick(TObject *Sender)
{
    this->Visible=false;    
}
//---------------------------------------------------------------------------




void __fastcall TFModVehiculo::FormShow(TObject *Sender)
{
    DNI->Clear();
    matricula->Clear();
    Nombre->Clear();
    Vehiculo->Clear();
    Telefono->Clear();
    Marca->Clear();
    Direccion->Clear();
    BBuscar->Enabled=false;
    BAceptar->Enabled=false;
    BCancelar->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TFModVehiculo::matriculaClick(TObject *Sender)
{
    BBuscar->Enabled=true;
    BAceptar->Enabled=false;
    BCancelar->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TFModVehiculo::matriculaChange(TObject *Sender)
{
   BBuscar->Enabled=true;
   BAceptar->Enabled=false;
   BCancelar->Enabled=false;
}
//---------------------------------------------------------------------------

