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

#include "SensibleEditorSourceCodeAccessPrivatePCH.h"
#include "SensibleEditorSourceCodeAccessor.h"

#define LOCTEXT_NAMESPACE "SensibleEditorSourceCodeAccessor"

bool FXCodeSourceCodeAccessor::CanAccessSourceCode() const
{
  return FPaths::FileExists(TEXT("/usr/bin/clang"));
}

FName FXCodeSourceCodeAccessor::GetFName() const
{
  return FName("SensibleEditorSourceCodeAccessor");
}

FText FXCodeSourceCodeAccessor::GetNameText() const 
{
  return LOCTEXT("SensibleEditorDisplayName", "Sensible Editor");
}

FText FXCodeSourceCodeAccessor::GetDescriptionText() const
{
  return LOCTEXT("SensibleEditorDisplayDesc", "Open source code files with Sensible Editor");
}

bool FXCodeSourceCodeAccessor::OpenSolution()
{
  const FString FullPath = IFileManager::Get().ConvertToAbsolutePathForExternalAppForRead( *FModuleManager::Get().GetSolutionFilepath() );
  if ( FPaths::FileExists( FullPath ) )
  {
    FPlatformProcess::LaunchFileInDefaultExternalApplication( *FullPath );
    return true;
  }
  return false;
}

bool FXCodeSourceCodeAccessor::OpenFileAtLine(const FString& FullPath, int32 LineNumber, int32 ColumnNumber)
{
  bool ExecutionSucceeded = false;
  if(ExecutionSucceeded == false)
  {
    FPlatformProcess::LaunchFileInDefaultExternalApplication(*FullPath);
  }
  
  return true;
}

bool FXCodeSourceCodeAccessor::OpenSourceFiles(const TArray<FString>& AbsoluteSourcePaths) 
{
  for ( const FString& SourcePath : AbsoluteSourcePaths ) 
  {
    FPlatformProcess::LaunchFileInDefaultExternalApplication(*SourcePath);
  }
  return true;
}

bool FXCodeSourceCodeAccessor::SaveAllOpenDocuments() const
{
  return false;
}

void FXCodeSourceCodeAccessor::Tick(const float DeltaTime) 
{

}

#undef LOCTEXT_NAMESPACE
