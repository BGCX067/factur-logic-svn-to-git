//---------------------------------------------------------------------------
#ifndef PrincipalH
#define PrincipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Qrctrls.hpp>
#include <quickrpt.hpp>
//---------------------------------------------------------------------------
class TFPrincipal : public TForm
{
__published:	// IDE-managed Components
    TBitBtn *BNuevaFactura;
    TBitBtn *BConsulFactura;
    TBitBtn *BSalir;
    TButton *BModificar;
    TButton *BPresupuesto;
    TButton *BVehiculo;
    TLabel *Label1;
    TLabel *Label2;
    TShape *Shape1;
    TLabel *Label3;
    TImage *Image1;
    void __fastcall BNuevaFacturaClick(TObject *Sender);
    void __fastcall BSalirClick(TObject *Sender);
    void __fastcall BConsulFacturaClick(TObject *Sender);
    
    
    void __fastcall BModificarClick(TObject *Sender);
    void __fastcall BPresupuestoClick(TObject *Sender);
    void __fastcall BVehiculoClick(TObject *Sender);
    
    
    
private:	// User declarations
public:		// User declarations
    __fastcall TFPrincipal(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPrincipal *FPrincipal;
//---------------------------------------------------------------------------
#endif
