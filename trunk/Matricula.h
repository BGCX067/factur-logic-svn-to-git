//---------------------------------------------------------------------------
#ifndef MatriculaH
#define MatriculaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFMatricula : public TForm
{
__published:	// IDE-managed Components
    TEdit *matricula;
    TLabel *Label1;
    TButton *BAceptar;
    TButton *BCancelar;
    void __fastcall BCancelarClick(TObject *Sender);
    void __fastcall BAceptarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFMatricula(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFMatricula *FMatricula;
//---------------------------------------------------------------------------
#endif
