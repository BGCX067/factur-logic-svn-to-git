�
 TFFACTURA 0   TPF0	TFFacturaFFacturaLeft�Top+BorderIcons BorderStylebsSingleCaption%Introduciendo los datos de la facturaClientHeightCClientWidth Font.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style WindowStatewsMaximizedOnShowFormShowPixelsPerInch`
TextHeight TDBTextfacturaLeft`TopWidth1Height	AlignmenttaCenter	DataFieldid_fact
DataSourceMTablas.FacturaDSFont.CharsetANSI_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameArial
Font.StylefsBoldfsItalic 
ParentFont  TLabelContadorLeft Top�Width	Height	AlignmenttaCenterCaption1Font.CharsetANSI_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameArial
Font.StylefsBold 
ParentFont  TLabelLabel2Left�Top�Width|HeightCaptionN�mero de lineaFont.CharsetANSI_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameArial
Font.StylefsBold 
ParentFont  TLabelLabel3LeftPTop�Width<HeightCaption
Componente  TLabelLabel4LeftPTopWidth*HeightCaptionCantidad  TLabelLabel5LeftPTop4WidthHeightCaptionPrecio  TLabelLabel6Left� TophWidthtHeightCaptionMANO DE OBRAFont.CharsetDEFAULT_CHARSET
Font.ColorclNavyFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold 
ParentFont  TLabelLabel7LeftXTopWidthHeightCaptionLineas de la factura n�meroFont.CharsetANSI_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameArial
Font.StylefsBoldfsItalic 
ParentFont  TBitBtnBAceptarLeft�TopWidthAHeightACaption&A�adir a  FacturaTabOrder OnClickBAceptarClick  TBitBtn	BCancelarLeft�Top�Width� Height1Caption	&CancelarTabOrderOnClickBCancelarClick  TDBGridDBGrid1LeftTop@Width�Heighti
DataSourceDataSource1TabOrderTitleFont.CharsetDEFAULT_CHARSETTitleFont.ColorclWindowTextTitleFont.Height�TitleFont.NameMS Sans SerifTitleFont.Style Visible  TEditManoObraLeft� Top�Width� HeightTabOrder  TButton
BFinalizarLeft�Top`WidthqHeightYCaption	FinalizarEnabledTabOrderOnClickBFinalizarClick  TEdit
componenteLeft� Top�Width�HeightTabOrder  TEditcantidadLeft� TopWidthIHeightTabOrder  TEditprecioLeft� Top(WidthaHeightTabOrder  TQuery
SuperQueryDatabaseName.\TablasSQL.Strings1select * from linea where id_fact=:identificativo Params.Data
     identificativo        Left�Top@  TDataSourceDataSource1DataSet
SuperQueryLeft�Top   TQueryQueryBorrarDatabaseName.\TablasSQL.Strings/delete from linea where id_fact=:identificativo Params.Data
     identificativo        Left�Top�  TDataSourceDataSource2DataSetQueryBorrarLeft�Top�   