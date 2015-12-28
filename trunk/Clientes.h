//---------------------------------------------------------------------------
#ifndef ClientesH
#define ClientesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------

int __fastcall PrimeraClaveDisponible(TTable *Tabla,const System::AnsiString NombreClave);


class TFClientes : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TEdit *Nombre;
    TEdit *Direccion;
    TEdit *DNI;
    TLabel *Label6;
    TLabel *Label7;
    TLabel *Label8;
    TGroupBox *GroupBox2;
    TEdit *Vehiculo;
    TEdit *Marca;
    TEdit *Matricula;
    TEdit *FEntrada;
    TEdit *FSalida;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TBitBtn *BAceptar;
    TBitBtn *BCancelar;
    TEdit *Telefono;
    TLabel *Label9;
    TLabel *Label10;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TButton *BBuscar;
    TQuery *QBuscar;
    TEdit *kms;
    TLabel *Label14;
    TEdit *miColor;
    void __fastcall BAceptarClick(TObject *Sender);
    
    void __fastcall BCancelarClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    
    
    
    
    
    
    
    void __fastcall BBuscarClick(TObject *Sender);
    void __fastcall MatriculaKeyPress(TObject *Sender, char &Key);
    
    
    void __fastcall MatriculaChange(TObject *Sender);
    void __fastcall MatriculaClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        int clave;
    __fastcall TFClientes(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFClientes *FClientes;
//---------------------------------------------------------------------------
#endif
