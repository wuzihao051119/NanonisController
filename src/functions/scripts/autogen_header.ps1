foreach ($fileName in Get-Content -Path "headerName.txt") {
    $upperFileName = $fileName.ToUpper() + "_H"
    $headerFileName = "../" + $fileName.ToLower() + ".h"
    $srcFileName = "../" + $fileName.ToLower() + ".cpp"
    $includeFileName = $fileName.ToLower() + ".h"
    $content = 
@"
#ifndef $upperFileName
#define $upperFileName

#include "../macro.h"

class $fileName
{
public:
    Add${FileName}Functions;
};

#endif // ${upperFileName}
"@
    $includeContent = @"
#include "$($includeFileName)"
"@
    # Write-Host -Value $content
    Set-Content -Path $headerFileName -Value $content
    Set-Content -Path $srcFileName -Value $includeContent
}
