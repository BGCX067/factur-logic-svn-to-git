//---------------------------------------------------------------------------
#ifndef pruebaH
#define pruebaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFPrueba : public TForm
{
__published:	// IDE-managed Components
    TLabel *prueba1;
    TLabel *prueba2;
    TLabel *prueba3;
private:	// User declarations
public:		// User declarations
    __fastcall TFPrueba(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFPrueba *FPrueba;
//---------------------------------------------------------------------------
#endif
