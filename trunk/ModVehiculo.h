//---------------------------------------------------------------------------
#ifndef ModVehiculoH
#define ModVehiculoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFModVehiculo : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TEdit *matricula;
    TButton *BBuscar;
    TLabel *Label11;
    TLabel *Label12;
    TLabel *Label13;
    TQuery *QBuscar;
    TGroupBox *BoxPropietario;
    TEdit *DNI;
    TLabel *Label1;
    TEdit *Nombre;
    TLabel *Label2;
    TEdit *Direccion;
    TLabel *Label3;
    TEdit *Telefono;
    TLabel *Label4;
    TGroupBox *BoxVehiculo;
    TLabel *Label5;
    TLabel *Label6;
    TEdit *Vehiculo;
    TEdit *Marca;
    TPanel *Panel1;
    TButton *BAceptar;
    TButton *BCancelar;
    TLabel *Tsql;
    void __fastcall BBuscarClick(TObject *Sender);
    void __fastcall BAceptarClick(TObject *Sender);
    void __fastcall BCancelarClick(TObject *Sender);
    
    void __fastcall FormShow(TObject *Sender);
    void __fastcall matriculaClick(TObject *Sender);
    void __fastcall matriculaChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TFModVehiculo(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFModVehiculo *FModVehiculo;
//---------------------------------------------------------------------------
#endif
