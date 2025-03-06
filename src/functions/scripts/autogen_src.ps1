foreach ($fullName in Get-Content -Path "srcName.txt") {
    $className = $fullName.Split("::")[0]
    $methodName = $fullName.Split("::")[1]
    $srcFileName = "../" + $className.ToLower() + ".cpp"

    $methodContent = @"

std::string &$className::$methodName(std::vector<std::string> &args) {
    std::string ret;
    return ret;
}
"@
    Add-Content -Path $srcFileName -Value $methodContent
}
