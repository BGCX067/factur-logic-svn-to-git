//---------------------------------------------------------------------------
#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Listado.h"
#include "Tablas.h"
#include "Factura.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFListado *FListado;

//---------------------------------------------------------------------------
__fastcall TFListado::TFListado(TComponent* Owner)
    : TForm(Owner)
{
}
//--------------------------------------------------------------------------



void __fastcall TFListado::QuickRep1AfterPreview(TObject *Sender)
{
FFactura->Close();    
}
//---------------------------------------------------------------------------

void __fastcall TFListado::prepararFactura(int id){
        double piezas, mano, iva, total;
        Superquery->ParamByName("identificativo")->AsInteger=id;
        QueryFact->ParamByName("identificativo")->AsInteger=id;
        QueryFact->Close();
        QueryFact->Open();
        Superquery->Close();
        Superquery->Open();

        piezas=QueryFact->FieldByName ("piezas")->AsFloat;
        mano=QueryFact->FieldByName ("mano")->AsFloat;
        //Falta de redondear el iva y el total de la factura que solo
        //aparecen en el impreso de la factura
        iva = 0.21 * (piezas + mano);
        long aux = floor(iva*100);
        iva=aux/100.0;
        //iva = iva /10000;
        total =  iva + piezas + mano;
        //total = total / 100000;
        this->total->Caption =   total;
        this->subtotal->Caption =   piezas + mano;
        this->iva->Caption = iva;
        //Falta calcular el iva y el total
}//Final de prepararFactura
//---------------------------------------------------------------------------
























