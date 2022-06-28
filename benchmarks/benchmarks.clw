; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
ClassCount=3
Class1=CBenchmarksApp
LastClass=CPublishersSet
NewFileInclude2=#include "benchmarks.h"
ResourceCount=0
NewFileInclude1=#include "stdafx.h"
Class2=CBooksSet
LastTemplate=CDaoRecordset
Class3=CPublishersSet

[CLS:CBenchmarksApp]
Type=0
HeaderFile=benchmarks.h
ImplementationFile=benchmarks.cpp
Filter=N
LastObject=CBenchmarksApp

[CLS:CBooksSet]
Type=0
HeaderFile=BooksSet.h
ImplementationFile=BooksSet.cpp
BaseClass=CDaoRecordset
Filter=N
VirtualFilter=x
LastObject=CBooksSet

[DB:CBooksSet]
DB=1
DBType=DAO
ColumnCount=8
Column1=[Title], 12, 255
Column2=[Year Published], 5, 2
Column3=[ISBN], 12, 20
Column4=[PubID], 4, 4
Column5=[Description], 12, 50
Column6=[Notes], 12, 50
Column7=[Subject], 12, 50
Column8=[Comments], -1, 0

[CLS:CPublishersSet]
Type=0
HeaderFile=PublishersSet.h
ImplementationFile=PublishersSet.cpp
BaseClass=CDaoRecordset
Filter=N
VirtualFilter=x
LastObject=CPublishersSet

[DB:CPublishersSet]
DB=1
DBType=DAO
ColumnCount=10
Column1=[PubID], 4, 4
Column2=[Name], 12, 50
Column3=[Company Name], 12, 255
Column4=[Address], 12, 50
Column5=[City], 12, 20
Column6=[State], 12, 10
Column7=[Zip], 12, 15
Column8=[Telephone], 12, 15
Column9=[Fax], 12, 15
Column10=[Comments], -1, 0

