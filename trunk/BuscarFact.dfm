�
 TFBUSCARFACT 0�  TPF0TFBuscarFactFBuscarFactLeft�Top� WidthHeightBorderIconsbiSystemMenu CaptionBuscar FacturaFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.Style PositionpoScreenCenterWindowStatewsMaximizedOnShowFormShowPixelsPerInch`
TextHeight TLabelLabel1Left(TopWidth� HeightCaptionIntroduzca el n�mero de Factura  TLabelLabel2LeftoTop@Width� HeightCaptionN�mero de Factura en CursoFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold 
ParentFont  TLabelidentificativoLeft@Top@Width	HeightCaption8Font.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold 
ParentFont  TEditNumFactLeft�TopWidthIHeightTabOrder OnChangeNumFactChangeOnClickNumFactClick  TButtonBAceptarLeftXTopWidthQHeight!CaptionBuscarEnabledTabOrderOnClickBAceptarClick  	TGroupBox	GroupBox2Left� TophWidth�Height� CaptionDatos de la FacturaTabOrder TLabelLabel12Left�Top$WidthHeightCaptionMano  TLabelLabel15LeftpTopWidth� HeightCaption%Formato -> dd/mm/aaaa, Ej: 12/05/2002  TLabelLabel6LeftxTop$WidthUHeightCaptionFecha de Entrada  TLabelLabel7LeftxTopDWidthMHeightCaptionFecha de Salida  TEditmanoLeft�Top$WidthyHeightTabOrder   TEditfechEntradaLeft� Top$WidthAHeightTabOrder  TEdit
fechSalidaLeft� TopDWidthAHeightTabOrder   TButton
BModLineasLeft(Top0Width�Height)CaptionModificar Lineas de la FacturaEnabledFont.CharsetANSI_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameTimes New Roman
Font.StylefsBold 
ParentFontParentShowHintShowHintTabOrderOnClickBModLineasClick  	TGroupBox	GroupBox1Left� Top� Width�Height!CaptionDatos del VehiculoTabOrder TLabelLabel4LeftTop<Width)HeightCaptionVehiculo  TLabelLabel3LeftTopdWidthHeightCaptionMarca  TLabelLabel5LeftxTop(Width+HeightCaption	Matricula  TLabelLabel8LeftTop� Width%HeightCaptionNombre  TLabelLabel11Left&Top� WidthHeightCaptionDNI  TLabelLabel9LeftTop� Width-HeightCaption	Direcci�n  TLabelLabel10LeftOTop� Width*HeightCaptionTel�fono  TEditVehiculoLeftPTop<Width� HeightColorclMenuReadOnly	TabOrder   TEditMarcaLeftPTopdWidth)HeightColorclMenuReadOnly	TabOrder  TEdit	matriculaLeft�Top$WidthAHeightColorclMenuReadOnly	TabOrder  TEditnombreLeftPTop� WidthIHeightColorclMenuReadOnly	TabOrder  TEditdniLeftPTop� WidthyHeightColorclMenuReadOnly	TabOrder  TEditdirLeftPTop� Width� HeightColorclMenuReadOnly	TabOrder  TEdittlfLeft�Top� WidthyHeightColorclMenuReadOnly	TabOrder  TButtonBModVehiculoLeft�TopxWidth� Height)CaptionModificar Datos VehiculoEnabledTabOrderOnClickBModVehiculoClick  TButtonBCambiarVehiculoLeftTopWidthyHeight*CaptionCambiar VehiculoEnabledTabOrderOnClickBCambiarVehiculoClick   TButton
BModificarLeftToppWidth�HeightQCaptionConfirmar Datos FacturaEnabledFont.CharsetDEFAULT_CHARSET
Font.ColorclWindowTextFont.Height�	Font.NameMS Sans Serif
Font.StylefsBold 
ParentFontTabOrderOnClickBModificarClick  TQueryQuery1CachedUpdates	DatabaseName.\TablasSQL.Strings3select * from factura where id_fact=:identificativo Params.Data
     identificativo        LeftkTop  TDataSourceDataSource1DataSetQuery1Left�Top  TQueryQuery2DatabaseName.\TablasSQL.Strings1delete from factura where id_fact=:identificativo Params.Data
     identificativo    Left�Top  TQuery	QVehiculoDatabaseName.\TablasLeftxTopP   