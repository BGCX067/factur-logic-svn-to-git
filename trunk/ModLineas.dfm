�
 TFMODLINEAS 0�
  TPF0TFModLineas
FModLineasLeft�Top� Width�Height�VertScrollBar.Position� BorderIconsbiSystemMenu CaptionModificaci�n de LineasFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style WindowStatewsMaximizedOnShowFormShowPixelsPerInch`
TextHeight TLabelLabel1LeftpTop� Width<HeightCaption
Componente  TLabelLabel2LeftxTopWidth*HeightCaptionCantidad  TLabelLabel3Left� Top=WidthHeightCaptionPrecio  TLabelLabel6Left�Top9�Width� HeightCaptionLineas de la FacturaFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold 
ParentFont  TLabeltotalLLeftTop�WidthHeightCaptiontotalL  TLabelLabel5Left� TopUWidth*HeightCaption5Para los valores con decimales se utilizar� la coma :Font.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold 
ParentFont  TLabelLabel7Left� TopeWidthkHeightCaptionPor ejemplo: 13,24Font.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold 
ParentFont  TDBGridDBGrid1Left8Top]�Width�Height!
DataSourceDataSource1TabOrder TitleFont.CharsetDEFAULT_CHARSETTitleFont.ColorclWindowTextTitleFont.Height�TitleFont.NameMS Sans SerifTitleFont.Style   TPanelPanel1Left�Top� Width	HeightQTabOrder TLabelLabel4Left,TopWidth� HeightCaption&Inserte el n�mero de linea a modificar  TEditnumLineaLeft Top(WidthYHeightTabOrder OnChangenumLineaChangeOnClicknumLineaClick  TButtonBSituarLeft� Top(WidthYHeightCaptionSituarTabOrderOnClickBSituarClick   TEdit
componenteLeft� Top� Width9HeightTabOrder  TEditcantidadLeft� TopWidthyHeightTabOrder  TEditprecioLeft� Top=WidthyHeightTabOrder  TPanelPanel2LeftTopWidth�Height� TabOrder TButton
BFinalizarLeft� TopXWidth� Height)Caption	FinalizarTabOrder OnClickBFinalizarClick  TButton	BInsertarLeft6TopWidth� Height1CaptionInsertarTabOrderOnClickBInsertarClick  TButtonBBorrarLeft� TopWidth� Height1CaptionBorrarEnabledTabOrder   TQueryQueryDatabaseName.\TablasLeftTop  TDataSourceDataSource1DataSetQueryLeft8Top  TQuery
QueryLineaDatabaseName.\TablasLefthTop  TQueryQueryUpdateDatabaseName.\TablasSQL.Strings?update factura set piezas=:totalP where id_fact=:identificativo Params.Data
"     totalP    identificativo    Left� Top   