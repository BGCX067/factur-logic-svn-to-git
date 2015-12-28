//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Principal.h"
#include "Clientes.h"
#include "ModVehiculo.h"
#include "Buscar.h"
#include "prueba.h"
#include "RPrep.h"
#include "BuscarFact.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFPrincipal *FPrincipal;
//---------------------------------------------------------------------------
__fastcall TFPrincipal::TFPrincipal(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFPrincipal::BNuevaFacturaClick(TObject *Sender)
{
FClientes->Show();
//FPrueba->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFPrincipal::BSalirClick(TObject *Sender)
{
FPrincipal->Close();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::BConsulFacturaClick(TObject *Sender)
{
FBuscar->Show();
}
//---------------------------------------------------------------------------
void __fastcall TFPrincipal::BModificarClick(TObject *Sender)
{
    FBuscarFact->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFPrincipal::BPresupuestoClick(TObject *Sender)
{
    FRPrep->Show();
}
//---------------------------------------------------------------------------


void __fastcall TFPrincipal::BVehiculoClick(TObject *Sender)
{
   FModVehiculo->Show();
}
//---------------------------------------------------------------------------




