/* Copyright (c) 2014 K. Ernest 'iFire' Lee

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.  */


// Add a class to handle the Solution file locally
// instead of relying on FDesktopPlatformModule.

#include "QtCreatorSourceCodeAccessPrivatePCH.h"
#include "QtCreatorSourceCodeAccessor.h"
#include "DesktopPlatformModule.h"

#define LOCTEXT_NAMESPACE "QtCreatorSourceCodeAccessor"
bool FQtCreatorSourceCodeAccessor::CanAccessSourceCode() const
{
  return FPaths::FileExists(TEXT("/usr/bin/clang"));
}

FName FQtCreatorSourceCodeAccessor::GetFName() const
{
  return FName("QtCreatorSourceCodeAccessor");
}

FText FQtCreatorSourceCodeAccessor::GetNameText() const 
{
  return LOCTEXT("QtCreatorDisplayName", "Qt Creator");
}

FText FQtCreatorSourceCodeAccessor::GetDescriptionText() const
{
  return LOCTEXT("QtCreatorDisplayDesc", "Open source code files with Qt Creator");
}

bool FQtCreatorSourceCodeAccessor::OpenSolution()
{
  FString FullPath;
  if(FDesktopPlatformModule::Get()->GetSolutionPath(FullPath)){
    if ( FPaths::FileExists( FullPath ) )
    {
      FString Editor = FString(TEXT("/usr/bin/qtcreator"));
      FString Args = FString(TEXT("-client "));
      Args.Append(FullPath);
      if(FLinuxPlatformProcess::CreateProc(*Editor,
                                           *Args,
                                           true,
                                           true,
                                           false,
                                           nullptr,
                                           0,
                                           nullptr,
                                           nullptr).IsValid())
        return true;
    }
  }
  return false;
}

bool FQtCreatorSourceCodeAccessor::OpenFileAtLine(const FString& FullPath, int32 LineNumber, int32 ColumnNumber)
{
    FString Editor = FString(TEXT("/usr/bin/qtcreator"));
    FString Args = FString(TEXT("-client "));                                                           
    Args.Append(FullPath).Append(TEXT(":")).Append(FString::FromInt(LineNumber));
    if (FLinuxPlatformProcess::CreateProc(*Editor,
                                          *Args,
                                          true,
                                          true,
                                          false,
                                          nullptr,
                                          0,
                                          nullptr,
                                          nullptr).IsValid())
      return true;
  return false;
}

bool FQtCreatorSourceCodeAccessor::OpenSourceFiles(const TArray<FString>& AbsoluteSourcePaths) 
{
  for ( const FString& SourcePath : AbsoluteSourcePaths ) 
  {
    FString Editor = FString(TEXT("/usr/bin/qtcreator"));
    FString Args = FString(TEXT("-client "));
    Args.Append(SourcePath);
    if(!(FLinuxPlatformProcess::CreateProc(*Editor,
                                           *Args,
                                           true,
                                           true,
                                           false,
                                           nullptr,
                                           0,
                                           nullptr,
                                           nullptr).IsValid())) 
        return false;
  }  
  return true;
}

bool FQtCreatorSourceCodeAccessor::SaveAllOpenDocuments() const
{
  return false;
}

void FQtCreatorSourceCodeAccessor::Tick(const float DeltaTime) 
{

}

#undef LOCTEXT_NAMESPACE
