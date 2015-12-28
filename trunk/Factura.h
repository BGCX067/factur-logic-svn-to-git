//---------------------------------------------------------------------------
#ifndef FacturaH
#define FacturaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
int __fastcall PrimeraClaveDisponible(TTable *Tabla,const System::AnsiString NombreClave);
void __fastcall GuardarEnTabla(TTable *Tabla,const System::AnsiString NombreClave);
void __fastcall BorrarEnTabla(TTable *Tabla, const System::AnsiString
                                NombreClave, const int clave);


class TFFactura : public TForm
{
__published:	// IDE-managed Components
    TDBText *factura;
    TLabel *Contador;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TBitBtn *BAceptar;
    TBitBtn *BCancelar;
    TDBGrid *DBGrid1;
    TQuery *SuperQuery;
    TDataSource *DataSource1;
    TEdit *ManoObra;
    TLabel *Label6;
    TButton *BFinalizar;
    TQuery *QueryBorrar;
    TDataSource *DataSource2;
    TLabel *Label7;
    TEdit *componente;
    TEdit *cantidad;
    TEdit *precio;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall BAceptarClick(TObject *Sender);
    void __fastcall BCancelarClick(TObject *Sender);
    void __fastcall BFinalizarClick(TObject *Sender);
    //void  __fastcall AnularAcciones();

    
    
    
private:	// User declarations

public:		// User declarations
    __fastcall TFFactura(TComponent* Owner);


    
};
//---------------------------------------------------------------------------
extern PACKAGE TFFactura *FFactura;
//---------------------------------------------------------------------------
#endif
