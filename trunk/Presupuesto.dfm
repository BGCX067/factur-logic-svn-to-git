�
 TFPRESUPUESTO 0�  TPF0TFPresupuestoFPresupuestoLeft"Top� Width�Height�VertScrollBar.Position� CaptionRealizar PresupuestoFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style OnShowFormShowPixelsPerInch`
TextHeight TLabelLabel1Left�Top�Width� HeightCaptionLineas del PresupuestoFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold 
ParentFontLayouttlCenter  TLabelLabel2Left@Top� Width<HeightCaption
Componente  TLabelLabel3LeftJTop� Width*HeightCaptionCantidad  TLabelLabel4LeftPTop$WidthHeightCaptionPrecio  TLabelLabel5LeftHTop\Width5HeightCaption	Mano Obra  TDBGridDBGrid1Left Top�Width�Height� 
DataSource
DataSourceTabOrder TitleFont.CharsetDEFAULT_CHARSETTitleFont.ColorclWindowTextTitleFont.Height�TitleFont.NameMS Sans SerifTitleFont.Style Visible  TEdit
componenteLeft� Top� Width!HeightTabOrder  TEditcantidadLeft� Top� WidthyHeightTabOrder  TEditprecioLeft� TopWidthyHeightTabOrder  TEditmanoLeft� TopTWidthyHeightTabOrder  TPanelPanel1LeftTop<Width�Height� TabOrder TButton	BInsertarLeft-Top.Width� Height;CaptionInsertarTabOrder OnClickBInsertarClick  TButton	BImprimirLeftTop(Width� Height9CaptionImprimirTabOrderOnClickBImprimirClick   TQueryQueryDatabaseName.\TablasSQL.Strings#select * from linea where id_fact=0 LeftTop`  TDataSource
DataSourceDataSetQueryLeft`Top(  TQueryQueryBorrarDatabaseName.\TablasSQL.Strings!delete from linea where id_fact=0 Left� Top   