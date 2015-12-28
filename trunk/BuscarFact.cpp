//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "BuscarFact.h"
#include "Tablas.h"
#include "ModLineas.h"
#include "Matricula.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFBuscarFact *FBuscarFact;
int idFact;
//---------------------------------------------------------------------------
__fastcall TFBuscarFact::TFBuscarFact(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFBuscarFact::BCancelarClick(TObject *Sender)
{
    this->Close();    
}
//---------------------------------------------------------------------------
void __fastcall TFBuscarFact::BAceptarClick(TObject *Sender)
{
    idFact= StrToInt(NumFact->Text);
    Query1->ParamByName("identificativo")->AsInteger=idFact;
    Query1->ExecSQL();
    Query1->Open();
    if (Query1->IsEmpty()){
        MessageBox(0,"Esta factura no existe" ,"Aviso de error",0);
        BModificar->Enabled=false;
        BModLineas->Enabled=false;
    }else{
        BModificar->Enabled=true;
        BModLineas->Enabled=true;
        BCambiarVehiculo->Enabled=true;
        BModVehiculo->Enabled=true;
        BAceptar->Enabled=false;
        identificativo->Caption=Query1->FieldByName("id_fact")->AsString;
        Vehiculo->Text=Query1->FieldByName("Vehiculo")->AsString;
        Marca->Text=Query1->FieldByName("Marca")->AsString;
        matricula->Text=Query1->FieldByName("Matricula")->AsString;
        fechEntrada->Text=Query1->FieldByName("f_ent")->AsString;
        fechSalida->Text=Query1->FieldByName("f_sal")->AsString;
        nombre->Text=Query1->FieldByName("Nombre")->AsString;
        dir->Text=Query1->FieldByName("Direccion")->AsString;
        tlf->Text=Query1->FieldByName("Telefono")->AsString;
        dni->Text=Query1->FieldByName("dni")->AsString;
        mano->Text=Query1->FieldByName("mano")->AsString;
    }//Final del else
    Query1->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFBuscarFact::BModificarClick(TObject *Sender)
{


     Query2->ParamByName("identificativo")->AsInteger=idFact;
     Query2->ExecSQL();
     MTablas->TFactura->Close();
     MTablas->TFactura->Open();
     MTablas->TFactura->Insert();
     MTablas->TFactura->FieldByName ("id_fact")->AsInteger=idFact;
     MTablas->TFactura->FieldByName ("f_ent")->AsString=fechEntrada->Text;
     //MTablas->TFactura->Edit();
     MTablas->TFactura->FieldByName ("f_sal")->AsString=fechSalida->Text;
     MTablas->TFactura->FieldByName ("dni")->AsString=dni->Text;
     MTablas->TFactura->FieldByName ("mano")->AsFloat=StrToFloat(mano->Text);
     MTablas->TFactura->FieldByName ("Matricula")->AsString=matricula->Text;
     MTablas->TFactura->FieldByName ("Vehiculo")->AsString=Vehiculo->Text;
     MTablas->TFactura->FieldByName ("Nombre")->AsString=nombre->Text;
     MTablas->TFactura->FieldByName ("Telefono")->AsString=tlf->Text;
     MTablas->TFactura->FieldByName ("Direccion")->AsString=dir->Text;
     MTablas->TFactura->FieldByName ("Marca")->AsString=Marca->Text;
     MTablas->TFactura->Post();
     MessageBox(0,"La Factura ha sido Modificada" ,"Aviso de error",0);
     this->Close();

}
//--------------------------------------------------------------- ------------
void __fastcall TFBuscarFact::BModLineasClick(TObject *Sender)
{
    FModLineas->idFact=idFact;
    FModLineas->Visible=true;
}
//---------------------------------------------------------------------------
void __fastcall TFBuscarFact::BModVehiculoClick(TObject *Sender)
{
    MessageBox(0,"Para cambiar las propiedades del vehiculo \n acuda a 'Modificar Vehiculos'\n Si desea asignar otro coche deberá pulsar al botón de 'Cambiar Vehiculo'" ,"Aviso de error",0);
}
//---------------------------------------------------------------------------

void __fastcall TFBuscarFact::FormShow(TObject *Sender)
{       Vehiculo->Clear();
        fechEntrada->Clear();
        fechSalida->Clear();
        dni->Clear();
        mano->Clear();
        nombre->Clear();
        tlf->Clear();
        dir->Clear();
        Marca->Clear();
        matricula->Clear();
        identificativo->Caption="";
        NumFact->Clear();
        BAceptar->Enabled=false;
        BModificar->Enabled=false;
        BModLineas->Enabled=false;
        BModVehiculo->Enabled=false;
        BCambiarVehiculo->Enabled=false;

}
//---------------------------------------------------------------------------

void __fastcall TFBuscarFact::NumFactClick(TObject *Sender)
{
     BAceptar->Enabled=true;
     BModificar->Enabled=false;
     BModLineas->Enabled=false;
     BModVehiculo->Enabled=false;
     BCambiarVehiculo->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TFBuscarFact::NumFactChange(TObject *Sender)
{
    BAceptar->Enabled=true;
    BModificar->Enabled=false;
    BModLineas->Enabled=false;
    BModVehiculo->Enabled=false;
    BCambiarVehiculo->Enabled=false;
}
//---------------------------------------------------------------------------



void __fastcall TFBuscarFact::BCambiarVehiculoClick(TObject *Sender)
{
    FMatricula->Show();    
}
//---------------------------------------------------------------------------
void __fastcall TFBuscarFact::BuscarVehiculo(String mat){
//haber si aguanta
    String sql = "select * from coche where Matricula='"+mat+"'";
    QVehiculo->SQL->Clear();
    QVehiculo->SQL->Add(sql);
    QVehiculo->ExecSQL();
    QVehiculo->Open();
    if (QVehiculo->IsEmpty())
        MessageBox(0,"El vehiculo especificado NO existe. \n Revise el listado de sus coches." ,"Aviso de error",0);
    else{
        MessageBox(0,"El vehiculo especificado existe. \n Sus datos serán insertado dentro de la factura en curso." ,"Aviso de error",0);
        Vehiculo->Text=QVehiculo->FieldByName("Vehiculo")->AsString;
        Marca->Text=QVehiculo->FieldByName("Marca")->AsString;
        matricula->Text=QVehiculo->FieldByName("Matricula")->AsString;
        nombre->Text=QVehiculo->FieldByName("Nombre")->AsString;
        dir->Text=QVehiculo->FieldByName("Direccion")->AsString;
        tlf->Text=QVehiculo->FieldByName("Telefono")->AsString;
        dni->Text=QVehiculo->FieldByName("dni")->AsString;
    }
}//Final del metodo BuscarVehiculo


